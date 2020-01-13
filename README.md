# AutoParBench

A benchmark framework to evaluate compilers and tools designed to automatically insert OpenMP directives. The goal is to generate actionable information (bug reports and feature requests) for compiler and tool developers. We also want to drive the research for automatic parallelization using OpenMP and make OpenMP more declarative to reduce the burdens on OpenMP users.

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
  
 ## Running the framework
  
On the top level directory of this repository, please, type the following commands:
 
 ```bash
   cd scripts/bashScripts
   sudo bash run.sh
 ```
 
 To run all scripts of this framework together is necessary to have ICC installed on your
 local machine. This repository provides a docker image to the other tools, however, is
 necessary to have a license of ICC. 
 
  ## Checking the results

This repository has a tool evaluation dashboard, it can be access using the link [Tool Evaluation Dashboard](https://github.com/gleisonsdm/AutoParBench/blob/master/reports/Tool-Evaluation-Dashboard.md).

  ## Tools

The built tool to support the JSON format and designed to provide facilities to users of AutoParBench are available in the following list:

 * [OMP Extractor](https://github.com/gleisonsdm/AutoParBench/blob/master/docs/OMP_Extractor.md) : A clang based tool to extract OpenMP directives to a JSON format.
 * [Pragma Remover](https://github.com/gleisonsdm/AutoParBench/blob/master/docs/PragmaRemover.md) : A C++ parser to remove OpenMP directives, providing facilities to add new samples to this benchmark suite.
 * [ICC Report Optimizer Parser](https://github.com/gleisonsdm/AutoParBench/blob/master/docs/ICCOptReportParser.md) : A parser to extract JSON representation of OpenMP objects, using the reports provided by ICC.
 * [Equivalence Checker](https://github.com/gleisonsdm/AutoParBench/blob/master/docs/EquivalenceChecker.md) : This tool can read two JSON files, one reference and the target file (generated by tools or developers), and classify loops inside the target file based at the reference. It can join two different JSON files that are describing the same source file also, details provided at the link.
 
