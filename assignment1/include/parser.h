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

class parser{
    public:
        // Adds a token to the list according to inputChar
        void tokenSwitch(const char inputChar, tokenId & id);

        // Tokenizes the given string 
        void stringTokenizer(const std::string input, tokenList* tList);

        // Expression
        void expr(int &index, tokenList* tList);

        // Expression'
        void expr1(int &index, tokenList* tList);

        // Function expression
        void functionExpr(int &index, tokenList* tList);

        // Parantheses expression
        void paranthesesExpr(int &index, tokenList* tList);

        // Prints the expression
        void printExpression(const std::string input, int &index, tokenList* tList);
};



#endif