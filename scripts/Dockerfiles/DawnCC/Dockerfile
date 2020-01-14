#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# STAGE 1: build DAWNCC
FROM ubuntu:cosmic as build

# install build dependencies
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update
RUN apt-get install apt-utils -y
RUN apt-get upgrade -y
RUN apt-get install libexpat1 -y
RUN apt-get install -y make vim cmake git wget zip unzip
RUN apt-get install -y gcc-5 g++-5
RUN apt-get install -y libomp-dev
RUN apt-get install -y python

# use gcc 5
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 100
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 100

WORKDIR /usr/src
RUN git clone https://github.com/gleisonsdm/DawnCC-Compiler.git

#Clang and LLVM versions
ENV LLVM_VER="3.7.0"
ENV CLANG_VER="3.7.0"

#DawnCC root path plus Clang and LLVM source folders
ENV ROOT_FOLDER="/usr/src"
ENV DAWN_PATH="${ROOT_FOLDER}/DawnCC"
ENV LLVM_SRC="${ROOT_FOLDER}/llvm"
ENV CLANG_SRC="${LLVM_SRC}/tools/clang"
ENV LLVM_OUTPUT_DIR="${ROOT_FOLDER}/llvm-build"

#Tarball names
ENV LLVM_SRC_FILE="llvm-${LLVM_VER}.src.tar.xz"
ENV CLANG_SRC_FILE="cfe-${CLANG_VER}.src.tar.xz"
ENV DAWN_SRC_FILE="DawnCC-Compiler-master.zip"

#Tarball websites
ENV LLVM_SRC_ADDR="http://llvm.org/releases/${LLVM_VER}/${LLVM_SRC_FILE}"
ENV CLANG_SRC_ADDR="http://llvm.org/releases/${CLANG_VER}/${CLANG_SRC_FILE}"
ENV DAWN_SRC_ADDR="https://github.com/gleisonsdm/DawnCC-Compiler/archive/master.zip"

#Download LLVM, Clang and DawnCC source tarballs if not already downloaded
RUN wget "${LLVM_SRC_ADDR}"

RUN wget "${CLANG_SRC_ADDR}"

RUN wget -O "${DAWN_SRC_FILE}" "${DAWN_SRC_ADDR}"
#download master.zip as DawnCC-Compiler-master.zip

RUN unzip "${DAWN_SRC_FILE}" 
RUN mv "${ROOT_FOLDER}/${DAWN_SRC_FILE%%.*}" "${DAWN_PATH}"

RUN mkdir "${LLVM_SRC}"
RUN tar -Jxf "llvm-${LLVM_VER}.src.tar.xz" -C "${LLVM_SRC}" --strip 1


#Apply DawnCC patch into LLVM source
workdir "${LLVM_SRC}"
RUN patch -p1 < "${DAWN_PATH}/ArrayInference/llvm-patch.diff"
workdir "${ROOT_FOLDER}"

RUN mkdir "${CLANG_SRC}"
RUN tar -Jxf "cfe-${CLANG_VER}.src.tar.xz" -C "${CLANG_SRC}" --strip 1
#extract clang tarball to llvm/tools folder

#Create output folder for LLVM if not already created
RUN mkdir ${LLVM_OUTPUT_DIR}

#Setup LLVM+Clang and scope-finder plugin if not already setup
ENV EXTRA_FOLDER="${LLVM_SRC}/tools/clang/tools/extra"

RUN mkdir -p "${EXTRA_FOLDER}"
RUN echo "add_subdirectory(scope-finder)" > ${EXTRA_FOLDER}/CMakeLists.txt
RUN cp -rf ${DAWN_PATH}/ScopeFinder/scope-finder ${EXTRA_FOLDER}/.

#Create setup with cmake if not already created
workdir ${LLVM_OUTPUT_DIR}

RUN CXX=g++-5 cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_SHARED_LIBS=ON ${LLVM_SRC}

#Prebuild clang to workaround DawnCC build problems
RUN make clang -j10

#Build LLVM then go back to root folder
RUN make -j10
workdir ${ROOT_FOLDER}

#Create lib folder of DawnCC if not already created
RUN mkdir ${DAWN_PATH}/lib 

#Navigate to DawnCC output directory, run if theres no makefile, and then build DawnCC
workdir ${DAWN_PATH}/lib

RUN CXX=g++-5 cmake -DLLVM_DIR=${LLVM_OUTPUT_DIR}/share/llvm/cmake ${DAWN_PATH}

RUN make -j10

#Go back to root folder
WORKDIR /root
