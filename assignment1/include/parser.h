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
        void expr(tokenList* tList);

        // Expression'
        void expr1(tokenList* tList);

        // Function expression
        void functionExpr(tokenList* tList);

        // Parantheses expression
        void paranthesesExpr(tokenList* tList);
};



#endif