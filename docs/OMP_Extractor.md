# OpenMP Extractor

## Summary
This tool is an implementation of an external clang plugin. It can parse the source code and extract information about loops with OpenMP directives into JSON files. This information can help users and developers to easily debug and associate information to relevant code snippets inside the source file.

## Generated JSON objects
These JSON objects are a representation of the target code snippets or loops. The following fields are capturing characteristics, all of them related to the parallel code. 

### Common Features
* Id : Unique object identifier.
* File : Location: Benchmark name.
* Function : Location: Function name.
* Line : Location: Line number.
* Column : Location: Column number.
* Type : Category of parallel strategy.
* Code : String representation of code.
* Ordered : Clause 'ordered' is present.
* Parent : Enclosing code region, if any.

### Loop Features
* Offload : Target descriptors.
* Multiversioned : True if this loop has two or more versions.
* Dependences : List of object dependencies (Example: An ordered directive inside the loop).
* Induction Variable : Loop induction variable.
* Access : Lists of clauses, as private, firstprivate, etc.
* Reduction : List of reduction variables and their operands (Example: +:sum).

### Non-Loop Features
* Loop id : Loop identifier where the object is located.
* Directive Type : Identifier of the generated directive (Example: atomic, ordered, ...).

## Learning how to use this tool

A plugin able to extract OpenMP is essential to provide feedback about automatic parallelization. The following link contains a class with information teaching basic steps when using/extending this tool:

[Free Compiler Camp Classroom](http://freecompilercamp.org/openmp-extractor/)
