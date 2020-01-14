#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# STAGE 1: build PRAGMA FINDER
FROM ubuntu:bionic as build

# install build dependencies
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update
RUN apt-get install apt-utils -y
RUN apt-get upgrade -y
RUN apt-get install libexpat1 -y
RUN apt-get install -y make vim cmake gcc-8 g++-8 git wget zip unzip 
RUN apt-get install -y libomp-dev
RUN apt-get install -y python

WORKDIR /usr/src

#Clang and LLVM versions
ENV LLVM_VER="8.0.0"
ENV CLANG_VER="8.0.0"

#DawnCC root path plus Clang and LLVM source folders
ENV ROOT_FOLDER="/usr/src"
ENV OMPEXTRACTOR_PATH="${ROOT_FOLDER}/OMP_Extractor"
ENV LLVM_SRC="${ROOT_FOLDER}/llvm"
ENV CLANG_SRC="${LLVM_SRC}/tools/clang"
ENV LLVM_OUTPUT_DIR="${ROOT_FOLDER}/llvm-build"

#Tarball names
ENV LLVM_SRC_FILE="llvm-${LLVM_VER}.src.tar.xz"
ENV CLANG_SRC_FILE="cfe-${CLANG_VER}.src.tar.xz"

#Tarball websites
ENV LLVM_SRC_ADDR="http://llvm.org/releases/${LLVM_VER}/${LLVM_SRC_FILE}"
ENV CLANG_SRC_ADDR="http://llvm.org/releases/${CLANG_VER}/${CLANG_SRC_FILE}"

#Download LLVM, Clang and OpenMP Extractor source tarballs if not already downloaded
RUN wget "${LLVM_SRC_ADDR}"

RUN wget "${CLANG_SRC_ADDR}"

RUN mkdir "${LLVM_SRC}"
RUN tar -Jxf "llvm-${LLVM_VER}.src.tar.xz" -C "${LLVM_SRC}" --strip 1

RUN mkdir "${CLANG_SRC}"
RUN tar -Jxf "cfe-${CLANG_VER}.src.tar.xz" -C "${CLANG_SRC}" --strip 1
#extract clang tarball to llvm/tools folder

#Create output folder for LLVM if not already created
RUN mkdir ${LLVM_OUTPUT_DIR}

#Create setup with cmake if not already created
workdir ${LLVM_OUTPUT_DIR}

RUN CXX=g++-8 cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_SHARED_LIBS=ON ${LLVM_SRC}

#Prebuild clang to workaround
RUN make clang -j4

#Build LLVM then go back to root folder
RUN make -j4
workdir ${ROOT_FOLDER}

#NOTE: Remove the token when AutoParBench be a public repository
RUN git clone https://github.com/gleisonsdm/AutoParBench.git ${OMPEXTRACTOR_PATH}

#Create lib folder of OMP Extractor if not already created
RUN mkdir ${OMPEXTRACTOR_PATH}/lib 

#Navigate to OMP Extractor output directory, run if theres no makefile, and then build OpenMP Extractor
workdir ${OMPEXTRACTOR_PATH}/lib

RUN CXX=g++-8 cmake -DLLVM_DIR=${LLVM_OUTPUT_DIR}/lib/cmake/llvm ${OMPEXTRACTOR_PATH}/tools/OpenMPExtractor

RUN make -j4

#Go back to root folder
WORKDIR /root
