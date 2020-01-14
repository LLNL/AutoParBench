#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# This script can cetus in all benchmarks that do not need an input.

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

cd "${SCRIPTS}/../benchmarks/${REFERENCE_DIRECTORY}"
INPUT_DIR=$(pwd)
cd ${THIS}

if [ -d "${SCRIPTS}/../benchmarks/Cetus" ]; then
  rm -r "${SCRIPTS}/../benchmarks/Cetus"
fi
cp -r "${INPUT_DIR}" "${SCRIPTS}/../benchmarks/Cetus"

cd "${SCRIPTS}/../benchmarks/Cetus"
OUTPUT_DIR=$(pwd)
cd ${SCRIPTS}

if [ -f "${THIS}/logs/cetus.log" ]; then
  rm ${THIS}/logs/cetus.log
fi

COMPILER="icc -qopenmp -w"
cd "${SCRIPTS}/../benchmarks/Cetus/NPB3.0-omp-c/"
mkdir "${SCRIPTS}/../benchmarks/Cetus/NPB3.0-omp-c/bin"
CLINK=${COMPILER} CC=${COMPILER} make suite
rm -r "${SCRIPTS}/../benchmarks/Cetus/NPB3.0-omp-c/bin"
cd "${SCRIPTS}"

cd ${OUTPUT_DIR}
BENCHS=$(find . -name "*.c" | sort)
BENCHSCPP=$(find . -name "*.cpp" | sort)
BENCHSJSON=$(find . -name "*.json" | sort)
cd ${THIS}

# Step 2 : Find all files with main function, and compile them
echo "-----------------------------------------------"
echo "----------------- CETUS START -----------------"
echo "-----------------------------------------------"
cd ${OUTPUT_DIR}
if [ "$(docker ps -q -f name=cetusCont)" ]; then
  docker stop cetusCont
  docker container rm cetusCont
fi

for f in $BENCHS; do
  echo "Running Cetus to : $f"
  filename="${f//*\/}"
  filedir="${f%/*}"
  cd "${OUTPUT_DIR}/${filedir}"
  docker run -t -d --name cetusCont -v $(pwd):/root gleisonsdm/cetus:latest
  echo "/usr/src/cetus-1.4.4/bin/cetus -parallelize-loops=2 -ompGen=2 -profitable-omp=0 $f" &>> ${THIS}/logs/cetus.log
  #  (docker exec -it cetusCont /usr/src/cetus-1.4.4/bin/cetus -profile-loop=1 -parallelize-loops=2 -ompGen=2 -private -profitable-omp=0 -c $f) &>> $SCRIPTS/cetus.log
  (docker exec -it cetusCont java cetus.exec.Driver -parallelize-loops=2 -ompGen=2 -profitable-omp=0 $filename) &>> ${THIS}/logs/cetus.log

  docker stop cetusCont
  docker container rm cetusCont
  # This line removes the sequential code
  rm "${filename}"
  if [ -f "cetus_output/${filename}" ]; then
    mv "cetus_output/${filename}" "${filename}"
    rm -r "cetus_output/"
  fi
  echo "${filedir}/${filename}"
  cd "${OUTPUT_DIR}"
done

COMPILER="icc -qopenmp -w"
if [ -d "${SCRIPTS}/../benchmarks/Cetus/NPB3.0-omp-c/" ]; then
  cd "${SCRIPTS}/../benchmarks/Cetus/NPB3.0-omp-c/"
  CLINK=${COMPILER} CC=${COMPILER} make clean
fi 

cd "${OUTPUT_DIR}"

for f in $BENCHSJSON; do
  filename="${f//*\/}"
  filedir="${f%/*}"
 rm "${filedir}/${filename}"
done

cd $SCRIPTS

