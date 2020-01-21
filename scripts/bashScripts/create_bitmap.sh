#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

create_bitmap () {

if test -f "${2}"; then
    rm ${2}
fi

ZOOM=5
REPEAT=$((${ZOOM} * 2))
N_ROWS=${3}

ROWS=$(wc -l < ${1})
LINES=$((${ROWS}/${N_ROWS}))
LINES_REST=$((${ROWS}%${N_ROWS}))
COLUMNS=$((${N_ROWS} - ${LINES_REST}))
[[ ${LINES_REST} = 0 ]] && LINES_REST=0 || LINES_REST=1
LINES=$((${LINES} + ${LINES_REST}))    
LINES_CHART=$(($LINES * ${REPEAT}))
COLUMNS_CHART=$((${N_ROWS} * ${REPEAT}))
echo "P2" &> ${2}
echo "${COLUMNS_CHART} ${LINES_CHART}" &>> ${2}
echo "15" &>> ${2}

COUNTER=1
line=""
sort ${1} &> ordered.txt
sed -i "s/N\/A/ZZ/g" ordered.txt
sort ordered.txt &> ordered2.txt
mv ordered2.txt ordered.txt

while read input
do
   input=${input/DP/00}
   input=${input/FN/04}
   input=${input/FP/07}
   input=${input/TN/10}
   input=${input/TP/12}
   input=${input/ZZ/15}

   for i in $(seq 1 1 ${REPEAT})
   do
     line="$line $input"
   done
   if [ "${COUNTER}" == "${N_ROWS}" ] ; then
     line="${line/ /}"
     for i in $(seq 1 1 ${REPEAT})
     do 
       echo "${line}" &>> ${2}
     done
     line=""
     COUNTER=0
   fi
   ((COUNTER++));
done < ordered.txt

if [ "${COLUMNS}" != "0" ]; then
   for i in $(seq 1 1 ${COLUMNS})
   do
     for j in $(seq 1 1 ${REPEAT})
     do
       line="$line 15"
     done
   done
   line="${line/ /}"
   for i in $(seq 1 1 ${REPEAT})
   do
     echo "${line}" &>> ${2}
   done
fi

rm ordered.txt
}

SCRIPTS=`pwd`

# Ground Truth as reference
echo "Creating for ICC Cost"
create_bitmap "${SCRIPTS}/reports/report/report_ICC_Cost.txt" "${SCRIPTS}/reports/images/report_ICC_Cost.ppm" 20
echo "Creating for Autopar"
create_bitmap "${SCRIPTS}/reports/report/report_Autopar.txt" "${SCRIPTS}/reports/images/report_Autopar.ppm" 26
echo "Creating for ICC Full"
create_bitmap "${SCRIPTS}/reports/report/report_ICC_Full.txt" "${SCRIPTS}/reports/images/report_ICC_Full.ppm" 20
echo "Creating for ICC Simd"
create_bitmap "${SCRIPTS}/reports/report/report_ICC_Simd.txt" "${SCRIPTS}/reports/images/report_ICC_Simd.ppm" 12
echo "Creating for DawnCC"
create_bitmap "${SCRIPTS}/reports/report/report_Dawncc.txt" "${SCRIPTS}/reports/images/report_Dawncc.ppm" 12
echo "Creating for Cetus"
create_bitmap "${SCRIPTS}/reports/report/report_Cetus.txt" "${SCRIPTS}/reports/images/report_Cetus.ppm" 12


