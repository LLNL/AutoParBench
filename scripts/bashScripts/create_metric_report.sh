#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set -e

set_environment() {
# Step 1: Create a header to the metric report
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd "${THIS}"
ANALYZE_AUTOPAR=true
ANALYZE_DAWNCC=true
ANALYZE_ICC_COST=true
ANALYZE_ICC_NOCOST=true
ANALYZE_ICC_SIMD_NOCOST=true
ANALYZE_CETUS=true
if [ -f "${THIS}/reports/Metrics-Report.md" ]; then
  rm "${THIS}/reports/Metrics-Report.md"
fi

}

create_metric_header() {
echo "# Metric report" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "## Evaluation platform" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "Intel(R) Xeon(R) CPU E5-2686 v4" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
}

calculate_metrics() {
  # Step 2: Collect statistcs
  TP=$(grep -c "TP" ${THIS}/reports/report/$1 || true)
  TN=$(grep -c "TN" ${THIS}/reports/report/$1 || true)
  FP=$(grep -c "FP" ${THIS}/reports/report/$1 || true)
  FN=$(grep -c "FN" ${THIS}/reports/report/$1 || true)
  DP=$(grep -c "DP" ${THIS}/reports/report/$1 || true)
  NF=$(grep -c "N/A" ${THIS}/reports/report/$1 || true)
  LOOPS=$(wc -l < ${THIS}/reports/report/$1)

  # Step 3: Calculate the metrics
  if [ "$TP" != 0 ]; then
    PRECISION=$(echo "scale=8; ($TP / ($TP + $FP))" | bc -l)
  else
    PRECISION=$(echo "0.00000000")
  fi
  if [ "$TP" != 0 ]; then
    RECALL=$(echo "scale=8; ($TP / ($TP + $FN))" | bc -l)
  else
    RECALL=$(echo "0.00000000")
  fi
  ACCURACY=$(echo "scale=8; (($TP + $TN) / ($TP + $FP + $TN + $FN))" | bc -l)
  DIV=$(echo "scale=8; (${PRECISION} + ${RECALL})" | bc -l)
  if [ "${DIV}" != "0" ] ; then
    F1=$(echo "scale=8; ((2 * $PRECISION * $RECALL) / ($PRECISION + $RECALL))" | bc -l)
  else
    F1=".00000000"
  fi

  ARRAY_METRICS=(0$PRECISION 0$RECALL 0$ACCURACY 0$F1)
  ARRAY_STATS=($TP $TN $FP $FN $NF $DP)
}

create_metric_report() {
# Step 5: Report the results with calculated metrics
echo "## Metric report ${1}" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md

LABEL="Different Parallelization"
echo " TOOL | Precision | Recall | Accuracy | F1 Score | True Positive | True Negative | False Positive | False Negative | Eliminated Loops | $LABEL " &>> ${THIS}/reports/Metrics-Report.md
echo " --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | ---" &>> ${THIS}/reports/Metrics-Report.md

if [ "$ANALYZE_AUTOPAR" = true ] ; then
  calculate_metrics report_Autopar${2}.txt
  echo " Autopar | ${ARRAY_METRICS[0]} | ${ARRAY_METRICS[1]} | ${ARRAY_METRICS[2]} | ${ARRAY_METRICS[3]} | ${ARRAY_STATS[0]} | ${ARRAY_STATS[1]} | ${ARRAY_STATS[2]} | ${ARRAY_STATS[3]} | ${ARRAY_STATS[4]} | ${ARRAY_STATS[5]} | " &>> ${THIS}/reports/Metrics-Report.md
fi

if [ "$ANALYZE_DAWNCC" = true ] ; then
  calculate_metrics report_Dawncc${2}.txt
  echo " Dawnc | ${ARRAY_METRICS[0]} | ${ARRAY_METRICS[1]} | ${ARRAY_METRICS[2]} | ${ARRAY_METRICS[3]} | ${ARRAY_STATS[0]} | ${ARRAY_STATS[1]} | ${ARRAY_STATS[2]} | ${ARRAY_STATS[3]} | ${ARRAY_STATS[4]} |  ${ARRAY_STATS[5]} | " &>> ${THIS}/reports/Metrics-Report.md
fi

if [ "$ANALYZE_ICC_COST" = true ] ; then
  calculate_metrics report_ICC_Cost${2}.txt
  echo " ICC Cost | ${ARRAY_METRICS[0]} | ${ARRAY_METRICS[1]} | ${ARRAY_METRICS[2]} | ${ARRAY_METRICS[3]} | ${ARRAY_STATS[0]} | ${ARRAY_STATS[1]} | ${ARRAY_STATS[2]} | ${ARRAY_STATS[3]} | ${ARRAY_STATS[4]} |  ${ARRAY_STATS[5]} | " &>> ${THIS}/reports/Metrics-Report.md
fi

if [ "$ANALYZE_ICC_NOCOST" = true ] ; then
  calculate_metrics report_ICC_Full${2}.txt
  echo " ICC Full | ${ARRAY_METRICS[0]} | ${ARRAY_METRICS[1]} | ${ARRAY_METRICS[2]} | ${ARRAY_METRICS[3]} | ${ARRAY_STATS[0]} | ${ARRAY_STATS[1]} | ${ARRAY_STATS[2]} | ${ARRAY_STATS[3]} | ${ARRAY_STATS[4]} |  ${ARRAY_STATS[5]} | " &>> ${THIS}/reports/Metrics-Report.md
fi

if [ "$ANALYZE_ICC_SIMD_NOCOST" = true ] ; then
  calculate_metrics report_ICC_Simd${2}.txt
  echo " ICC Simd | ${ARRAY_METRICS[0]} | ${ARRAY_METRICS[1]} | ${ARRAY_METRICS[2]} | ${ARRAY_METRICS[3]} | ${ARRAY_STATS[0]} | ${ARRAY_STATS[1]} | ${ARRAY_STATS[2]} | ${ARRAY_STATS[3]} | ${ARRAY_STATS[4]} |  ${ARRAY_STATS[5]} | " &>> ${THIS}/reports/Metrics-Report.md
fi

if [ "$ANALYZE_CETUS" = true ] ; then
  calculate_metrics report_Cetus${2}.txt
  echo " Cetus | ${ARRAY_METRICS[0]} | ${ARRAY_METRICS[1]} | ${ARRAY_METRICS[2]} | ${ARRAY_METRICS[3]} | ${ARRAY_STATS[0]} | ${ARRAY_STATS[1]} | ${ARRAY_STATS[2]} | ${ARRAY_STATS[3]} | ${ARRAY_STATS[4]} |  ${ARRAY_STATS[5]} | " &>> ${THIS}/reports/Metrics-Report.md
fi

echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
}

create_footnode() {
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "## Metrics formula" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "precision (P) = TP/(TP + FP)" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "recall (R) = TP/(TP + FN)" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "accuracy (A) = (TP+TN)/(TP+FP+TN+FN)" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "F1 score (F1) = (2 * precision * recall)/(precision + recall)" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md

echo "" &>> ${THIS}/reports/Metrics-Report.md
echo "## Tool version" &>> ${THIS}/reports/Metrics-Report.md
echo "" &>> ${THIS}/reports/Metrics-Report.md
echo " Tool | Version " &>> ${THIS}/reports/Metrics-Report.md
echo " --- | --- " &>> ${THIS}/reports/Metrics-Report.md
echo " Autopar (rose) | 0.9.10.235 " &>> ${THIS}/reports/Metrics-Report.md
echo " DawnCC (clang) | 3.7.0 " &>> ${THIS}/reports/Metrics-Report.md
echo " ICC | 19.0.4.243 " &>> ${THIS}/reports/Metrics-Report.md
echo " Cetus | 1.4.4 " &>> ${THIS}/reports/Metrics-Report.md

}

set_environment

create_metric_header

create_metric_report "" ""

ANALYZE_DAWNCC=false
ANALYZE_ICC_SIMD_NOCOST=false

create_metric_report "- Dataracebench" "_DataRaceBench"

create_metric_report "- Rodinia" "_Rodinia"

create_metric_report " - Nas Parallel Benchmarks" "_NPB"

create_footnode
