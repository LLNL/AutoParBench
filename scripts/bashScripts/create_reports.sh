#!/bin/bash
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
echo "| [Autopar Report](${DATE}/Detailed-Report-Autopar.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [Cetus Report](${DATE}/Detailed-Report-Cetus.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [Dawncc Report](${DATE}/Detailed-Report-Dawncc.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [ICC Cost Report](${DATE}/Detailed-Report-ICC_cost.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [ICC Full Report](${DATE}/Detailed-Report-ICC_Full.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "| [ICC Simd Report](${DATE}/Detailed-Report-ICC_Simd.md) |" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
echo "" &>> "${THIS}/reports/Tool-Evaluation-Dashboard.md"
}

copy_reports() {
echo "Copying Files"
# Copy Detailed Report for each tool:
cp "${THIS}/reports/Detailed-Report-Autopar.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-Cetus.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-ICC_Full.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-ICC_Cost.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-Dawncc.md" "${REPORTS_DIR}/${DATE}/."
cp "${THIS}/reports/Detailed-Report-ICC_Simd.md" "${REPORTS_DIR}/${DATE}/."

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

