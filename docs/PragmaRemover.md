# Pragma Remover

## Summary

Pragma Remover s a C++ parser that can parser a C / C++ program and remove OpenMP pragmas and their clauses.
This parser was tested on Ubuntu 18.04, using GCC-8. However, mirror changes maybe are necessary to run it in your local machine.

## Compilation Process

Users are able to compile this parser using a C++ compiler. The following example is using G++-8 to compile this parser. To compile Pragma Remover, please, follow the steps:

* Open your terminal.
* Go to the top lever directory of this repository.
* Type the following commands into your terminal:

```sh
g++-8 tools/PragmaRemover/pragmaRemover.cpp -o pragmaRemover.out
```

After using it, we encorage you to remove the executable file.

## Execution

To execute the parser and strip off all OpenMP directives, it is just necessary to pass the target source code as a parameter. The
following command-line reflects the use of the analysis:

```sh
./pragmaRemover.out test.c
```

Afther runnning it, the file test.c does not contains OpenMP directives.
