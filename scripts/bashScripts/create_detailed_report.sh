#!/bin/bash

set_environment() {
# Step 1: Define flags to be used in the scripts
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
if [ -f "${THIS}/reports/Detailed-Report-${TOOL}.md" ]; then
  rm "${THIS}/reports/Detailed-Report-${TOOL}.md"
fi
}

create_detailed_header() {
TOOL=${1}
echo "# Summary report" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo "" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo "## Evaluation platform" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo "" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo "Intel(R) Xeon(R) CPU E5-2686 v4" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo "" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
}

create_detailed_report() {
TOOL=${1}
REFERENCE=${2}

create_detailed_header "${TOOL}"
echo "### ${TOOL} Report" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo "" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo " ID | Filename | Original | Sequential | Reference | Loop ID | Line Number | ${TOOL} | Output | JSON | Ground Truth " &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo " --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- " &>> ${THIS}/reports/Detailed-Report-${TOOL}.md

COUNTER=1
while IFS= read -r index
do
  filename=${index%%|*}
  filename=${filename/.json/}
  filename=${filename/.\/CPU\//}
  filename=${filename/.\/GPU\//}
  filename=${filename/.\/CPU_VECTORIZATION\//}
  filename=${filename// /}

  info="${index#*|}"

  link_orig="[Original](https://github.com/gleisonsdm/AutoParBench/tree/master/benchmarks/original/${filename})"
  link_seq="[Sequential](https://github.com/gleisonsdm/AutoParBench/tree/master/benchmarks/sequential/${filename})"
  link_ref="[Reference](https://github.com/gleisonsdm/AutoParBench/tree/master/benchmarks/${REFERENCE}/${filename/.c/.c.json})"

  link_tool="[out](https://github.com/gleisonsdm/AutoParBench/tree/master/benchmarks/${TOOL}/${filename})"
  link_tool_json="[json](https://github.com/gleisonsdm/AutoParBench/tree/master/benchmarks/${TOOL}/${filename/.c/.c.json})"

  link_ground_truth="(https://github.com/gleisonsdm/AutoParBench/tree/master/benchmarks/original/${filename})"

  row_data="${index#*|}"
  row_data="${row_data/ | YES/}"
  row_data="${row_data/ | NO/}"
  row_ground_truth="${index##*|}"
  row_ground_truth="${row_ground_truth/ /}"
  
  echo "${COUNTER} | ${filename/.\//} | ${link_orig} | ${link_seq} | ${link_ref} |${row_data} | ${link_tool} | ${link_tool_json} | [${row_ground_truth}]${link_ground_truth}" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md

  COUNTER=$((COUNTER+1))
done < "${THIS}/reports/detailed/detailed_report_${TOOL}.txt"

echo "" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
echo "" &>> ${THIS}/reports/Detailed-Report-${TOOL}.md
}


set_environment

create_detailed_header

create_detailed_report "Autopar" "reference_cpu_threading"
create_detailed_report "Cetus" "reference_cpu_threading"
create_detailed_report "ICC_Full" "reference_cpu_threading"
create_detailed_report "ICC_Cost" "reference_cpu_threading"

create_detailed_report "ICC_Simd" "reference_cpu_simd"

create_detailed_report "Dawncc" "reference_gpu_target"
