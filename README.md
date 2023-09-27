# CoPL Assignments

A parser written in C++ for the untyped $\lambda$-calculus.

## Description


### Installing
Execute the following code in a Unix command terminal in a location of your choice:
```
make
```

The included makefile will build the project into a binary file.

### Executing program
The binary file is located in the */bin* folder, and can be executed with the following code snippet:
```
./bin/lambda
```

## Authors

Niels Versteeg (s3322637)
Lana van Sprang (s3272192)

## TODO
* <del> Constructing LL grammar
* Parser
   * <del> Adding tokenization
   * Adding the four parse functions
   * Adding syntax checker   
* Generalizing coding style

### LL Grammar
```
<expr> ::= <fexpr> <expr1>
<expr1> ::-= <fexpr> <expr1> | emptystring
<fexpr> ::= <parexpr> | '\'<var> <fexpr>
<parexpr> ::= <var> | '('<expr>')'
```