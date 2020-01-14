#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# This script can run pragma finder in all benchmarks that do not need an input.

# Step 1 : Set the directories to run OpenMP Extractor.
set_environment() {
  THIS=$(pwd)
  cd ../
  SCRIPTS=$(pwd)
  cd "${THIS}"

  CLANG="/usr/src/llvm-build/bin/clang"
  CLANGPP="/usr/src/llvm-build/bin/clang++"
  PRAGFIND="/usr/src/OMP_Extractor/lib/ompextractor/libCLANGOMPExtractor.so"
  FLAGS=" -Xclang -load -Xclang $PRAGFIND -Xclang -add-plugin -Xclang -extract-omp -fopenmp -g -O0 -c -fsyntax-only "
  if [ -f "${THIS}/logs/ompextractor.log" ]; then
    rm "${THIS}/logs/ompextractor.log"
  fi
}

# Step 1 : Create a link to the target directory.
map_directory () {
  echo "${1}" &> ${THIS}/logs/ompextractor.log
  cd "${SCRIPTS}/../benchmarks/${1}"
  INPUT_DIR=$(pwd)
  cd "${THIS}"
}

# Step 2 : Remove all json files.
remove_jsons() {
  cd "${SCRIPTS}/../benchmarks/"
  BENCHS_JSON=$(find ${1} -name "*.json" | sort)
  for f in $BENCHS_JSON; do
    echo "Removing $f"
    rm "$f"
  done
  cd "${THIS}"
}

# Step 3 : Find source files to run our scripts.
map_files() {
  cd "${SCRIPTS}/../benchmarks/${1}"
  BENCHS=$(find . -name "*.c" | sort)
  BENCHSCPP=$(find . -name "*.cpp" | sort)
  cd "${THIS}"
}

# Step 4 : Run OpenMP Extractor in all banchmarks avaialble.
run_OMP() {
echo "-----------------------------------------------"
echo "------------- OMP Extractor START -------------"
echo "-----------------------------------------------"
cd "${SCRIPTS}/../benchmarks/${1}"
sudo docker run -t -d --name ompExtractorCont -v $(pwd):/root gleisonsdm/ompextractor:latest
for f in $BENCHS; do
  filename="${f//*\/}"
  filedir="${f%/*}"

  echo "Writting Json to : ${filename}"

  (sudo docker exec -it ompExtractorCont $CLANG $FLAGS "${filedir}/${filename}") &>> ${THIS}/logs/ompextractor.log
done

for f in $BENCHSCPP; do
  filename="${f//*\/}"
  filedir="${f%/*}"

  echo "Writting Json to : ${filename}"

  (sudo docker exec -it ompExtractorCont $CLANGPP $FLAGS "${filedir}/${filename}") &>> ${THIS}/logs/ompextractor.log
done

sudo docker stop ompExtractorCont
sudo docker container rm ompExtractorCont
cd "${THIS}"
}

# Step 6 : Update all json files.
update_jsons() {
if [ $# -eq 2 ]; then
  cd "${SCRIPTS}/../benchmarks/"
  BENCHS_JSON=$(find ${1} -name "*.json" | sort)
  for f in $BENCHS_JSON; do
    echo "Updating $f"
    sed -i "s/${2}//g" "${f}"
    if [ "$?" != "0" ]; then
      exit 1;
    fi
    grep "${2}" "${f}"
  done
  cd "${THIS}"
fi
}

# Step 7 : Produce jsons for each ".c" file in a directory.
analyze_directory() {
set_environment
map_directory ${1}
remove_jsons ${1}
map_files ${1}
run_OMP ${1}
update_jsons ${1} ${2}
}

analyze_directory original
analyze_directory reference_cpu_threading
analyze_directory Cetus
analyze_directory reference_gpu_target
analyze_directory Dawncc
analyze_directory reference_cpu_simd
analyze_directory Autopar
