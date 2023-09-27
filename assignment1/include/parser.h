/**
* Declaration of the string parser
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* parser.h
* 15-09-2023
**/

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include "../include/token.h"

// Checks the given tokenlist for syntax errors
bool syntaxCheck(tokenList* tList);

// Adds a token to the list according to inputChar
void tokenSwitch(const char inputChar, int & id);

// Tokenizes the given string 
bool stringTokenizer(const std::string input, tokenList* tList);

// Expression
void expr();

// Expression'
void expr1();

// Function expression
void fexpr();

// Parantheses expression
void parexpr();

#endif