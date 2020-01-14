#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# STAGE 1: build Cetus
FROM ubuntu:cosmic as build

# install build dependencies
RUN apt update
RUN apt install -y make vim cmake build-essential git wget gcc-7 g++-7 texlive git automake autoconf libtool debhelper devscripts ghostscript lsb-core python
RUN apt-get update
RUN apt-get install apt-utils
RUN apt-get install -y default-jre
RUN apt-get install -y default-jdk

# use gcc 7
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 100
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 100

# prepare CETUS source code
WORKDIR /usr/src
RUN wget https://www.dropbox.com/s/5338ld0k54th12o/cetus.tar.gz?dl=0
RUN mv cetus.tar.gz?dl=0 cetus.tar.gz
RUN tar -xvf cetus.tar.gz

# build Cetus
WORKDIR /usr/src/cetus-1.4.4
# feel free to change the -j value
RUN chmod 777 build.sh
RUN ./build.sh compile
RUN ./build.sh jar
RUN ./build.sh bin

# setup PATH
ENV CLASSPATH="/usr/src/cetus-1.4.4/lib/cetus.jar:/usr/src/cetus-1.4.4/lib/antlr.jar:/usr/src/cetus-1.4.4/lib/rsyntaxtextarea.jar"
WORKDIR /root
