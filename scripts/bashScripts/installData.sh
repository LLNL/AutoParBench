#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set -e

THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd "${THIS}"

#Download the data
wget www.cs.virginia.edu/~kw5na/lava/Rodinia/Packages/Current/rodinia_3.1.tar.bz2

#Unzip rodinia
tar xjf "${THIS}/rodinia_3.1.tar.bz2"

#Copy data to original benchmarks from rodinia
if [ ! -d "${SCRIPTS}/../benchmarks/original/rodinia_3.1/data" ]; then
  cp -r "${THIS}/rodinia_3.1/data" "${SCRIPTS}/../benchmarks/original/rodinia_3.1/data" 
fi
#Copy data to sequential benchmarks from rodinia
if [ ! -d "${SCRIPTS}/../benchmarks/sequential/rodinia_3.1/data" ]; then
  cp -r "${THIS}/rodinia_3.1/data" "${SCRIPTS}/../benchmarks/sequential/rodinia_3.1/data" 
fi
#Copy data to reference cpu threading benchmarks from rodinia
if [ ! -d "${SCRIPTS}/../benchmarks/reference_cpu_threading/rodinia_3.1/data" ]; then
  cp -r "${THIS}/rodinia_3.1/data" "${SCRIPTS}/../benchmarks/reference_cpu_threading/rodinia_3.1/data" 
fi
#Copy data to Autopar benchmarks from rodinia
if [ ! -d "${SCRIPTS}/../benchmarks/Autopar/rodinia_3.1/data" ]; then
  cp -r "${THIS}/rodinia_3.1/data" "${SCRIPTS}/../benchmarks/Autopar/rodinia_3.1/data" 
fi
#Copy data to ICC Full benchmarks from rodinia
if [ ! -d "${SCRIPTS}/../benchmarks/ICC_Full/rodinia_3.1/data" ]; then
  cp -r "${THIS}/rodinia_3.1/data" "${SCRIPTS}/../benchmarks/ICC_Full/rodinia_3.1/data" 
fi
#Copy data to ICC Cost benchmarks from rodinia
if [ ! -d "${SCRIPTS}/../benchmarks/ICC_Cost/rodinia_3.1/data" ]; then
  cp -r "${THIS}/rodinia_3.1/data" "${SCRIPTS}/../benchmarks/ICC_Cost/rodinia_3.1/data" 
fi
#Copy data to Cetus benchmarks from rodinia
if [ ! -d "${SCRIPTS}/../benchmarks/Cetus/rodinia_3.1/data" ]; then
  cp -r "${THIS}/rodinia_3.1/data" "${SCRIPTS}/../benchmarks/Cetus/rodinia_3.1/data" 
fi

# Delete downloaded files
if [ -d "${THIS}/rodinia_3.1/" ]; then
  rm -r "${THIS}/rodinia_3.1/"
fi

#Delete compressed file
if [ -f "${THIS}/rodinia_3.1.tar.bz2" ]; then
  rm "${THIS}/rodinia_3.1.tar.bz2"
fi

