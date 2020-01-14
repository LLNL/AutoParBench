#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//
set -e

# Step 1: Setup the environment
set_environment() {
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd "${THIS}"

if [ -f "${THIS}/equivalence_checker.out" ]; then
  rm ${THIS}/equivalence_checker.out
fi
g++-8 ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.h ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.cpp -o ${THIS}/equivalence_checker.out
chmod +x ${THIS}/equivalence_checker.out
if [ -f "${THIS}/logs/checker.log" ]; then
  rm "${THIS}/logs/checker.log"
fi

ANALYZE_AUTOPAR=true
ANALYZE_DAWNCC=true
ANALYZE_ICC_COST=true
ANALYZE_ICC_NOCOST=true
ANALYZE_ICC_SIMD_NOCOST=true
ANALYZE_BASELINE=true
ANALYZE_CETUS=true
}

# Step 2: Find and collect reference files
link_jsons() {
cd "${SCRIPTS}/../benchmarks/"
BENCHMARKS=$(pwd)
cd "${THIS}"

#Collect jsons for all benchmarks
BASELINE_JSON=$(find "${BENCHMARKS}/reference_cpu_threading" -name "*.json" | sort)
AUTOPAR_JSON=$(find "${BENCHMARKS}/Autopar" -name "*.json" | sort)
DAWNCC_JSON=$(find "${BENCHMARKS}/Dawncc" -name "*.json" | sort)
ICC_NOCOST_JSON=$(find "${BENCHMARKS}/ICC_Full" -name "*.json" | sort)
ICC_SIMD_NOCOST_JSON=$(find "${BENCHMARKS}/ICC_Simd" -name "*.json" | sort)
ICC_COST_JSON=$(find "${BENCHMARKS}/ICC_Cost" -name "*.json" | sort)
CETUS_JSON=$(find "${BENCHMARKS}/Cetus" -name "*.json" | sort)

#Collect jsons for dataracebench
DATARACEBENCH_BASELINE_JSON=$(find "${BENCHMARKS}/reference_cpu_threading/dataracebench" -name "*.json" | sort)
DATARACEBENCH_AUTOPAR_JSON=$(find "${BENCHMARKS}/Autopar/dataracebench" -name "*.json" | sort)
DATARACEBENCH_ICC_NOCOST_JSON=$(find "${BENCHMARKS}/ICC_Full/dataracebench" -name "*.json" | sort)
DATARACEBENCH_ICC_COST_JSON=$(find "${BENCHMARKS}/ICC_Cost/dataracebench" -name "*.json" | sort)
DATARACEBENCH_CETUS_JSON=$(find "${BENCHMARKS}/Cetus/dataracebench" -name "*.json" | sort)

#Collect jsons for rodinia
RODINIA_BASELINE_JSON=$(find "${BENCHMARKS}/reference_cpu_threading/rodinia_3.1" -name "*.json" | sort)
RODINIA_AUTOPAR_JSON=$(find "${BENCHMARKS}/Autopar/rodinia_3.1" -name "*.json" | sort)
RODINIA_ICC_NOCOST_JSON=$(find "${BENCHMARKS}/ICC_Full/rodinia_3.1" -name "*.json" | sort)
RODINIA_ICC_COST_JSON=$(find "${BENCHMARKS}/ICC_Cost/rodinia_3.1" -name "*.json" | sort)
RODINIA_CETUS_JSON=$(find "${BENCHMARKS}/Cetus/rodinia_3.1" -name "*.json" | sort)

#Collect jsons for npb
NPB_BASELINE_JSON=$(find "${BENCHMARKS}/reference_cpu_threading/NPB3.0-omp-c" -name "*.json" | sort)
NPB_AUTOPAR_JSON=$(find "${BENCHMARKS}/Autopar/NPB3.0-omp-c" -name "*.json" | sort)
NPB_ICC_NOCOST_JSON=$(find "${BENCHMARKS}/ICC_Full/NPB3.0-omp-c" -name "*.json" | sort)
NPB_ICC_COST_JSON=$(find "${BENCHMARKS}/ICC_Cost/NPB3.0-omp-c" -name "*.json" | sort)
NPB_CETUS_JSON=$(find "${BENCHMARKS}/Cetus/NPB3.0-omp-c" -name "*.json" | sort)
}

# Step 3: Collect data of each json file
# This script just can calculate metrics if the tool provided a reference.
collect_data() {
REF_GROUP_DIR=${1}
TOOL_DIR=${2}
NAME=${3}
TOOL_JSONS=${4}
GROUP=${5}

echo "*** NAME = ${NAME}***"

if [ -f "${THIS}/reports/report/report_${NAME}.txt" ]; then
  rm "${THIS}/reports/report/report_${NAME}.txt"
fi
if [ -f "${THIS}/reports/detailed/detailed_report_${NAME}.txt" ]; then
  rm "${THIS}/reports/detailed/detailed_report_${NAME}.txt"
fi
if [ -f "${THIS}/reports/summary/summary_${NAME}.txt" ]; then
  rm "${THIS}/reports/summary/summary_${NAME}.txt"
fi

for f in ${TOOL_JSONS}; do
  reference="${f/${TOOL_DIR}/${REF_GROUP_DIR}}"
  reference_file="${reference//*\/}"
  reference_dir="${reference%/*}"
  reference="${reference_dir}/${reference_file}"

  file="${reference_dir}/${reference_file}"
  file="${file/${REF_GROUP_DIR}/ }"
  file="${file#* }"
  file="./${GROUP}${file}"
#  file="${reference_dir}/${reference_file}"

#  echo "${file}"
  cd "${THIS}"
  LOG=$(./equivalence_checker.out -check "${reference}" "${f}")
  LOG_DETAIL="${THIS}/tmp.txt"
  ./equivalence_checker.out -check-detailed "${reference}" "${f}" &> "${LOG_DETAIL}"
  ./equivalence_checker.out -check "${reference}" "${f}" >> /dev/null
  if [[ $? -ne 0 ]];
  then
     echo "Error at: $f"
     exit 0;
  fi
  if [[ -z "${LOG}" ]]; then
    continue;
  fi
  echo "${f} -> ${LOG}" &>> "${THIS}/logs/checker.log"

  COUNTER=001
  COUNT_TP=0
  COUNT_TN=0
  COUNT_FP=0
  COUNT_FN=0
  COUNT_NF=0
  COUNT_DP=0
  for l in ${LOG}; do
    COUNTER=$(printf %04d $COUNTER)
    echo "${l}" &>> "${THIS}/reports/report/report_${NAME}.txt"
    if [ "${l}" = "TP" ] ; then
      COUNT_TP=$((${COUNT_TP} + 1));
    fi
    if [ "${l}" = "TN" ] ; then
      COUNT_TN=$((${COUNT_TN} + 1));
    fi
    if [ "${l}" = "FP" ] ; then
      COUNT_FP=$((${COUNT_FP} + 1));
    fi
    if [ "${l}" = "FN" ] ; then
      COUNT_FN=$((${COUNT_FN} + 1));
    fi
    if [ "${l}" = "DP" ] ; then
      COUNT_DP=$((${COUNT_DP} + 1));
    fi
    if [ "${l}" = "N/A" ] ; then
      COUNT_NF=$((${COUNT_NF} + 1));
    fi
    COUNTER=$((10#$COUNTER + 1))
  done

  COUNTER=1
  while IFS= read -r index
  do
    echo "${file} | ${COUNTER} | ${index}" &>> "${THIS}/reports/detailed/detailed_report_${NAME}.txt"
    COUNTER=$((COUNTER+1))
  done < "${LOG_DETAIL}"
  rm "${LOG_DETAIL}"

  echo "<td>${file/.json/}</td><td> ${COUNT_DP} </td><td> ${COUNT_TP} </td><td> ${COUNT_TN} </td><td> ${COUNT_FP} </td><td> ${COUNT_FN} </td><td> ${COUNT_NF} </td>" &>> "${THIS}/reports/summary/summary_${NAME}.txt"
done
}

clean_environment() {
  rm ${THIS}/equivalence_checker.out
}

set_environment

link_jsons

collect_data reference_cpu_threading reference_cpu_threading Ground_Truth "${BASELINE_JSON[@]}" "CPU"
collect_data reference_cpu_threading Autopar Autopar "${AUTOPAR_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Cost ICC_Cost "${ICC_COST_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Full ICC_Full "${ICC_NOCOST_JSON[@]}" "CPU"
collect_data reference_cpu_threading Cetus Cetus "${CETUS_JSON[@]}" "CPU"
collect_data reference_gpu_target Dawncc Dawncc "${DAWNCC_JSON[@]}" "GPU"
collect_data reference_cpu_simd ICC_Simd ICC_Simd "${ICC_SIMD_NOCOST_JSON[@]}" "CPU_VECTORIZATION"


ANALYZE_DAWNCC=false
ANALYZE_ICC_SIMD_NOCOST=false
collect_data reference_cpu_threading reference_cpu_threading Ground_Truth_DataRaceBench "${DATARACEBENCH_BASELINE_JSON[@]}" "CPU"
collect_data reference_cpu_threading Autopar Autopar_DataRaceBench "${DATARACEBENCH_AUTOPAR_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Cost ICC_Cost_DataRaceBench "${DATARACEBENCH_ICC_COST_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Full ICC_Full_DataRaceBench "${DATARACEBENCH_ICC_NOCOST_JSON[@]}" "CPU"
collect_data reference_cpu_threading Cetus Cetus_DataRaceBench "${DATARACEBENCH_CETUS_JSON[@]}" "CPU"

ANALYZE_DAWNCC=false
ANALYZE_ICC_SIMD_NOCOST=false
collect_data reference_cpu_threading reference_cpu_threading Ground_Truth_Rodinia "${RODINIA_BASELINE_JSON[@]}" "CPU"
collect_data reference_cpu_threading Autopar Autopar_Rodinia  "${RODINIA_AUTOPAR_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Cost ICC_Cost_Rodinia "${RODINIA_ICC_COST_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Full ICC_Full_Rodinia "${RODINIA_ICC_NOCOST_JSON[@]}" "CPU"
collect_data reference_cpu_threading Cetus Cetus_Rodinia "${RODINIA_CETUS_JSON[@]}" "CPU"

ANALYZE_DAWNCC=false
ANALYZE_ICC_SIMD_NOCOST=false
collect_data reference_cpu_threading reference_cpu_threading Ground_Truth_NPB "${NPB_BASELINE_JSON[@]}" "CPU"
collect_data reference_cpu_threading Autopar Autopar_NPB "${NPB_AUTOPAR_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Cost ICC_Cost_NPB "${NPB_ICC_COST_JSON[@]}" "CPU"
collect_data reference_cpu_threading ICC_Full ICC_Full_NPB "${NPB_ICC_NOCOST_JSON[@]}" "CPU"
collect_data reference_cpu_threading Cetus Cetus_NPB "${NPB_CETUS_JSON[@]}" "CPU"

clean_environment
exit 0;



