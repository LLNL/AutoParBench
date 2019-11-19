#!/bin/bash
set -e 

# map directories
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd "${THIS}"

# remove the output directory, if it exists
if [ -d "${SCRIPTS}/../benchmarks/reference_cpu_threading" ]; then
  rm -r "${SCRIPTS}/../benchmarks/reference_cpu_threading"
fi
mkdir "${SCRIPTS}/../benchmarks/reference_cpu_threading"

# Map directoires
cd "${SCRIPTS}/../benchmarks/reference_cpu_threading"
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
  cp "${csource}" "${csource/sequential/reference_cpu_threading}"
done
for csource in $(find "${CPU_sequential_DIR}" -name "*.cpp" ); do
  cp "${csource}" "${csource/sequential/reference_cpu_threading}"
done
for csource in $(find "${CPU_sequential_DIR}" -name "*.h" ); do
  cp "${csource}" "${csource/sequential/reference_cpu_threading}"
done
for csource in $(find "${CPU_sequential_DIR}" -name "*.hpp" ); do
  cp "${csource}" "${csource/sequential/reference_cpu_threading}"
done

if [ -f "${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.out" ]; then
  rm "${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.out"
fi

# compile the parser to join JSON files
g++-8 ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.h ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.cpp -o ${THIS}/equivalence_checker.out
chmod +x ${THIS}/equivalence_checker.out

# Join the manual JSON file and ICC without threshold to find all parallelizable but not profitable loops.
for json in $(find "${BASELINEDIR}" -name "*.json" | sort); do
  echo ""
  echo "./equivalence_checker.out -join ${json/reference_cpu_threading/original} ${json/reference_cpu_threading/ICC_Full} ${json}"
  if [ -f "${json/reference_cpu_threading/ICC_Full}" ]; then
    ./equivalence_checker.out -join "${json/reference_cpu_threading/original}" "${json/reference_cpu_threading/ICC_Full}" "${json}"
  else
    ./equivalence_checker.out -join "${json/reference_cpu_threading/original}" "${jsonjson/reference_cpu_threading/original}" "${json}"
  fi
done

# remove temporary files
#find "${BASELINEDIR}" -type f ! \( -name '*.json' \) -delete
rm ${THIS}/equivalence_checker.out
