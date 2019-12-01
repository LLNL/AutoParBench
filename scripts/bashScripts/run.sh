#!/bin/bash

# Creates a sequential version
sudo bash create_sequential_versions.sh

# Generates reports to Autopar
sudo bash create_autopar_reports.sh

# Generate reports to DawnCC
sudo bash create_dawncc_reports.sh

# Generate reports to ICC
sudo bash create_icc_reports.sh

# Generate JSONs to ICC
sudo bash create_icc_jsons.sh

# Generate reports to Cetus
sudo bash create_cetus_reports.sh

# Generate JSONs to represent source codes 
sudo bash create_source_jsons.sh

# Generate the ground truth
#  - Manual version
#  - Then, uses ICC without threshold to find all
#    parallelizable but not profitable loops
#bash create_ground_truth.sh

bash collect_classification_files.sh

# Produce the reports to be used
sudo bash create_reports.sh

