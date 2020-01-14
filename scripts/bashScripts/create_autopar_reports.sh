#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# This script can run autopar in all benchmarks that do not need an input.

if [ "$#" -ne 0 ]; then
  echo "$# Illegal number of parameters"
  exit 1;
fi

# Step 1 : Create a copy of the benchmarks to run rose
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
REFERENCE_DIRECTORY="sequential"
cd ${THIS}

cd ${SCRIPTS}/../benchmarks/${REFERENCE_DIRECTORY}
INPUT_DIR=$(pwd)
cd ${THIS}

if [ -d "${SCRIPTS}/../benchmarks/Autopar" ]; then
  rm -r "${SCRIPTS}/../benchmarks/Autopar"
fi
cp -r "${INPUT_DIR}" "${SCRIPTS}/../benchmarks/Autopar"

cd "${SCRIPTS}/../benchmarks/Autopar"
OUTPUT_DIR=$(pwd)
cd ${SCRIPTS}

if [ -f "${THIS}/logs/autopar.log" ]; then
  rm ${THIS}/logs/autopar.log
fi

COMPILER="icc -qopenmp -w"
if [ -d "${SCRIPTS}/../benchmarks/Autopar/NPB3.0-omp-c/" ]; then
  mkdir "${SCRIPTS}/../benchmarks/Autopar/NPB3.0-omp-c/bin"
  cd "${SCRIPTS}/../benchmarks/Autopar/NPB3.0-omp-c/"
  CLINK=${COMPILER} CC=${COMPILER} make suite
  rm -r "${SCRIPTS}/../benchmarks/Autopar/NPB3.0-omp-c/bin"
fi
cd "${THIS}"

cd $OUTPUT_DIR
BENCHS=$(find . -name "*.c" | sort)
BENCHSCPP=$(find . -name "*.cpp" | sort)
cd ${SCRIPTS}

# Step 2 : Find all files with main function, and compile them
echo "-----------------------------------------------"
echo "---------------- AUTOPAR START ----------------"
echo "-----------------------------------------------"
cd ${OUTPUT_DIR}
if [ "$(docker ps -q -f name=autoparCont)" ]; then
  docker stop autoparCont
  docker container rm autoparCont
fi

docker run -t -d --name autoparCont -v $(pwd):/root gleisonsdm/rose:latest

for f in $BENCHS; do
  echo "Running AutoPar to : $f"
  filename="${f//*\/}"
  filedir="${f%/*}"
  echo "Benchmark : $f" >> ${THIS}/logs/autopar.log
  (docker exec -it autoparCont timeout 600s autoPar $EDGFLAGS -w -rose:verbose 0 -c $f) &>> ${THIS}/logs/autopar.log
  echo "${filedir}/${filename}"
  # This line removes the sequential code:
  rm "${filedir}/${filename}"
  if [ -f "rose_${filename}" ]; then
    cp "rose_${filename}" "${filedir}/${filename}"
    rm "rose_${filename}"
  fi
  if [ -f "${filename/.c/.o}" ]; then
    rm "${filename/.c/.o}"
  fi
done

for f in $BENCHSCPP; do
  if echo "${f}" | grep -q "rodinia_3.1/data/"; then
    continue;
  fi
  echo "Running AutoPar to : $f"
  filename="${f//*\/}"
  filedir="${f%/*}"
  echo "Benchmark : $f" >> ${THIS}/logs/autopar.log
  (docker exec -it autoparCont timeout 600s autoPar $EDGFLAGS -w -rose:verbose 0 -c $f) &>> ${THIS}/logs/autopar.log
  echo "${filedir}/${filename}"
  # This line removes the sequential code:
  rm "${filedir}/${filename}"
  if [ -f "rose_${filename}" ]; then
    cp "rose_${filename}" "${filedir}/${filename}"
    rm "rose_${filename}"
  fi
  if [ -f "${filename/.cpp/.o}" ]; then
    rm "${filename/.cpp/.o}"
  fi
done

COMPILER="icc -qopenmp -w"
if [ -d "${SCRIPTS}/../benchmarks/Autopar/NPB3.0-omp-c" ]; then
  cd "${SCRIPTS}/../benchmarks/Autopar/NPB3.0-omp-c/"
  CLINK=${COMPILER} CC=${COMPILER} make clean
fi
cd "${THIS}"

docker stop autoparCont
docker container rm autoparCont

cd "${THIS}"

