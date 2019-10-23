#!/bin/bash

# Set Environment
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





