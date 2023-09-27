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
void tokenSwitch(const char inputChar, tokenId & id);

// Tokenizes the given string 
bool stringTokenizer(const std::string input, tokenList* tList);

// Expression
bool expr(int &index, tokenList* tList);

// Expression'
bool expr1(int &index, tokenList* tList);

// Function expression
bool functionExpr(int &index, tokenList* tList);

// Parantheses expression
bool paranthesesExpr(int &index, tokenList* tList);

#endif