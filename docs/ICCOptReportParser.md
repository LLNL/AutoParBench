# ICC Opt Report Parser

## Summary

ICC Opt Report Parser s a C++ parser able to read and process the log files provided by ICC using its automatic parallelization tool. It can creates a JSON object for each loop present in the report. This parser can provide a detailed report about what happened inside ICC afther optimizations and analysis, writing the description in a summarized object.

This parser was tested on Ubuntu 18.04, using GCC-8. However, mirror changes maybe are necessary to run it in your local machine.

## Compilation Process

Users are able to compile this parser using a C++ compiler. The following example is using G++-8 to compile this parser.
To compile ICC Opt Report Parser, please, follow the steps.

* Open your terminal.
* Go to the top lever directory of this repository.
* Type the following commands into your terminal:
```bash
g++-8 tools/ICCOptReportParser/icc_parser.h tools/ICCOptReportParser/icc_parser.cpp -o icc_parser.out
```

After using it, we encorage you to remove the executable file.

## Execution

To execute the parser and provide a JSON representation of the ".optrpt" file, it is just necessary to pass the target source code as a parameter. The following command-line reflects the use of the analysis:

./icc_parser.out test.c

Afther runnning it, the file test.c does not contains OpenMP directives.
