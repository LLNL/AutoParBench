#!/bin/bash

# Creates a sequential version
bash create_sequential_versions.sh

# Generates reports to Autopar
bash create_autopar_reports.sh

# Generate reports to DawnCC
bash create_dawncc_reports.sh

# Generate reports to ICC
bash create_icc_reports.sh

# Generate JSONs to ICC
bash create_icc_jsons.sh

# Generate reports to Cetus
bash create_cetus_reports.sh

# Generate JSONs to represent source codes 
bash create_source_jsons.sh

# Generate the ground truth
#  - Manual version
#  - Then, uses ICC without threshold to find all
#    parallelizable but not profitable loops
bash create_ground_truth.sh

# Produce the reports to be used
bash create_reports.sh

