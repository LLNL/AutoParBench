# AutoParBench

A benchmark framework to evaluate compilers and tools designed to automatically insert OpenMP directives. The goal is to generate actional information (bug reports and feature requests) for compiler and tool developers. We also want to drive the research for automatic parallelization using OpenMP and make OpenMP more declarative to reduce the burdens on OpenMP users.

## Repository structure

This repository contains the following content:

* benchmarks
  * Autopar
  * original
  * Cetus
  * Dawncc
  * ICC_Cost
  * ICC_Full
  * ICC_Simd
  * original
  * reference_cpu_simd
  * reference_cpu_threading
  * reference_gpu_target
  * sequential
* scripts
  * Dockerfiles
    * Cetus
    *  DataRaceDetectionTools
      * Romp 
    * DawnCC
    * OMPExtractor
    * PythonCharts
    * Rose
    * ThreadSanitizer
    * Traco
  * bashScripts
  * reporting
* tools
  * EquivalenceChecker
  * ICCOptReportParser
  * OpenMPExtractor
  * PragmaRemover
  
 ## Running the framweork
  
On the top level directory of this repository, please, type the following commands:
 
 ```bash
   cd scripts/bashScripts
   sudo ./run.sh
 ```
 
  ## Checking the results

This repository has a tool evaluation dashboard, it can be access using the link [Tool Evaluation Dashboard](https://github.com/gleisonsdm/AutoParBench/blob/master/reports/Tool-Evaluation-Dashboard.md).
