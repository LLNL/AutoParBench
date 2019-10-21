#!/bin/bash
set -e 

# map directories
THIS=$(pwd)
cd ../
SCRIPTS=$(pwd)
cd "${THIS}"

# remove the output directory, if it exists
if [ -d "${SCRIPTS}/../benchmarks/baseline" ]; then
  rm -r "${SCRIPTS}/../benchmarks/baseline"
fi
mkdir "${SCRIPTS}/../benchmarks/baseline"

# Map directoires
cd "${SCRIPTS}/../benchmarks/baseline"
BASELINEDIR=$(pwd)
cd "${THIS}"

cd "${SCRIPTS}/../benchmarks/ICC_Full"
ICC_NOCOST_DIR=$(pwd)
cd "${THIS}"

cd "${SCRIPTS}/../benchmarks/reference_cpu_threading"
CPU_reference_DIR=$(pwd)
cd "${THIS}"

if [ -d "${BASELINEDIR}" ]; then
  rm -r "${BASELINEDIR}"
fi
cp -r "${CPU_reference_DIR}" "${BASELINEDIR}"

if [ -f "${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.out" ]; then
  rm "${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.out"
fi

# compile the parser to join JSON files
g++-8 ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.h ${SCRIPTS}/../tools/EquivalenceChecker/equivalence_checker.cpp -o ${THIS}/equivalence_checker.out
chmod +x ${THIS}/equivalence_checker.out

# Join the manual JSON file and ICC without threshold to find all parallelizable but not profitable loops.
for json in $(find "${CPU_reference_DIR}" -name "*.json" | sort); do
  echo ""
  echo "./equivalence_checker.out -join ${json} ${json/reference_cpu_threading/ICC_Full} ${json/reference_cpu_threading/baseline}"
  if [ -f "${json/reference_cpu_threading/ICC_Full}" ]; then
    ./equivalence_checker.out -join "${json}" "${json/reference_cpu_threading/ICC_Full}" "${json/reference_cpu_threading/baseline}"
  else
    ./equivalence_checker.out -join "${json}" "${json}" "${json/reference_cpu_threading/baseline}"
  fi
done

# remove temporary files
find "${BASELINEDIR}" -type f ! \( -name '*.json' \) -delete
rm ${THIS}/equivalence_checker.out
