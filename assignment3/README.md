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
The binary file is located in the */bin* folder, and can be executed with the following code snippet:
```
./bin/stack
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
This assignment is not done. It currently works on the LL grammar of assignment 1. 


## LL Grammar Assignment 3
```
<judge> ::= <expr> ':' <type>

<expr> ::= <lvar> | <fexpr> <expr1>
<lvar> ::= any variable name that starts with lowercase letter

<expr1> ::= <fexpr> <expr1> | emptystring
<fexpr> ::= <parexpr> | '\'<lvar> '^' <type> <fexpr>
<uvar> ::= any variable name that starts with uppercase letter


<type> ::= <ftype> <type1>
<type1> ::= <ftype> '->' <type1> | emptystring
<ftype> ::= <partype> | ...
<partype> ::= <uvar> | '('<type>')'

---
<expr> ::= <fexpr> <expr1>
<expr1> ::= <fexpr> <expr1> | emptystring
<fexpr> ::= <parexpr> | '\'<var> <fexpr>
<parexpr> ::= <var> | '('<expr>')'
```