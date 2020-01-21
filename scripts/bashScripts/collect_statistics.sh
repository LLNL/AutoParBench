#!/bin/bash
set -e

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

SCRIPTS=$(pwd)
cd ${SCRIPTS}/../../
TOPDIR=$(pwd)
cd ${SCRIPTS}

create_Lists() {
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
./DRB039-truedepsingleelement-orig-yes.c
./DRB040-truedepsingleelement-var-yes.c
./DRB041-3mm-parallel-no.c
./DRB043-adi-parallel-no.c
./DRB044-adi-tile-no.c
./DRB045-doall1-orig-no.c
./DRB046-doall2-orig-no.c
./DRB047-doallchar-orig-no.c
./DRB048-firstprivate-orig-no.c
./DRB049-fprintf-orig-no.c
./DRB050-functionparameter-orig-no.c
./DRB052-indirectaccesssharebase-orig-no.c
./DRB053-inneronly1-orig-no.c
./DRB054-inneronly2-orig-no.c
./DRB055-jacobi2d-parallel-no.c
./DRB056-jacobi2d-tile-no.c
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

nas_list=(
./BT
./CG
./EP
./FT
./IS
./LU
./MG
./SP
)

rodinia_list=(
./b+tree
./bfs
./cfd
./heartwall
./hotspot
./hotspot3D
)
}

count_lines () {
  BENCHMARK_NAME=${1}
  MULTIPLE_FILES=${2}
  LINES=0
  if [ "$MULTIPLE_FILES" = false ] ; then
    LINES=$(wc -l < ${BENCHMARK_NAME})
  else
    cd ${BENCHMARK_NAME}
    LIST=$(find . -name "*.c")
    cd ${SCRIPTS}
    for i in ${LIST[@]}; do
      BENCH_LINES=$(wc -l < "${BENCHMARK_NAME}/$i")
      LINES=$(( $BENCH_LINES + $LINES ))
    done

    cd ${BENCHMARK_NAME}
    LIST=$(find . -name "*.h")
    cd ${SCRIPTS}
    for i in ${LIST[@]}; do
      BENCH_LINES=$(wc -l < "${BENCHMARK_NAME}/$i")
      LINES=$(( $BENCH_LINES + $LINES ))
    done

    cd ${BENCHMARK_NAME}
    LIST=$(find . -name "*.cpp")
    cd ${SCRIPTS}
    for i in ${LIST[@]}; do
      BENCH_LINES=$(wc -l < "${BENCHMARK_NAME}/$i")
      LINES=$(( $BENCH_LINES + $LINES ))
    done

    cd ${BENCHMARK_NAME}
    LIST=$(find . -name "*.hpp")
    cd ${SCRIPTS}
    for i in ${LIST[@]}; do
      BENCH_LINES=$(wc -l < "${BENCHMARK_NAME}/$i")
      LINES=$(( $BENCH_LINES + $LINES ))
    done
  fi
}

count_loops () {
  BENCHMARK_NAME=${1}
  MULTIPLE_FILES=${2}
  NEGATIVE_LOOPS=0
  POSITIVE_LOOPS=0
  LOOPS=0
  if [ "$MULTIPLE_FILES" = false ] ; then
    LOOPS=$(grep "\"loop - object id " < "${BENCHMARK_NAME}.json" | wc -l)
    NEGATIVE_LOOPS=$(grep "\"pragma type\":\"NULL\"" < "${BENCHMARK_NAME}.json" | wc -l)
  else
    echo "-->> ${BENCHMARK_NAME}"
    cd ${BENCHMARK_NAME}
    LIST=$(find . -name "*.json")
    cd ${SCRIPTS}
    for i in ${LIST[@]}; do
      BENCH_LOOPS=$(grep "\"loop - object id " < "${BENCHMARK_NAME}/$i" | wc -l)
      BENCH_NEGATIVE_LOOPS=$(grep "\"pragma type\":\"NULL\"" < "${BENCHMARK_NAME}/$i" | wc -l)

      LOOPS=$(( $BENCH_LOOPS + $LOOPS ))
      NEGATIVE_LOOPS=$(( $BENCH_NEGATIVE_LOOPS + $NEGATIVE_LOOPS ))
    done
  fi
  POSITIVE_LOOPS=$(( $LOOPS - $NEGATIVE_LOOPS))
}

process_dataracebench () {
  cd "${TOPDIR}/benchmarks/${DIRECTORY}/dataracebench"
  DATARACEBENCHDIR=$(pwd)
  cd ${SCRIPTS}
  for f in ${dataracebench_micro_list[@]}; do 
    count_lines "${DATARACEBENCHDIR}/${f}" false
    echo "${f},${LINES}" &>> ${SCRIPTS}/number_of_lines.csv 

    count_loops "${DATARACEBENCHDIR}/${f}" false
    echo "${f},${LOOPS}" &>> ${SCRIPTS}/number_of_loops.csv 
    echo "${f},${LOOPS},${POSITIVE_LOOPS},${NEGATIVE_LOOPS}" &>> ${SCRIPTS}/number_of_loops_per_type.csv
  done	

  HEADERS_LINES=0
  count_lines "${DATARACEBENCHDIR}/utilities/polybench.c" false
  HEADERS_LINES=$(( 10#$HEADERS_LINES + 10#$LINES ))
  
  HEADERS_LOOPS=0
  HEADERS_NEGATIVE_LOOPS=0
  HEADERS_POSITIVE_LOOPS=0
  count_loops "${DATARACEBENCHDIR}/utilities/polybench.c" false
  HEADERS_LOOPS=$(( 10#$HEADERS_LOOPS + 10#$LOOPS ))
  HEADERS_NEGATIVE_LOOPS=$(( 10#$HEADERS_NEGATIVE_LOOPS + 10#$NEGATIVE_LOOPS ))
  HEADERS_POSITIVE_LOOPS=$(( 10#$HEADERS_POSITIVE_LOOPS + 10#$POSITIVE_LOOPS ))

  for f in ${dataracebench_poly_list[@]}; do
    count_lines "${DATARACEBENCHDIR}/${f}" false
    SUM=$((10#$HEADERS_LINES + 10#$LINES))
    echo "${f},${SUM}" &>> ${SCRIPTS}/number_of_lines.csv

    count_loops "${DATARACEBENCHDIR}/${f}" false
    LOOPS_2=$((10#$HEADERS_LOOPS + 10#$LOOPS))
    POSITIVE_LOOPS_2=$(( 10#$POSITIVE_LOOPS + 10#$HEADERS_POSITIVE_LOOPS))
    NEGATIVE_LOOPS_2=$(( 10#$NEGATIVE_LOOPS + 10#$HEADERS_NEGATIVE_LOOPS))
    echo "${f},${LOOPS_2},${POSITIVE_LOOPS_2},${NEGATIVE_LOOPS_2}" &>> ${SCRIPTS}/number_of_loops_per_type.csv
    echo "${f},${LOOPS_2}" &>> ${SCRIPTS}/number_of_loops.csv
  done
}

process_nas () {
  cd "${TOPDIR}/benchmarks/${DIRECTORY}/NPB3.0-omp-c"
  NASDIR=$(pwd)
  cd ${SCRIPTS}
  HEADERS_LINES=0
  count_lines "${NASDIR}/common" true
  HEADERS_LINES=$(( 10#$HEADERS_LINES + 10#$LINES ))
  
  HEADERS_LOOPS=0
  HEADERS_NEGATIVE_LOOPS=0
  HEADERS_POSITIVE_LOOPS=0
  count_loops "${NASDIR}/common" true
  HEADERS_LOOPS=$(( 10#$HEADERS_LOOPS + 10#$LOOPS ))
  HEADERS_NEGATIVE_LOOPS=$(( 10#$HEADERS_NEGATIVE_LOOPS + 10#$NEGATIVE_LOOPS ))
  HEADERS_POSITIVE_LOOPS=$(( 10#$HEADERS_POSITIVE_LOOPS + 10#$POSITIVE_LOOPS ))
  #echo "COMMON = $HEADERS_LOOPS"

  for f in ${nas_list[@]}; do
    count_lines "${NASDIR}/${f}" true
    SUM=$((10#$HEADERS_LINES + 10#$LINES))
    echo "${f},${SUM}" &>> ${SCRIPTS}/number_of_lines.csv

    count_loops "${NASDIR}/${f}" true
    POSITIVE_LOOPS_2=$(( 10#$POSITIVE_LOOPS + 10#$HEADERS_POSITIVE_LOOPS))
    NEGATIVE_LOOPS_2=$(( 10#$NEGATIVE_LOOPS + 10#$HEADERS_NEGATIVE_LOOPS))
    LOOPS_2=$((10#$HEADERS_LOOPS + 10#$LOOPS))
    echo "${f},${LOOPS_2},${POSITIVE_LOOPS_2},${NEGATIVE_LOOPS_2}" &>> ${SCRIPTS}/number_of_loops_per_type.csv
    echo "${f},${LOOPS_2}" &>> ${SCRIPTS}/number_of_loops.csv
  done
}

process_rodinia () {
  cd "${TOPDIR}/benchmarks/${DIRECTORY}/rodinia_3.1/openmp"
  RODINIADIR=$(pwd)
  cd ${SCRIPTS}

  for f in ${rodinia_list[@]}; do
    count_lines "${RODINIADIR}/${f}" true
    echo "${f},${LINES}" &>> ${SCRIPTS}/number_of_lines.csv

    count_loops "${RODINIADIR}/${f}" true
    LOOPS_2=$(( 10#$LOOPS ))
    POSITIVE_LOOPS_2=$(( 10#$POSITIVE_LOOPS ))
    NEGATIVE_LOOPS_2=$(( 10#$NEGATIVE_LOOPS ))
    echo "${f},${LOOPS_2},${POSITIVE_LOOPS_2},${NEGATIVE_LOOPS_2}" &>> ${SCRIPTS}/number_of_loops_per_type.csv
    echo "${f},${LOOPS_2}" &>> ${SCRIPTS}/number_of_loops.csv
  done
}

# Collect statistics using the following directory:
DIRECTORY="reference_cpu_threading"
if [ -f "${SCRIPTS}/number_of_lines.csv" ]; then
  rm ${SCRIPTS}/number_of_lines.csv
fi
if [ -f "${SCRIPTS}/number_of_loops.csv" ]; then
  rm ${SCRIPTS}/number_of_loops.csv
fi
if [ -f "${SCRIPTS}/number_of_loops_per_type.csv" ]; then
  rm ${SCRIPTS}/number_of_loops_per_type.csv
fi
echo "benchmark,lines" &>  ${SCRIPTS}/number_of_lines.csv
echo "benchmark,loops" &>  ${SCRIPTS}/number_of_loops.csv
echo "benchmark,loops,positive_loops,negative_loops" &>  ${SCRIPTS}/number_of_loops_per_type.csv

create_Lists
process_dataracebench
process_nas
process_rodinia

mv ${SCRIPTS}/number_of_lines.csv ${SCRIPTS}/reports/number_of_lines.csv
mv ${SCRIPTS}/number_of_loops.csv ${SCRIPTS}/reports/number_of_loops.csv
mv ${SCRIPTS}/number_of_loops_per_type.csv ${SCRIPTS}/reports/number_of_loops_per_type.csv

if [ "$(docker ps -q -f name=pythonScriptsCont)" ]; then
  docker stop pythonScriptsCont
  docker container rm pythonScriptsCont
fi

cd "${SCRIPTS}"

docker run -t -d --name pythonScriptsCont -v $(pwd):/root gleisonsdm/pythoncharts:latest

docker exec -it pythonScriptsCont python /usr/src/PYSCRIPTS/scripts/reporting/number_of_benchmarks_per_lines_of_code.py reports/number_of_lines.csv

docker exec -it pythonScriptsCont python /usr/src/PYSCRIPTS/scripts/reporting/number_of_benchmarks_per_loops.py reports/number_of_loops_per_type.csv

docker stop pythonScriptsCont

docker container rm pythonScriptsCont

rm -r .cache/
mv ${SCRIPTS}/num_benchmarks_lines_of_code.png ${SCRIPTS}/reports/images/num_benchmarks_lines_of_code.png
mv ${SCRIPTS}/num_benchmarks_loops.png ${SCRIPTS}/reports/images/num_benchmarks_loops.png
