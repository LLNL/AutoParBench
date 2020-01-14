#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set -e 

# This script can run dawncc in all benchmarks that do not need an input.

# Step 1 : Create a copy of the benchmarks to run dawncc
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
REFERENCE_DIRECTORY="reference_gpu_target"
cd ${THIS}

cd ${SCRIPTS}/../benchmarks/${REFERENCE_DIRECTORY}
INPUT_DIR=$(pwd)
cd ${SCRIPTS}

if [ -d "${SCRIPTS}/../benchmarks/Dawncc" ]; then
rm -r "${SCRIPTS}/../benchmarks/Dawncc"
fi
cp -r "${INPUT_DIR}" ${SCRIPTS}/../benchmarks/Dawncc

cd "${SCRIPTS}/../benchmarks/Dawncc"
OUTPUT_DIR=$(pwd)
cd ${SCRIPTS}

if [ -f "$SCRIPTS/logs/dawncc.log" ]; then
  rm "$SCRIPTS/logs/dawncc.log"
fi

cd $OUTPUT_DIR
BENCHS=$(find . -name "*.c" | sort)
cd ${SCRIPTS}

# Step 2 : Find all files with main function, and compile them
echo "-----------------------------------------------"
echo "----------------- DAWNCC START ----------------"
echo "-----------------------------------------------"
cd ${OUTPUT_DIR}
g++-7 ${SCRIPTS}/../tools/PragmaRemover/pragmaRemover.cpp -o pragmaRemover.out
chmod +x pragmaRemover.out
sudo docker run -t -d --name dawnccCont -v $(pwd):/root gleisonsdm/dawncc:latest
for f in $BENCHS; do
  echo "Running DawnCC to : $f"

  ./pragmaRemover.out "$OUTPUT_DIR/$f"

  filename="${f//*\/}"
  filedir="${f%/*}"

  sudo docker exec -it dawnccCont /usr/src/llvm-build/bin/clang-format -style="{BasedOnStyle: llvm, IndentWidth: 2}" -i $f
  
  sudo docker exec -it dawnccCont /usr/src/llvm-build/bin/clang -Xclang -load -Xclang /usr/src/llvm-build/lib/scope-finder.so -Xclang -add-plugin -Xclang -find-scope -g -O0 -c -fsyntax-only $f

  sudo docker exec -it dawnccCont /usr/src/llvm-build/bin/clang -g -S -emit-llvm $f -o result.bc

  sudo docker exec -it dawnccCont /usr/src/llvm-build/bin/opt -load /usr/src/DawnCC/lib/PtrRangeAnalysis/libLLVMPtrRangeAnalysis.so -load /usr/src/DawnCC/lib/AliasInstrumentation/libLLVMAliasInstrumentation.so -load /usr/src/DawnCC/lib/DepBasedParallelLoopAnalysis/libParallelLoopAnalysis.so -load /usr/src/DawnCC/lib/CanParallelize/libCanParallelize.so -mem2reg -tbaa -scoped-noalias -basicaa -functionattrs -gvn -loop-rotate -instcombine -licm -ptr-ra -basicaa -scoped-noalias -alias-instrumentation -region-alias-checks -can-parallelize -S result.bc &> /dev/null

  sudo docker exec -it dawnccCont /usr/src/llvm-build/bin/opt -load /usr/src/DawnCC/lib/ScopeTree/libLLVMScopeTree.so -load /usr/src/DawnCC/lib/ArrayInference/libLLVMArrayInference.so -annotateParallel -S result.bc -o result2.bc

  sudo docker exec -it dawnccCont /usr/src/llvm-build/bin/opt -S -mem2reg -instnamer -loop-rotate -load /usr/src/DawnCC/lib/ScopeTree/libLLVMScopeTree.so -load /usr/src/DawnCC/lib/ArrayInference/libLLVMArrayInference.so -writeInFile -stats -Emit-GPU=false -Emit-Parallel=true -Emit-OMP=1 -Restrictifier=true -Memory-Coalescing=true -Ptr-licm=true -Ptr-region=true -Run-Mode=false result2.bc -o result3.bc &>> ${THIS}/logs/dawncc.log

  rm "${filedir}/${filename}"
  mv "${filedir}/${filename/.c/_AI.c}" "${filedir}/${filename}"
  rm "${filedir}/${filename}_scope.dot"
  rm "${filedir}/${filename}.patch"
  rm result.bc
  rm result2.bc 
  rm result3.bc

done
rm pragmaRemover.out
sudo docker stop dawnccCont
sudo docker container rm dawnccCont
cd ${THIS}

