#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# STAGE 1: build Traco
FROM ubuntu:cosmic as build

# install build dependencies
RUN apt update
RUN apt install -y make vim cmake git wget gcc-7 g++-7 texlive git subversion automake autoconf unzip libtool default-jre default-jdk debhelper devscripts ghostscript lsb-core python libboost-all-dev python-setuptools

# use gcc 7
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 100
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 100

# prepare Traco source code
WORKDIR /usr/src
RUN svn checkout http://svn.code.sf.net/p/traco/code/trunk traco-code

# prepare islplot
RUN wget https://github.com/tobig/islplot/archive/master.zip
RUN unzip master.zip
RUN mv islplot-master/ islplot/
WORKDIR /usr/src/islplot/
RUN python setup.py install

# build Traco
WORKDIR /usr/src/traco-code
RUN echo "/usr/src/traco-code/barvinok0.41/iscc < barvinok_input > ppp" &> barv_script
RUN echo "touch lock" &>> barv_script
# feel free to change the -j value
RUN bash install_ubuntu

WORKDIR /root
