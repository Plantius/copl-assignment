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
void stringTokenizer(const std::string input, tokenList* tList);

// Switch for the special characters
// switch(input[i]){
//     case '(':
//         id = lpar; 
//         if(!(tList->addToken(id, '$'))){
//             cerr << "Failed to add token to the list" << endl;
//         }
//         break;
//     case ')':
//         id = rpar;
//         if(!(tList->addToken(id, ')'))){
//             cerr << "Failed to add token to the list" << endl;
//         }
//         break;
//     case '\\':
//         id = lambda;
//         if(!(tList->addToken(id,'\\'))){
//             cerr << "Failed to add token to the list" << endl;
//         }
//         break;
//     case ' ':
//         id = space;
//         if(!(tList->addToken(id, ' '))){
//             cerr << "Failed to add token to the list" << endl;
//         }
//         break;
//     case '.': 
//         id = dot;
//         if(!(tList->addToken(id, '.'))){
//             cerr << "Failed to add token to the list" << endl;
//         }
//         break;
//     default: 
//         break;
// }

#endif