# CoPL Assignments

A parser written in C++ for the untyped $\lambda$-calculus.

## Description

This project is a parser written for the untyped $\lambda$-calculus, in C++. It parses an input, checks it for syntax errors, and produces an output with left precedence, and inserted parantheses to eliminate ambiguity. The parser type checks the expressions.

## Installing
Build the project using the MakeFile:
```
make
```

The included makefile will build the project into a binary file.

### Executing program
The binary file is created in the directory of the makefile, and can be executed with the following code snippet:
```
./lambda < positives.txt
```
Or with:
```
make run
```

## Authors

Niels Versteeg (s3322637)

Lana van Sprang (s3272192)

Class: Concepts of Programming Languages
Group name: Lambda Males

## Compiler used by authors
Compiler: g++
OS: Linux
Compiler version: 11.4.0


## Defects, derivations from assignment, working
The generated output does not contain the least amount of brackets, and performing a beta-reduction does not always give the correct result.


## LL Grammar Assignment 1
```
<expr> ::= <fexpr> <expr1>
<expr1> ::= <fexpr> <expr1> | emptystring
<fexpr> ::= <parexpr> | '\'<var> <fexpr>
<parexpr> ::= <var> | '('<expr>')'
```