#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# STAGE 1: build c_func_name_extract
FROM ubuntu:cosmic as build

# install build dependencies
RUN apt update
RUN apt install -y make vim cmake build-essential git wget gcc-7 g++-7 texlive git automake autoconf libtool debhelper devscripts ghostscript lsb-core python
RUN apt-get update
RUN apt-get install apt-utils

# use gcc 7
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 100
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 100

# prepare c_func_name_extract python scripts
WORKDIR /root
RUN git clone https://github.com/yuedeji/c_func_name_extract.git
WORKDIR /c_func_name_extract

