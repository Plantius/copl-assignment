# CoPL Assignments

A parser written in C++ for the untyped $\lambda$-calculus.

## Description


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

## TODO
* <del> Constructing LL grammar
* <del> Parser
   * <del> Adding tokenization
   * Adding the four parse functions
   * Adding syntax checker   
* Generalizing coding style
* Adding parser output

## LL Grammar
```
<expr> ::= <fexpr> <expr1>
<expr1> ::= <fexpr> <expr1> | emptystring
<fexpr> ::= <parexpr> | '\'<var> <fexpr>
<parexpr> ::= <var> | '('<expr>')'
```