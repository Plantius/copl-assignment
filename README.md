# CoPL Assignments

A parser written in C++ for the untyped $\lambda$-calculus.

## Description

This project is a parser written for the untyped $\lambda$-calculus, in C++. It parses an input, checks it for syntax errors, and produces an output with left precedence, and inserted parantheses to eliminate ambiguity.

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

## TODO


## LL Grammar Assignment 1
```
<expr> ::= <fexpr> <expr1>
<expr1> ::= <fexpr> <expr1> | emptystring
<fexpr> ::= <parexpr> | '\'<var> <fexpr>
<parexpr> ::= <var> | '('<expr>')'
```