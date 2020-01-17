#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

run_ICC_parser () {
ICC_DIR=${1}
cd "${SCRIPTS}/../tools/ICCOptReportParser/"
if [ -d "${THIS}/icc_parser.out" ]; then
  rm "${THIS}/icc_parser.out"
fi
g++-7 icc_parser.h icc_parser.cpp -o ${THIS}/icc_parser.out
chmod +x "${THIS}/icc_parser.out"
cd ${THIS}

ICC_PARSER=${THIS}/icc_parser.out

cd "${SCRIPTS}/../benchmarks/${ICC_DIR}"
FILES_DIR=$(pwd)
cd ${THIS}

FILES=$(find ${FILES_DIR} -name "*.optrpt" | sort)

for f in ${FILES}; do

  cd "${SCRIPTS}/../benchmarks/${ICC_DIR}"
  original_str=$(pwd)
  cd ${SCRIPTS}
  original_str=${original_str//\//\\\/}
  filename=${f/$FILES_DIR/\/root}

  echo "${f}"
  ${ICC_PARSER} "${f}"

  filename="${f//*\/}"
  filename="${filename/.optrpt/}"
  filedir="${f%/*}"

  if [ -f "${f}.json"  ]; then
    mv "${f}.json" "${filedir}/${filename}.json"
  fi

  if [ -f "${filedir}/${filename}.json" ]; then
    sed -i "s/${original_str}/./g" "${filedir}/${filename}.json"
  fi
done
}

setEnvironment () {
  THIS=$(pwd)
  cd ../
  SCRIPTS=$(pwd)
  cd "${THIS}"
  COMPILER="icc -w -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
  cd "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c"
  CLINK=${COMPILER} CC=${COMPILER} make veryclean
  mkdir  "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c/bin"
  CLINK=${COMPILER} CC=${COMPILER} make suite
  rm -r "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c/bin"
  cd "${THIS}"
  cd "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c"
  CLINK=${COMPILER} CC=${COMPILER} make veryclean
  mkdir "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c/bin"
  CLINK=${COMPILER} CC=${COMPILER} make suite
  rm -r "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c/bin"
  
  if [ -f "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c/bin/ipo_out.optrpt" ]; then
    rm "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c/bin/ipo_out.optrpt"
  fi
  if [ -f "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c/bin/ipo_out.optrpt" ]; then
    rm "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c/bin/ipo_out.optrpt"
  fi
  cd "${THIS}"
}

cleanEnvironment () {
  COMPILER="icc -w -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
  cd "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c"
  CLINK=${COMPILER} CC=${COMPILER} make veryclean
  cd "${THIS}"
  cd "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c"
  CLINK=${COMPILER} CC=${COMPILER} make veryclean
  if [ -f "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c/bin/ipo_out.optrpt" ]; then
    rm "${SCRIPTS}/../benchmarks/ICC_Full/NPB3.0-omp-c/bin/ipo_out.optrpt"
  fi
  if [ -f "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c/bin/ipo_out.optrpt" ]; then
    rm "${SCRIPTS}/../benchmarks/ICC_Cost/NPB3.0-omp-c/bin/ipo_out.optrpt"
  fi
  cd "${THIS}"
  rm "${ICC_PARSER}"
}


setEnvironment

run_ICC_parser "ICC_Cost"
run_ICC_parser "ICC_Full"
run_ICC_parser "ICC_Simd"

cleanEnvironment
