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

// Adds a token to the list according to inputChar
void tokenSwitch(const std::string inputChar, tokenList* tList);

// Tokenizes the given string 
void stringTokenizer(const std::string input);

#endif