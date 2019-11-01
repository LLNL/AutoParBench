# Equivalence Checker

## Summary

Equivalence checker is a C++ parser able to read and process the JSON representation of files and loops provided by AutoParBench. It can evaluate equivalent JSON files, or join two json files into one (using the parallel representation of both to improve the coverage of the JSON). This parser can provide a detailed comparison of two loops also.

This parser was tested on Ubuntu 18.04, using GCC-8. However, mirror changes maybe are necessary to run it in your local machine.

## Compilation Process

Users are able to compile this parser using a C++ compiler. The following example is using G++-8 to compile this parser.
To compile OpenMP Extractor, please, follow the steps.

* Open your terminal.
* Go to the top lever directory of this repository.
* Type the following commands into your terminal:
```bash
g++-8 tools/EquivalenceChecker/equivalence_checker.h tools/EquivalenceChecker/equivalence_checker.cpp -o equivalence_checker.out
```

After using it, we encorage you to remove the executable file.

## Running Equivalence Checker

Equivalence checker contains few flags to use. The goal is to do necessary steps to provide the best baseline possible or classify parallel OpenMP code in a Loop granularity comparing a reference (manually parallelized, provided by a tool, or files containing both representations, as our ground truth). 

## Step by Step use
