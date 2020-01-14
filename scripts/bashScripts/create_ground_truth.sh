#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set_environment() {
# map directories
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd "${THIS}"

# remove the output directory, if it exists
if [ -d "${SCRIPTS}/../benchmarks/baseline" ]; then
  rm -r "${SCRIPTS}/../benchmarks/baseline"
fi
mkdir "${SCRIPTS}/../benchmarks/baseline"

# Map directoires
cd "${SCRIPTS}/../benchmarks/baseline"
BASELINEDIR=$(pwd)
cd "${THIS}"

cd "${SCRIPTS}/../benchmarks/ICC_Full"
ICC_NOCOST_DIR=$(pwd)
cd "${THIS}"

cd "${SCRIPTS}/../benchmarks/original"
CPU_reference_DIR=$(pwd)
cd "${THIS}"

cd "${SCRIPTS}/../benchmarks/sequential"
CPU_sequential_DIR=$(pwd)
cd "${THIS}"

if [ -d "${BASELINEDIR}" ]; then
  rm -r "${BASELINEDIR}"
fi
cp -r "${CPU_reference_DIR}" "${BASELINEDIR}"

for csource in $(find "${CPU_sequential_DIR}" -name "*.c" ); do
  cp "${csource}" "${csource/sequential/baseline}"
done
for csource in $(find "${CPU_sequential_DIR}" -name "*.cpp" ); do
  cp "${csource}" "${csource/sequential/baseline}"
done
for csource in $(find "${CPU_sequential_DIR}" -name "*.h" ); do
  cp "${csource}" "${csource/sequential/baseline}"
done
for csource in $(find "${CPU_sequential_DIR}" -name "*.hpp" ); do
  cp "${csource}" "${csource/sequential/baseline}"
done
}

generate_ground_truth_jsons() {
if [ -f "${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.out" ]; then
  rm "${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.out"
fi

# compile the parser to join JSON files
g++-8 ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.h ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.cpp -o ${THIS}/equivalence_checker.out
chmod +x ${THIS}/equivalence_checker.out

# Join the manual JSON file and ICC without threshold to find all parallelizable but not profitable loops.
for json in $(find "${BASELINEDIR}" -name "*.json" | sort); do
   echo "Creating ${json}"
   if [ -f "${json/baseline/ICC_Full}" ]; then
    ./equivalence_checker.out -join "${json/baseline/original}" "${json/baseline/ICC_Full}" "${json}"
  else
    ./equivalence_checker.out -join "${json/baseline/original}" "${json/baseline/original}" "${json}"
  fi
done
}

run_OMP() {
LLVM_OUTPUT_DIR="/usr/src/llvm-build"
CLANG="${LLVM_OUTPUT_DIR}/bin/clang"
CLANGPP="${LLVM_OUTPUT_DIR}/bin/clang++"
FLAGS="-g -c -Xclang -load -Xclang /usr/src/OMP_Writer/lib/ompwriter/libCLANGOMPWriter.so -Xclang -plugin -Xclang -write-omp"
POSFLAGS="-fopenmp -O0"

cd "${BASELINEDIR}"
BENCHS=$(find . -name "*.c" | sort)
BENCHSCPP=$(find . -name "*.cpp" | sort)
cd "${THIS}"

if [ -f "${THIS}/logs/ompwriter.log" ]; then
  rm "${THIS}/logs/ompwriter.log"
fi

if [ "$(docker ps -q -f name=ompWriterCont)" ]; then
  sudo docker stop ompWriterCont
  sudo docker container rm ompWriterCont
fi

echo "-----------------------------------------------"
echo "--------------- OMP Writer START --------------"
echo "-----------------------------------------------"
cd "${BASELINEDIR}"
sudo docker run -t -d --name ompWriterCont -v $(pwd):/root gleisonsdm/ompwriter:latest
for f in $BENCHS; do
  filename="${f//*\/}"
  filedir="${f%/*}"

  echo "Writting Json to : ${filename}"

  FLAGS_WJ="${FLAGS} -Xclang -plugin-arg--write-omp -Xclang -write-json=${filename}.json"
  echo "$CLANG $FLAGS_WJ "${filedir}/${filename}" $POSFLAGS"
  (sudo docker exec -it ompWriterCont $CLANG $FLAGS_WJ "${filedir}/${filename}" $POSFLAGS) &>> ${THIS}/logs/ompwriter.log
done

for f in $BENCHSCPP; do
  filename="${f//*\/}"
  filedir="${f%/*}"

  echo "Writting Json to : ${filename}"

  FLAGS_WJ="${FLAGS} -Xclang -plugin-arg--write-omp -Xclang -write-json=${filedir}/${filename}.json"
  (sudo docker exec -it ompWriterCont $CLANGPP $FLAGS_WJ "${filedir}/${filename}" $POSFLAGS) &>> ${THIS}/logs/ompwriter.log
done

sudo docker stop ompWriterCont
sudo docker container rm ompWriterCont
cd "${THIS}"
}

clean_environment() {
# remove temporary files
#find "${BASELINEDIR}" -type f ! \( -name '*.json' \) -delete
find "${BASELINEDIR}" -type f \( -name '*.optrpt' \) -delete
if [ -f "${THIS}/equivalence_checker.out" ]; then
  rm ${THIS}/equivalence_checker.out
fi

}

set_environment
generate_ground_truth_jsons
run_OMP
clean_environment


