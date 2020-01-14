#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

# STAGE 1: build ROSE
FROM ubuntu:cosmic as build

# install build dependencies
RUN apt update
RUN apt install -y make vim cmake git wget gcc g++ gfortran gcc-7 g++-7 gfortran-7 libxml2-dev texlive git automake autoconf libtool flex bison openjdk-8-jdk debhelper devscripts ghostscript lsb-core python perl-doc

# use gcc 7
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 100
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 100
RUN update-alternatives --install /usr/bin/gfortran gfortran /usr/bin/gfortran-7 100

# fetch boost source
WORKDIR /usr/src
RUN wget -O boost-1.67.0.tar.bz2 http://sourceforge.net/projects/boost/files/boost/1.67.0/boost_1_67_0.tar.bz2/download \
	&& tar xf boost-1.67.0.tar.bz2 \
	&& rm -f boost-1.67.0.tar.bz2

# build boost
WORKDIR /usr/src/boost_1_67_0
RUN ./bootstrap.sh --prefix=/usr/rose --with-libraries=chrono,date_time,filesystem,iostreams,program_options,random,regex,serialization,signals,system,thread,wave || cat ./bootstrap.log
RUN ./b2 -sNO_BZIP2=1 install

# prepare ROSE source code
WORKDIR /usr/src
RUN git clone https://github.com/rose-compiler/rose.git
RUN cd rose && ./build

# build ROSE
WORKDIR /usr/src/rose-build
RUN CC=gcc-7 CXX=g++-7 CXXFLAGS= ../rose/configure --prefix=/usr/rose --oldincludedir=/usr/include --with-C_OPTIMIZE=-O0 --with-CXX_OPTIMIZE=-O0 --with-C_DEBUG='-g' --with-CXX_DEBUG='-g' --with-boost=/usr/rose --with-boost-libdir=/usr/rose/lib --with-gfortran=/usr/bin/gfortran-7 --enable-languages=c,c++,fortran --enable-projects-directory --enable-edg_version=5.0
# feel free to change the -j value
RUN make core -j4
RUN make install-core -j4

# strip symbols from the binaries to reduce size
#RUN apt-get update && apt-get install -y binutils && rm -rf /var/lib/apt/lists/*
#RUN strip /usr/rose/bin/* /usr/rose/lib/* || true

# STAGE 2: build the image
FROM ubuntu:cosmic as rose

# copy installed ROSE
COPY --from=build /usr/rose /usr/rose

# add configuration of ld
ADD ld.so.conf /etc/

# add JRE
ADD jre/ /usr/jre

# setup PATH
ENV PATH="/usr/rose/bin:/usr/jre/bin:$PATH"

# apply ld configuration
RUN ldconfig

# add other packages
RUN apt-get update
RUN apt-get install -y gcc-7 g++-7 gfortran-7

# use gcc 7 in rose package
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 100
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 100
RUN update-alternatives --install /usr/bin/gfortran gfortran /usr/bin/gfortran-7 100

RUN apt-get update
RUN apt-get install libicu60

RUN sed -i '1s/^/#define __builtin_bswap16 __bswap_constant_16\n/' /usr/rose/include/edg/g++-7_HEADERS/hdrs7/bits/byteswap.h

WORKDIR /root
