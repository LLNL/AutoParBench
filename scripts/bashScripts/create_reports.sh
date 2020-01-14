#!/bin/bash

#//******************************************************************************************************************//
#// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
#// and Federal University of Minas Gerais
#// SPDX-License-Identifier: (BSD-3-Clause)
#//*****************************************************************************************************************//

set -e
# Set Environment
set_environment() {
THIS=$(pwd)
DATE=$(date +"%Y-%m-%d")
cd ../../reports
REPORTS_DIR=$(pwd)
cd "${THIS}"

# Remove the directory with the current date, if exists
# Then, create a new directory to receive the reports.
cd "${REPORTS_DIR}"
if [ -d "${DATE}" ]; then
  rm -r "${REPORTS_DIR}/${DATE}"
fi
mkdir "${DATE}"
cd "${THIS}"
}

generate_reports() {
#Generate all reports to be updated.
echo "Summary Report"
./create_summary_report.sh
echo "Metric Report"
./create_metric_report.sh
echo "Detailed Report"
./create_detailed_report.sh
}

generate_tool_evaluation_dashboard() {
echo "Creating Tool Evaluation Dashboard"
# Overwrite tool evaluation dashboard:
if [ -f "${THIS}/reports/Tool-Evaluation-Dashboard.md" ]; then
  rm "${THIS}/reports/Tool-Evaluation-Dashboard.md"
fi
version=$(cat "${THIS}/version.txt")
version=$(echo "scale=3; ($version + 1)" | bc -l)
echo "$version" &> "${THIS}/version.txt"

echo "# Tool Evaluation Dashboard" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "## AutoParBench version (1.0.$version)" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| Report |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| --- |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [Metric Report](${DATE}/Metrics-Report.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [Summary Report](${DATE}/Summary-Report.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [CPU Dataracebench Report](${DATE}/Detailed-Report-CPU_Dataracebench.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [CPU Nas Parallel Benchmarks](${DATE}/Detailed-Report-CPU_NPB.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [CPU Rodinia](${DATE}/Detailed-Report-CPU_Rodinia.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [CPU Vectorization](${DATE}/Detailed-Report-CPU_Vectorization.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [GPU Target](${DATE}/Detailed-Report-GPU_Target.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [Correctness Report](${DATE}/Correctness_Report.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [Data Race Report](${DATE}/DataRace_Report.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
}

copy_reports() {
echo "Copying Files"
# Copy Detailed Report for each tool:
cp "${THIS}/reports/Detailed-Report-CPU_Dataracebench.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-CPU_NPB.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-CPU_Rodinia.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-CPU_Vectorization.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-GPU_Target.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Correctness_Report.md" "${REPORTS_DIR}/${DATE}/."
if [ -f "${THIS}/reports/DataRace_Report.md" ]; then
  cp "${THIS}/reports/DataRace_Report.md" "${REPORTS_DIR}/${DATE}/."
fi

# Copy Metrics Report:
cp "${THIS}/reports/Metrics-Report.md" "${REPORTS_DIR}/${DATE}/."

# Copy Summary Report:
cp "${THIS}/reports/Summary-Report.md" "${REPORTS_DIR}/${DATE}/."

# Copy Tool Evaluation Dashboard to the correct to the Top Level directory with the reports
cp "${THIS}/reports/Tool-Evaluation-Dashboard.md" "${REPORTS_DIR}/." 
}

set_environment
generate_reports
generate_tool_evaluation_dashboard
copy_reports

