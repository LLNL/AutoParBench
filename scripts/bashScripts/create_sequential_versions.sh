#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set -e 

# Step 1 : Create a copy of the benchmarks and remove OpenMP Directives
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd bashScripts
BENCHMARKS="${SCRIPTS}/../benchmarks/"

if [ -d "${BENCHMARKS}/sequential" ]; then
  rm -r "${BENCHMARKS}/sequential"
fi

echo "Copying benchmarks"
cp -r "${BENCHMARKS}/reference_cpu_threading" "${BENCHMARKS}/sequential"

echo "Removing pragmas"
cd ${BENCHMARKS}/sequential
OUTPUT_DIR=$(pwd)
cd ${SCRIPTS}

# Step 2 : Find all files with source code
cd $OUTPUT_DIR
BENCHS=$(find . -name "*.c" | sort)
BENCHS_H=$(find . -name "*.h" | sort)
BENCHS_CPP=$(find . -name "*.cpp" | sort)
BENCHS_OPTRPT=$(find . -name "*.optrpt" | sort)
BENCHS_JSON=$(find . -name "*.json" | sort)
cd ${THIS}

# Step 3 : Remove all OpenMP directives
g++ ${SCRIPTS}/../tools/PragmaRemover/pragmaRemover.cpp -o pragmaRemover.out
chmod +x pragmaRemover.out

# Step 4 : We do not remove OpenMP system functions. So, to avoid problems, we should use -qopenmp
for f in $BENCHS; do
  echo "Removing pragmas of : $f"
  ./pragmaRemover.out "${OUTPUT_DIR}/$f"
done
for f in $BENCHS_H; do
  echo "Removing pragmas of : $f"
  ./pragmaRemover.out "${OUTPUT_DIR}/$f"
done
for f in $BENCHS_CPP; do
  echo "Removing pragmas of : $f"
  ./pragmaRemover.out "${OUTPUT_DIR}/$f"
done
for f in $BENCHS_OPTRPT; do
  echo "Removing file : $f"
  rm "${OUTPUT_DIR}/$f"
done
for f in $BENCHS_JSON; do
  echo "Removing file : $f"
  rm "${OUTPUT_DIR}/$f"
done
rm pragmaRemover.out

