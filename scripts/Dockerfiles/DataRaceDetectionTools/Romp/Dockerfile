#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# STAGE 1: build ROMP
FROM ubuntu:bionic as build

# install build dependencies
RUN apt-get update
RUN apt-get install -y make vim cmake gcc-7 g++-7 git wget python zip unzip libomp-dev autoconf libtool apt-utils build-essential libboost-all-dev libdwarf-dev
RUN apt-get install libelf-dev
RUN apt-get -y upgrade

WORKDIR /usr/src
RUN libtoolize

#--------------------------------
#   Clang
#--------------------------------
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

#Download LLVM, Clang source tarballs if not already downloaded
RUN wget "${LLVM_SRC_ADDR}"

RUN wget "${CLANG_SRC_ADDR}"

RUN mkdir "${LLVM_SRC}"
RUN tar -Jxf "llvm-${LLVM_VER}.src.tar.xz" -C "${LLVM_SRC}" --strip 1

RUN mkdir "${CLANG_SRC}"
RUN tar -Jxf "cfe-${CLANG_VER}.src.tar.xz" -C "${CLANG_SRC}" --strip 1

#Create output folder for LLVM if not already created
RUN mkdir ${LLVM_OUTPUT_DIR}

#Create setup with cmake if not already created
workdir ${LLVM_OUTPUT_DIR}

RUN CXX=g++-7 cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_SHARED_LIBS=ON ${LLVM_SRC}

#Prebuild clang to workaround
RUN make clang -j4

#Build LLVM then go back to root folder
RUN make -j4
workdir ${ROOT_FOLDER}

#--------------------------------
#   ROMP
#--------------------------------

# install TCMalloc
ENV CXXFLAGS=-std=c++11
RUN git clone https://github.com/zygyz/romp.git /usr/src/romp
WORKDIR /usr/src/romp/pkgs-src
RUN git clone https://github.com/gperftools/gperftools.git /usr/src/romp/pkgs-src/gperftools
WORKDIR /usr/src/romp/pkgs-src/gperftools
RUN mkdir gperftools-build gperftools-install
RUN cp /usr/share/libtool/build-aux/ltmain.sh .
RUN autoreconf -i
WORKDIR /usr/src/romp/pkgs-src/gperftools/perftools-build
RUN ../configure --prefix=/usr/src/romp/pkgs-src/gperftools/gperftools-install
RUN make -j4
RUN make install -j4

# install dyninst
WORKDIR /usr/src/romp/pkgs-src
RUN git clone https://github.com/dyninst/dyninst.git /usr/src/romp/pkgs-src/dyninst
WORKDIR /usr/src/romp/pkgs-src/dyninst
RUN mkdir dyninst-build dyninst-install
WORKDIR /usr/src/romp/pkgs-src/dyninst/dyninst-build
RUN cmake -DCMAKE_INSTALL_PREFIX=/usr/src/romp/pkgs-src/dyninst/dyninst-install -DBOOST_MIN_VERSION=1.61.0 ..
RUN make -j4
RUN make install -j4

# build and install LLVM OpenMP runtime library
WORKDIR /usr/src/romp/pkgs-src/llvm-openmp/openmp
RUN mkdir llvm-openmp-build llvm-openmp-install
WORKDIR /usr/src/romp/pkgs-src/llvm-openmp/openmp/llvm-openmp-build
ENV PATH="/usr/src/llvm-build/bin/:$PATH"
RUN cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++  -DCMAKE_INSTALL_PREFIX=`pwd`/../llvm-openmp-install ..
RUN make -j4
RUN make install -j4

# build and install romp
ENV CPATH=/usr/src/romp/pkgs-src/llvm-openmp/openmp/llvm-openmp-install/include:$CPATH
ENV LD_LIBRARY_PATH=/usr/src/romp/pkgs-src/llvm-openmp/openmp/llvm-openmp-install/lib:/usr/src/romp/pkgs-src/gperftools/gperftools-install/lib:$LD_LIBRARY_PATH
RUN apt-get install libelf-dev
WORKDIR /usr/src/romp/pkgs-src/romp-lib
RUN mkdir romp-build romp-install
WORKDIR /usr/src/romp/pkgs-src/romp-lib/romp-build
RUN cmake -DCMAKE_INSTALL_PREFIX=/usr/src/romp/pkgs-src/romp-lib/romp-install ..
RUN make -j4
RUN make install -j4

# build dyninst client
WORKDIR /usr/src/romp/pkgs-src/dyninst-client
RUN make -j4
RUN ["chmod","+x","omp_race_client"]

# to collect results and run the programs
ENV ROMP_VERBOSE="on"
ENV DYNINST_ROOT="/usr/src/romp/pkgs-src/dyninst/dyninst-install"
ENV DYNINSTAPI_RT_LIB="$DYNINST_ROOT/lib/libdyninstAPI_RT.so"
ENV DYNINST_CLIENT="/usr/src/romp/pkgs-src/dyninst-client/omp_race_client"
ENV ROMP_PATH="/usr/src/romp/pkgs-src/romp-lib/romp-install/lib/libomptrace.so"
ENV CPATH="/usr/src/romp/pkgs-src/llvm-openmp/openmp/llvm-openmp-install/include:$CPATH"
ENV LD_LIBRARY_PATH="/usr/src/romp/pkgs-src/llvm-openmp/openmp/llvm-openmp-install/lib:$LD_LIBRARY_PATH"
ENV LD_LIBRARY_PATH="/usr/src/romp/pkgs-src/gperftools/gperftools-install/lib:$LD_LIBRARY_PATH" 
ENV LD_LIBRARY_PATH="/usr/src/romp/pkgs-src/dyninst/dyninst-install/lib:$LD_LIBRARY_PATH"
ENV LD_LIBRARY_PATH="/usr/src/romp/pkgs-src/romp-lib/romp-install/lib:$LD_LIBRARY_PATH"

#Go back to root folder
WORKDIR /root
