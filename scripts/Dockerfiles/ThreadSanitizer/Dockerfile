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

RUN git clone https://github.com/llvm/llvm-project.git

WORKDIR /usr/src/llvm-project

RUN cp -r /usr/src/llvm-project/clang /usr/src/llvm-project/llvm/tools/clang

RUN mkdir /usr/src/llvm-build

WORKDIR /usr/src/llvm-build

ENV CXX=g++-8
ENV CC=gcc-8

RUN cmake -DBUILD_SHARED_LIBS=ON -DLLVM_ENABLE_PROJECTS=clang -G "Unix Makefiles" ../llvm-project/llvm

RUN make -j4

WORKDIR /usr/src

WORKDIR /usr/src/llvm-build/tools

RUN ["chmod","+x","llvm-config"]

WORKDIR /usr/src/llvm-build/lib/clang/10.0.0/

RUN cmake -DLLVM_CONFIG_PATH=/usr/src/llvm-build/bin/llvm-config -DLIBOMP_TSAN_SUPPORT=1 ../../../../llvm-project/openmp
#../../../../llvm-project/openmp
#../../../../llvm-project/compiler-rt/

RUN cmake --build . --target install

RUN make -j4

ENV LD_PRELOAD=/usr/local/lib/libomp.so

#Go back to root folder
WORKDIR /root
