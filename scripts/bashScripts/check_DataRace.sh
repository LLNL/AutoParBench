#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set_environment() {
export PATH="/opt/intel/compilers_and_libraries_2019.4.243/linux/bin/intel64/:$PATH"
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd ../
TOPDIR=$(pwd)
TOPDIR="${TOPDIR}/benchmarks"
cd "${THIS}"
HIGH_FLAGS_INSP="-collect ti3"
#"-knob scope=extreme -knob stack-depth=16 -knob use-maximum-resources=true"
LOW_FLAGS_INSP="-collect ti2"
DIRECTORY="original"
}

create_lists() {
if [ -f "${THIS}/DataRace_Report.md" ]; then
  rm ${THIS}/DataRace_Report.md
fi

dataracebench_micro_list=(
./DRB001-antidep1-orig-yes.c
./DRB002-antidep1-var-yes.c
./DRB003-antidep2-orig-yes.c
./DRB004-antidep2-var-yes.c
./DRB005-indirectaccess1-orig-yes.c
./DRB006-indirectaccess2-orig-yes.c
./DRB007-indirectaccess3-orig-yes.c
./DRB008-indirectaccess4-orig-yes.c
./DRB009-lastprivatemissing-orig-yes.c
./DRB010-lastprivatemissing-var-yes.c
./DRB011-minusminus-orig-yes.c
./DRB012-minusminus-var-yes.c
./DRB013-nowait-orig-yes.c
./DRB014-outofbounds-orig-yes.c
./DRB015-outofbounds-var-yes.c
./DRB016-outputdep-orig-yes.c
./DRB017-outputdep-var-yes.c
./DRB018-plusplus-orig-yes.c
./DRB019-plusplus-var-yes.c
./DRB020-privatemissing-var-yes.c
./DRB021-reductionmissing-orig-yes.c
./DRB022-reductionmissing-var-yes.c
./DRB024-simdtruedep-orig-yes.c
./DRB025-simdtruedep-var-yes.c
./DRB026-targetparallelfor-orig-yes.c
./DRB028-privatemissing-orig-yes.c
./DRB029-truedep1-orig-yes.c
./DRB030-truedep1-var-yes.c
./DRB031-truedepfirstdimension-orig-yes.c
./DRB032-truedepfirstdimension-var-yes.c
./DRB033-truedeplinear-orig-yes.c
./DRB034-truedeplinear-var-yes.c
./DRB035-truedepscalar-orig-yes.c
./DRB036-truedepscalar-var-yes.c
./DRB037-truedepseconddimension-orig-yes.c
./DRB038-truedepseconddimension-var-yes.c
./DRB040-truedepsingleelement-var-yes.c
./DRB045-doall1-orig-no.c
./DRB046-doall2-orig-no.c
./DRB047-doallchar-orig-no.c
./DRB048-firstprivate-orig-no.c
./DRB049-fprintf-orig-no.c
./DRB050-functionparameter-orig-no.c
./DRB052-indirectaccesssharebase-orig-no.c
./DRB053-inneronly1-orig-no.c
./DRB054-inneronly2-orig-no.c
./DRB057-jacobiinitialize-orig-no.c
./DRB058-jacobikernel-orig-no.c
./DRB059-lastprivate-orig-no.c
./DRB060-matrixmultiply-orig-no.c
./DRB061-matrixvector1-orig-no.c
./DRB062-matrixvector2-orig-no.c
./DRB063-outeronly1-orig-no.c
./DRB064-outeronly2-orig-no.c
./DRB065-pireduction-orig-no.c
./DRB066-pointernoaliasing-orig-no.c
./DRB067-restrictpointer1-orig-no.c
./DRB068-restrictpointer2-orig-no.c
./DRB070-simd1-orig-no.c
./DRB071-targetparallelfor-orig-no.c
./DRB073-doall2-orig-yes.c
./DRB084-threadprivatemissing-orig-yes.c
./DRB085-threadprivate-orig-no.c
./DRB090-static-local-orig-yes.c
./DRB091-threadprivate2-orig-no.c
./DRB092-threadprivatemissing2-orig-yes.c
./DRB093-doall2-collapse-orig-no.c
./DRB094-doall2-ordered-orig-no.c
./DRB095-doall2-taskloop-orig-yes.c
./DRB096-doall2-taskloop-collapse-orig-no.c
./DRB097-target-teams-distribute-orig-no.c
./DRB098-simd2-orig-no.c
./DRB099-targetparallelfor2-orig-no.c
./DRB104-nowait-barrier-orig-no.c
./DRB109-orderedmissing-orig-yes.c
./DRB110-ordered-orig-no.c
./DRB111-linearmissing-orig-yes.c
./DRB112-linear-orig-no.c
./DRB113-default-orig-no.c
./DRB114-if-orig-yes.c
	)

dataracebench_poly_list=(
./DRB041-3mm-parallel-no.c
./DRB043-adi-parallel-no.c
./DRB044-adi-tile-no.c
./DRB055-jacobi2d-parallel-no.c
./DRB056-jacobi2d-tile-no.c
)

tmp_files=(
./benchmarks/original/NPB3.0-omp-c/BT/npbparams.h
./benchmarks/original/NPB3.0-omp-c/CG/npbparams.h
./benchmarks/original/NPB3.0-omp-c/EP/npbparams.h
./benchmarks/original/NPB3.0-omp-c/FT/npbparams.h
./benchmarks/original/NPB3.0-omp-c/IS/npbparams.h
./benchmarks/original/NPB3.0-omp-c/LU/npbparams.h
./benchmarks/original/NPB3.0-omp-c/MG/npbparams.h
./benchmarks/original/NPB3.0-omp-c/SP/npbparams.h
./benchmarks/original/rodinia_3.1/openmp/b+tree/output.txt
./benchmarks/original/rodinia_3.1/openmp/bfs/bfs
./benchmarks/original/rodinia_3.1/openmp/bfs/bfs_offload
./benchmarks/original/rodinia_3.1/openmp/bfs/result.txt
./benchmarks/original/rodinia_3.1/openmp/cfd/density
./benchmarks/original/rodinia_3.1/openmp/cfd/density_energy
./benchmarks/original/rodinia_3.1/openmp/cfd/euler3d_cpu
./benchmarks/original/rodinia_3.1/openmp/cfd/euler3d_cpu_double
./benchmarks/original/rodinia_3.1/openmp/cfd/momentum
./benchmarks/original/rodinia_3.1/openmp/hotspot/hotspot
./benchmarks/original/rodinia_3.1/openmp/hotspot3D/3D
./benchmarks/sequential/NPB3.0-omp-c/sys/setparams
./benchmarks/sequential/rodinia_3.1/openmp/b+tree/output.txt
./benchmarks/sequential/rodinia_3.1/openmp/bfs/bfs
./benchmarks/sequential/rodinia_3.1/openmp/bfs/bfs_offload
./benchmarks/sequential/rodinia_3.1/openmp/bfs/result.txt
./benchmarks/sequential/rodinia_3.1/openmp/cfd/density
./benchmarks/sequential/rodinia_3.1/openmp/cfd/density_energy
./benchmarks/sequential/rodinia_3.1/openmp/cfd/euler3d_cpu
./benchmarks/sequential/rodinia_3.1/openmp/cfd/euler3d_cpu_double
./benchmarks/sequential/rodinia_3.1/openmp/cfd/momentum
./benchmarks/sequential/rodinia_3.1/openmp/heartwall/heartwall
./benchmarks/sequential/rodinia_3.1/openmp/hotspot/hotspot
./benchmarks/sequential/rodinia_3.1/openmp/hotspot3D/3D
)
}

run_Rodinia() {
declare -A map=()
# Run Rodinia Benchmarks to check the outputs.
cd "${TOPDIR}/original/rodinia_3.1"
RODINIADIR=$(pwd)
COMPILER="icc -qopenmp -w"
run_Rodinia_Exe

cd "${TOPDIR}/sequential/rodinia_3.1"
RODINIADIR=$(pwd)
COMPILER="icc -w -qopenmp -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=3"
run_Rodinia_Exe

echo "<tr><td>b+tree</td>${map["b+tree"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>bfs</td>${map["bfs"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>euler3d_cpu</td>${map["euler3d_cpu"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>euler3d_cpu_double</td>${map["euler3d_cpu_double"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>heartwall</td>${map["heartwall"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>hotspot</td>${map["hotspot"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>3D</td>${map["3D"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
unset map
}

run_Rodinia_Exe() {
make OMP_clean
LINK=${COMPILER} ICC=${COMPILER} CXX=${COMPILER} CC=${COMPILER} make OMP
echo "b+tree"
cd "${RODINIADIR}/openmp/b+tree"
chmod +x b+tree.out
run_Intel_Inspector "b+tree.out core 2 file ../../data/b+tree/mil.txt command ../../data/b+tree/command.txt &> /dev/null"
map["b+tree"]="${map["b+tree"]}S{REPORT}"
echo "bfs"
cd "${RODINIADIR}/openmp/bfs"
chmod +x bfs
run_Intel_Inspector "bfs 4 ../../data/bfs/graph1MW_6.txt &> /dev/null"
map["bfs"]="${map["bfs"]}S{REPORT}"
echo "cfd"
cd "${RODINIADIR}/openmp/cfd"
chmod +x euler3d_cpu
run_Intel_Inspector "euler3d_cpu ../../data/cfd/fvcorr.domn.193K &> /dev/null"
map["euler3d_cpu"]="${map["euler3d_cpu"]}S{REPORT}"
chmod +x euler3d_cpu_double
run_Intel_Inspector "euler3d_cpu_double ../../data/cfd/fvcorr.domn.193K &> /dev/null"
map["euler3d_cpu_double"]="${map["euler3d_cpu_double"]}S{REPORT}"
echo "heartwall"
cd "${RODINIADIR}/openmp/heartwall"
chmod +x heartwall
run_Intel_Inspector "heartwall ../../data/heartwall/test.avi 20 4 &> /dev/null"
map["heartwall"]="${map["heartwall"]}S{REPORT}"
echo "hotspot"
cd "${RODINIADIR}/openmp/hotspot"
chmod +x hotspot
run_Intel_Inspector "hotspot 1024 1024 2 4 ../../data/hotspot/temp_1024 ../../data/hotspot/power_1024 /dev/null"
map["hotspot"]="${map["hotspot"]}S{REPORT}"
echo "hotspot3D"
cd "${RODINIADIR}/openmp/hotspot3D"
chmod +x 3D
run_Intel_Inspector "3D 512 8 100 ../../data/hotspot3D/power_512x8 ../../data/hotspot3D/temp_512x8 /dev/null"
map["3D"]="${map["3D"]}S{REPORT}"
make OMP_clean
}

run_NAS() {
# Run NAS Benchmarks to check for Data Races.
THIS="${PWD}"
cd "${TOPDIR}/original/NPB3.0-omp-c"
ORIGINALDIR=$(pwd)
cd "${TOPDIR}/sequential/NPB3.0-omp-c"
SEQUENTIALDIR=$(pwd)
cd "${THIS}"
declare -A map=()

if [ -d "${ORIGINALDIR}/bin" ]; then
  rm -r "${ORIGINALDIR}/bin"
fi
mkdir "${ORIGINALDIR}/bin"
cd "${ORIGINALDIR}"
COMPILER="icc -qopenmp -w"
cp "${ORIGINALDIR}/config/suite.def_S" "${ORIGINALDIR}/config/suite.def"
CLINK=${COMPILER} CC=${COMPILER} make clean
CLINK=${COMPILER} CC=${COMPILER} make suite
cp "${ORIGINALDIR}/config/suite.def_M" "${ORIGINALDIR}/config/suite.def"
cd "${ORIGINALDIR}/bin"
run_NAS_EXE
cd "${ORIGINALDIR}"
CLINK=${COMPILER} CC=${COMPILER} make clean
cd "${THIS}"

if [ -d "${SEQUENTIALDIR}/bin" ]; then
  rm -r "${SEQUENTIALALDIR}/bin"
fi
mkdir "${SEQUENTIALDIR}/bin"
cd "${SEQUENTIALDIR}"
COMPILER="icc -w -qopenmp -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=3"
cp "${SEQUENTIALDIR}/config/suite.def_S" "${SEQUENTIALDIR}/config/suite.def"
CLINK=${COMPILER} CC=${COMPILER} make clean
CLINK=${COMPILER} CC=${COMPILER} make suite
cp "${SEQUENTIALDIR}/config/suite.def_M" "${SEQUENTIALDIR}/config/suite.def"
cd "${SEQUENTIALDIR}/bin"
run_NAS_EXE
cd "${SEQUENTIALDIR}"
CLINK=${COMPILER} CC=${COMPILER} make clean
cd "${THIS}"

echo "<tr><td>bt</td>${map["bt"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>cg</td>${map["cg"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>ep</td>${map["ep"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>ft</td>${map["ft"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>is</td>${map["is"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>lu</td>${map["lu"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>mg</td>${map["mg"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
echo "<tr><td>sp</td>${map["sp"]}</tr>" &>> ${THIS}/reports/DataRace_Report.md
unset map
}

run_NAS_EXE() {
chmod +x "bt.W"
run_Intel_Inspector "bt.W"
map["bt"]="${map["bt"]}${REPORT}"

chmod +x "cg.W"
run_Intel_Inspector "cg.W"
map["cg"]="${map["cg"]}${REPORT}"

chmod +x "ep.W"
run_Intel_Inspector "ep.W"
map["ep"]="${map["ep"]}${REPORT}"

chmod +x "ft.W"
run_Intel_Inspector "ft.W"
map["ft"]="${map["ft"]}${REPORT}"

chmod +x "is.W"
run_Intel_Inspector "is.W"
map["is"]="${map["is"]}${REPORT}"

chmod +x "lu.W"
run_Intel_Inspector "lu.W"
map["lu"]="${map["lu"]}${REPORT}"

chmod +x "mg.W"
run_Intel_Inspector "mg.W"
map["mg"]="${map["mg"]}${REPORT}"

chmod +x "sp.W"
run_Intel_Inspector "sp.W"
map["sp"]="${map["sp"]}${REPORT}"
}

run_dataracebench() {
# Run DataRaceBench Benchmarks to check Data Races.
cd "${TOPDIR}/original/dataracebench"
ORIGINALDIR=$(pwd)
cd "${TOPDIR}/sequential/dataracebench"
SEQUENTIALDIR=$(pwd)
cd "${THIS}"
for f in ${dataracebench_micro_list[@]}; do
  echo "${f/.c/.out}"
  REPORT="<tr>"

  COMPILER="icc -qopenmp -w"
  ${COMPILER} -std=c99 "${ORIGNALDIR}/${f}" -o "${f/.c/.out}" -lm
  REPORT="${REPORT}<td>${f}</td>"
  run_Intel_Inspector "${f/.c/.out}" 

  COMPILER="icc -w -qopenmp -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
  ${COMPILER} -std=c99 "${SEQUENTIALDIR}/${f}" -o "${f/.c/.out}" -lm
  run_Intel_Inspector "${f/.c/.out}" 

  REPORT="${REPORT}</tr>"
  echo "${REPORT}" &>> ${THIS}/reports/DataRace_Report.md
  if [ -f "${f/.c/.out}" ]; then
    rm "${f/.c/.out}"
  fi
  if [ -f "${f/.c/.optrpt}" ]; then
    rm "${f/.c/.optrpt}"
  fi
done

for f in ${dataracebench_poly_list[@]}; do
  echo "${f/.c/.out}"
  REPORT="<tr>"

  COMPILER="icc -qopenmp -w"
  echo  "${ORIGINALDIR}/utilities/polybench.c"
  (${COMPILER} -std=c99 -c "${ORIGINALDIR}/utilities/polybench.c" -o polybench.o -lm)
  (${COMPILER} -std=c99 -c "${ORIGINALDIR}/${f}" -o ${f/.c/.o} -lm)
  (${COMPILER} -o ${f/.c/.out} -std=c99 polybench.o ${f/.c/.o} -lm)
  chmod +x "${f/.c/.out}"
  REPORT="${REPORT}<td>${f}</td>"
  run_Intel_Inspector "${f/.c/.out}"
  rm "${f/.c/.o}"
  rm "polybench.o"


  echo "${SEQUENTIALDIR}/utilities/polybench.c"
  COMPILER="icc -w -qopenmp -par-threshold0 -no-vec -fno-inline -parallel -qopt-report-phase=all -qopt-report=5"
  (${COMPILER} -std=c99 -c "${SEQUENTIALDIR}/utilities/polybench.c" -o polybench.o -lm)
  (${COMPILER} -std=c99 -c "${SEQUENTIALDIR}/${f}" -o ${f/.c/.o} -lm)
  (${COMPILER} -o ${f/.c/.out} -std=c99 polybench.o ${f/.c/.o} -lm)
  chmod +x "${f/.c/.out}"
  run_Intel_Inspector "${f/.c/.out}"
  rm "${f/.c/.o}"
  rm "polybench.o"

  REPORT="${REPORT}</tr>"
  echo "${REPORT}" &>> ${THIS}/reports/DataRace_Report.md 
  if [ -f "${f/.c/.out}" ]; then
    rm "${f/.c/.out}"
  fi
  if [ -f "${f/.c/.optrpt}" ]; then
    rm "${f/.c/.optrpt}"
  fi
done

cd "${THIS}"
}

run_Thread_Sanitizer() {
  # Compile the source file
  sudo docker run --rm -it -v $(pwd):/root gleisonsdm/threadsanitizer:latest /usr/src/llvm-build/bin/clang -L/usr/src/build-compiler-rt/lib/linux/libclang_rt.tsan-x86_64.a -fopenmp -fsanitize=thread -g ${1} -o ${2}

  # Run the compiled program
  sudo docker run --rm -it -v $(pwd):/root gleisonsdm/threadsanitizer:latest ./${2}
}

run_Intel_Inspector() {
  pwd
  echo "${1}"
  /opt/intel/inspector/bin64/inspxe-cl "${HIGH_FLAGS_INSP}" -- ./${1} &> /dev/null
  LOG=$(grep -rn "Data race problem(s) detected" "r000ti3/inspxe-cl.txt")
  if [ "${LOG}" != "" ]; then
    REPORT="${REPORT}<td>Yes</td>"
  else
    REPORT="${REPORT}<td>No</td>"
  fi
  if [ -d "r000ti3" ]; then
    rm -r "r000ti3"
  fi
}

check_outputs() {
  echo "" &> ${THIS}/reports/DataRace_Report.md
  echo "# Data Race Report" &>> ${THIS}/reports/DataRace_Report.md
  echo "" &>> ${THIS}/reports/DataRace_Report.md
  echo "This report was produced running intel inspector to check data races into the benchmarks. Yes or No are the possible values, the next step is a manual inspection." &>> ${THIS}/reports/DataRace_Report.md
  echo "" &>> ${THIS}/reports/DataRace_Report.md
  echo "<table><tr><th>Benchmark</th><th>Original</th><th>ICC Full</th></tr>" &>> ${THIS}/reports/DataRace_Report.md

  run_dataracebench

  #run_NAS

  #run_Rodinia

  echo "</table>" &>> ${THIS}/reports/DataRace_Report.md
}


clean_environment() {
  # Remove binary files.
  cd "${TOPDIR}/sequential"
  for f in $(find . -name "*.optrpt"); do
    rm "$f"
  done

  cd "${TOPDIR}/../"
  for f in ${tmp_files[@]}; do
    if [ -f "${f}" ]; then
      rm "${f}"
    fi
  done
  if [ -f "${THIS}/ipo_out.optrpt" ]; then
    rm "${THIS}/ipo_out.optrpt"
  fi
  if [ -f "${THIS}/polybench.optrpt" ]; then
    rm "${THIS}/polybench.optrpt"
  fi

}

set_environment
create_lists

check_outputs

clean_environment
