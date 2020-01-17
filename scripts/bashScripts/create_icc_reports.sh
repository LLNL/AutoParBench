#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set -e

# This script can run autopar in all benchmarks that do not need an input.

run_icc() {
export PATH="/opt/intel/compilers_and_libraries_2019.4.243/linux/bin/intel64/:$PATH"
REFERENCE_DIRECTORY=${1}
ICC_DIR=${2}
FLAGS=${3}

# Step 1 : Create a copy of the benchmarks to run rose
THIS=$(pwd)
cd ${THIS}/../
SCRIPTS=$(pwd)
cd bashScripts/

cd ${SCRIPTS}/../benchmarks/${REFERENCE_DIRECTORY}
INPUT_DIR=$(pwd)
cd ${THIS}

if [ -d "${SCRIPTS}/../benchmarks/${ICC_DIR}" ]; then
  rm -r "${SCRIPTS}/../benchmarks/${ICC_DIR}"
fi
cp -r "${INPUT_DIR}" "${SCRIPTS}/../benchmarks/${ICC_DIR}"

cd "${SCRIPTS}/../benchmarks/${ICC_DIR}"
OUTPUT_DIR=$(pwd)
cd ${SCRIPTS}

COMPILER="icc -w -parallel"
if [ -d "${OUTPUT_DIR}/NPB3.0-omp-c/" ]; then
  cd "${OUTPUT_DIR}/NPB3.0-omp-c/"
  if [ -d "${OUTPUT_DIR}/NPB3.0-omp-c/bin" ]; then
    rm -r "${OUTPUT_DIR}/NPB3.0-omp-c/bin"
  fi
  mkdir "${OUTPUT_DIR}/NPB3.0-omp-c/bin"
  CLINK=${COMPILER} CC=${COMPILER} make suite
  rm -r "${OUTPUT_DIR}/NPB3.0-omp-c/bin"
cd "${SCRIPTS}"
fi

if [ -f "${THIS}/logs/icc.log" ]; then
  rm "${THIS}/logs/icc.log"
fi
echo "" &> ${THIS}/logs/icc.log

BENCHS=$(find $OUTPUT_DIR -name "*.c" | sort)
BENCHSCPP=$(find $OUTPUT_DIR -name "*.cpp" | sort)

# Step 2 : Find all files with main function, and compile them
echo "-----------------------------------------------"
echo "------------------ ICC START ------------------"
echo "-----------------------------------------------"
cd ${OUTPUT_DIR}
#module load gcc/8.1.0
g++-8 ${SCRIPTS}/../tools/PragmaRemover/pragmaRemover.cpp -o pragmaRemover.out

#module load intel/19.0.4
chmod +x pragmaRemover.out
for f in $BENCHS; do
  echo "Running ICC to : $f"
  ./pragmaRemover.out $f
  filename="${f//*\/}"
  filedir="${f%/*}"
  bin_filename=${filename/.c/.o}
  report=${filename/.c/.optrpt}

  (icc -c ${FLAGS} $f -o $filedir/$bin_filename) &>> ${THIS}/logs/icc.log

  mv "$filedir/${filename/.c/.optrpt}" "$filedir/${filename/.c/.c.optrpt}"
  if [ -f "${filedir}/${bin_filename}" ]; then
    rm "${filedir}/${bin_filename}"
  fi
  if [ -f "${filedir}/${filename}.json" ]; then
    rm "${filedir}/${filename}.json"
  fi

done
for f in $BENCHSCPP; do
  if echo "${f}" | grep -q "rodinia_3.1/data/"; then
    continue;
  fi
  echo "Running ICC to : $f"
  ./pragmaRemover.out $f
  filename="${f//*\/}"
  filedir="${f%/*}"
  bin_filename=${filename/.cpp/.o}

  (icc -c ${FLAGS} $f -o $filedir/$bin_filename) &>> ${THIS}/logs/icc.log

  mv "$filedir/${filename/.cpp/.optrpt}" "$filedir/${filename/.cpp/.cpp.optrpt}"
  if [ -f "${filedir}/${bin_filename}" ]; then
    rm "${filedir}/${bin_filename}"
  fi
  if [ -f "${filedir}/${filename}.json" ]; then
    rm "${filedir}/${filename}.json"
  fi
done
rm pragmaRemover.out
cd $SCRIPTS

COMPILER="icc -w -parallel"
if [ -d "${OUTPUT_DIR}/NPB3.0-omp-c/" ]; then
  cd "${OUTPUT_DIR}/NPB3.0-omp-c/"
  CLINK=${COMPILER} CC=${COMPILER} make clean
fi
cd "${THIS}"
}

run_icc "sequential" "ICC_Full" " -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5 "
run_icc "sequential" "ICC_Cost" " -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5 "
run_icc "reference_cpu_simd" "ICC_Simd" " -par-threshold0 -vec-threshold0 -fno-inline -parallel -qopt-report-phase=all -qopt-report=5 "


