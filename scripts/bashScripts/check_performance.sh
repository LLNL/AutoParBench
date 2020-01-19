#!/bin/bash
#set -e 

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

run_NAS() {
OUTREF=${1}
COMP_TYPE=${2}
cd "${TOPDIR}/benchmarks/${DIRECTORY}/NPB3.0-omp-c"
NASDIR=$(pwd)
cd "${SCRIPTS}"

if [ -d "${NASDIR}/bin" ]; then
  rm -r "${NASDIR}/bin"
fi
mkdir "${NASDIR}/bin"

cd "${NASDIR}"
if [ "${COMP_TYPE}" == "S" ]; then
  cp "${NASDIR}/config/suite.def_T" "${NASDIR}/config/suite.def"
fi
if [ "${COMP_TYPE}" == "W" ]; then
  cp "${NASDIR}/config/suite.def_S" "${NASDIR}/config/suite.def"
fi
if [ "${COMP_TYPE}" == "A" ]; then
  cp "${NASDIR}/config/suite.def_M" "${NASDIR}/config/suite.def"
fi
if [ "${COMP_TYPE}" == "B" ]; then
  cp "${NASDIR}/config/suite.def_L" "${NASDIR}/config/suite.def"
fi

ulimit -s 64000
CLINK=${COMPILER} CC=${COMPILER} make clean
CLINK=${COMPILER} CC=${COMPILER} make suite
cd "${NASDIR}/bin"
chmod +x bt.${COMP_TYPE}
echo "BT ${COMP_TYPE}"
echo "BT ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./bt.${COMP_TYPE} &> ${OUTPUTS}/bt_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
chmod +x cg.${COMP_TYPE} 
echo "CG ${COMP_TYPE}"
echo "CG ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./cg.${COMP_TYPE} &> ${OUTPUTS}/cg_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
chmod +x ep.${COMP_TYPE} 
echo "EP ${COMP_TYPE}"
echo "EP ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./ep.${COMP_TYPE} &> ${OUTPUTS}/ep_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
chmod +x ft.${COMP_TYPE}
echo "FT ${COMP_TYPE}"
echo "FT ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./ft.${COMP_TYPE} &> ${OUTPUTS}/ft_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
chmod +x is.${COMP_TYPE}
echo "IS ${COMP_TYPE}"
echo "IS ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./is.${COMP_TYPE} &> ${OUTPUTS}/is_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
#chmod +x lu.${COMP_TYPE} 
#echo "LU ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
#echo "LU ${COMP_TYPE}"
#time (timeout 7200s ./lu.${COMP_TYPE} &> ${OUTPUTS}/lu_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
chmod +x mg.${COMP_TYPE} 
echo "MG ${COMP_TYPE}"
echo "MG ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./mg.${COMP_TYPE} &> ${OUTPUTS}/mg_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
chmod +x sp.${COMP_TYPE} 
echo "SP ${COMP_TYPE}"
echo "SP ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./sp.${COMP_TYPE} &> ${OUTPUTS}/sp_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
cd "${NASDIR}"
CLINK=${COMPILER} CC=${COMPILER} make clean
cd "${SCRIPTS}"
}

run_Rodinia() {
OUTREF=${1}
COMP_TYPE=${2}
cd "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1"
RODINIADIR=$(pwd)
cd "${SCRIPTS}"

if [ -d "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1/bin" ] ; then
  rm -r "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1/bin"
fi
mkdir "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1/bin"
mkdir "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1/bin/linux"
mkdir "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1/bin/linux/omp"

chmod 777 -R "${RODINIADIR}"
cd "${RODINIADIR}"
#make OMP_clean
LINK=${COMPLINK} ICC=${COMPICC} CXX=${COMPILERCPP} CC=${COMPILER} make OMP
echo "b+tree"
cd "${RODINIADIR}/openmp/b+tree"
chmod +x b+tree.out
echo "BPT ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./b+tree.out core 2 file ${RODINIADIR}/data/b+tree/mil.txt command ${RODINIADIR}/data/b+tree/command.txt &> ${OUTPUTS}/btree_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
cp output.txt ${OUTPUTS}/btree_${OUTREF}_${COMP_TYPE}_out.txt
#echo "backprop"
#cd "${RODINIADIR}/openmp/backprop"
#chmod +x backprop
#./backprop 65536 &> ${OUTPUTS}/backprop_${OUTREF}_${COMP_TYPE}_out.txt
echo "bfs"
cd "${RODINIADIR}/openmp/bfs"
chmod +x bfs
echo "BFS ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./bfs 4 ${RODINIADIR}/data/bfs/graph1MW_6.txt &> ${OUTPUTS}/bfs_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
cp result.txt ${OUTPUTS}/bfs_${OUTREF}_${COMP_TYPE}_out.txt
echo "cfd"
cd "${RODINIADIR}/openmp/cfd"
chmod +x euler3d_cpu
echo "E3C ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./euler3d_cpu ${RODINIADIR}/data/cfd/fvcorr.domn.193K &> ${OUTPUTS}/euler3d_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
cp density ${OUTPUTS}/euler3d_density_${OUTREF}_${COMP_TYPE}_out.txt
cp density_energy ${OUTPUTS}/euler3d_density_energy_${OUTREF}_${COMP_TYPE}_out.txt
cp momentum ${OUTPUTS}/euler3d_momentum_${OUTREF}_${COMP_TYPE}_out.txt
chmod +x euler3d_cpu_double
echo "E3D ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./euler3d_cpu_double ${RODINIADIR}/data/cfd/fvcorr.domn.193K &> ${OUTPUTS}/euler3d_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
cp density ${OUTPUTS}/euler3d_double_density_${OUTREF}_${COMP_TYPE}_out.txt
cp density_energy ${OUTPUTS}/euler3d_double_density_energy_${OUTREF}_${COMP_TYPE}_out.txt
cp momentum ${OUTPUTS}/euler3d_double_momentum_${OUTREF}_${COMP_TYPE}_out.txt
echo "heartwall"
cd "${RODINIADIR}/openmp/heartwall"
chmod +x heartwall
echo "HTW ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./heartwall ${RODINIADIR}/data/heartwall/test.avi 20 4 &> ${OUTPUTS}/heartwall_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
cp result.txt ${OUTPUTS}/heartwall_${OUTREF}_${COMP_TYPE}_out.txt
echo "hotspot"
cd "${RODINIADIR}/openmp/hotspot"
chmod +x hotspot
echo "HTP ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./hotspot 1024 1024 2 4 ${RODINIADIR}/data/hotspot/temp_1024 ${RODINIADIR}/data/hotspot/power_1024 ${OUTPUTS}/hotspot_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
echo "hotspot 3D"
cd "${RODINIADIR}/openmp/hotspot3D"
chmod +x 3D
echo "H3D ${COMP_TYPE}" &>> "${SCRIPTS}/reports/time.txt"
time (timeout 7200s ./3D 512 8 100 ${RODINIADIR}/data/hotspot3D/power_512x8 ${RODINIADIR}/data/hotspot3D/temp_512x8 ${OUTPUTS}/3d_${OUTREF}_${COMP_TYPE}_out.txt) &>> "${SCRIPTS}/reports/time.txt"
}

check() {
SCRIPTS=$(pwd)
cd "../../"
TOPDIR=$(pwd)
cd "${SCRIPTS}"
OUTPUTS="${SCRIPTS}/Outputs"

if [ -d "${SCRIPTS}/Outputs" ]; then
  rm -r "${SCRIPTS}/Outputs"
fi
mkdir "${SCRIPTS}/Outputs"

if [ -f "${SCRIPTS}/reports/time.txt" ]; then
  rm -r "${SCRIPTS}/reports/time.txt"
fi

export PATH="/opt/intel/compilers_and_libraries_2019.4.243/linux/bin/intel64/:$PATH"
export LD_LIBRARY_PATH="/opt/intel/parallel_studio_xe_2019.4.070/compilers_and_libraries_2019/linux/compiler/lib/intel64/"

COMPILER="icc -qopenmp -w"
COMPILERCPP="icc -qopenmp -w"
COMPLINK="icc -qopenmp -w"
COMPICC="icc -qopenmp -w "
DIRECTORY="sequential"

for i in $(seq 1 1 5); do
  echo "Sequential ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "ref" "A"
  run_Rodinia "ref" "A"
done

COMPILER="icc -qopenmp -w"
COMPILERCPP="icc -qopenmp -w"
COMPLINK="icc -qopenmp -w"
COMPICC="icc -qopenmp -w "
DIRECTORY="reference_cpu_threading"

for i in $(seq 1 1 5); do
  echo "Ground Truth ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "ground_truth" "A"
  run_Rodinia "ground_truth" "A"
done

COMPILER="icc -w -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
COMPILERCPP="icc -w -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
COMPLINK="icc -w -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
COMPICC="icc -w -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
DIRECTORY="ICC_Cost"

for i in $(seq 1 1 5); do
  echo "Parallel with threshold ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "ICC_Cost" "A"
  run_Rodinia "ICC_Cost" "A"
done

COMPILER="icc -w -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
COMPILERCPP="icc -w -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
COMPLINK="icc -w -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
COMPICC="icc -w -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
DIRECTORY="ICC_Full"

for i in $(seq 1 1 5); do
  echo "Parallel without threshold ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "ICC_Full" "A"
  run_Rodinia "ICC_Full" "A"
done

COMPILER="icc -w -qopenmp -O3 "
COMPILERCPP="icc -w -qopenmp -O3 "
COMPLINK="icc -w -qopenmp -O3"
COMPICC="icc -w -qopenmp -O3"
DIRECTORY="sequential"

for i in $(seq 1 1 5); do
  echo "Optimized with -O3 ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "par_no_threshold" "A"
  run_Rodinia "par_no_threshold" "A"
done

COMPILER="icc -qopenmp -w"
COMPILERCPP="icc -qopenmp -w"
COMPLINK="icc -qopenmp -w"
COMPICC="icc -qopenmp -w "
DIRECTORY="original"

for i in $(seq 1 1 5); do
  echo "Manual ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "manual" "A"
  run_Rodinia "manual" "A"
done

COMPILER="icc -qopenmp -w"
COMPILERCPP="icc -qopenmp -w"
COMPLINK="icc -qopenmp -w"
COMPICC="icc -qopenmp -w "
DIRECTORY="Autopar"

for i in $(seq 1 1 5); do
  echo "AUTOPAR ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "autopar" "A"
  run_Rodinia "autopar" "A"
done

COMPILER="icc -qopenmp -w"
COMPILERCPP="icc -qopenmp -w"
COMPLINK="icc -qopenmp -w"
COMPICC="icc -qopenmp -w "
DIRECTORY="Cetus"

for i in $(seq 1 1 5); do
  echo "CETUS ${i}" &>> "${SCRIPTS}/reports/time.txt"
  run_NAS "cetus" "A"
  run_Rodinia "cetus" "A"
done

}

clean_Repository() {
SCRIPTS=$(pwd)
cd "../../"
TOPDIR=$(pwd)
cd "${SCRIPTS}"
OUTPUT_DIR="${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1"

BENCHS=$(find $OUTPUT_DIR -name "*.c" | sort)
BENCHSCPP=$(find $OUTPUT_DIR -name "*.cpp" | sort)
DIRECTORY="${1}"

cd "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1"

for f in $BENCHS; do
  filename="${f//*\/}"
  filedir="${f%/*}"
  bin_filename=${filename/.c/.o}
  report=${filename/.c/.optrpt}

  mv "$filedir/${filename/.c/.optrpt}" "$filedir/${filename/.c/.c.optrpt}"
  if [ -f "${filedir}/${bin_filename}" ]; then
    rm "${filedir}/${bin_filename}"
  fi
  if [ -f "${filedir}/${filename/.c/.c.optrpt}" ]; then
    rm "${filedir}/${filename/.c/.c.optrpt}"
  fi
  if [ -f "${filedir}/${filename}.json" ]; then
    rm "${filedir}/${filename}.json"
  fi

done
for f in $BENCHSCPP; do
  filename="${f//*\/}"
  filedir="${f%/*}"
  bin_filename=${filename/.cpp/.o}

  mv "$filedir/${filename/.cpp/.optrpt}" "$filedir/${filename/.cpp/.cpp.optrpt}"
  if [ -f "${filedir}/${bin_filename}" ]; then
    rm "${filedir}/${bin_filename}"
  fi
  if [ -f "${filedir}/${filename/.cpp/.cpp.optrpt}" ]; then
    rm "${filedir}/${filename/.cpp/.cpp.optrpt}"
  fi
  if [ -f "${filedir}/${filename}.json" ]; then
    rm "${filedir}/${filename}.json"
  fi
done
}

check
clean_Repository "sequential"
clean_Repository "reference_cpu_threading"
clean_Repository "Cetus"
clean_Repository "Autopar"
clean_Repository "original"
clean_Repository "ICC_Cost"
clean_Repository "ICC_Full"


