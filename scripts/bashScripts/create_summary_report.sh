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
if [ -f "${THIS}/reports/Summary-Report.md" ]; then
  rm "${THIS}/reports/Summary-Report.md"
fi

}

create_summary_header() {
report_id=${1}
echo "# Summary report ${report_id}" &>> ${THIS}/reports/Summary-Report.md
echo "" &>> ${THIS}/reports/Summary-Report.md
echo "## Evaluation platform" &>> ${THIS}/reports/Summary-Report.md
echo "" &>> ${THIS}/reports/Summary-Report.md
echo "Intel(R) Xeon(R) CPU E5-2686 v4" &>> ${THIS}/reports/Summary-Report.md
echo "" &>> ${THIS}/reports/Summary-Report.md
}

create_summary_report() {

echo "" &>> ${THIS}/reports/Summary-Report.md
echo "" &>> ${THIS}/reports/Summary-Report.md
echo "<table>" &>> ${THIS}/reports/Summary-Report.md
echo "<tr><th style="font-weight:bold" colspan="8"> ${1} </th></tr>" &>> ${THIS}/reports/Summary-Report.md
echo "<tr><th> ID </th><th> Filename </th><th> DP </th><th> TP </th><th> TN </th><th> FP </th><th> FN </th><th> N/A </th></tr>" &>> ${THIS}/reports/Summary-Report.md
COUNTER=1
while IFS= read -r index
do
  echo "<tr><td>${COUNTER}</td>${index/.\//}</tr>" &>> ${THIS}/reports/Summary-Report.md
  COUNTER=$((COUNTER+1))
done < "${THIS}/reports/summary/${2}"


echo "</table>" &>> ${THIS}/reports/Summary-Report.md
}

set_environment
create_summary_header

# CPU Threading 
create_summary_report "Autopar" "summary_Autopar.txt"
create_summary_report "ICC Full" "summary_ICC_Full.txt"
create_summary_report "ICC Cost" "summary_ICC_Cost.txt"
create_summary_report "Cetus" "summary_Cetus.txt"

# GPU Target
create_summary_report "Dawncc" "summary_Dawncc.txt"

# CPU Simd
create_summary_report "ICC Simd" "summary_ICC_Simd.txt"

