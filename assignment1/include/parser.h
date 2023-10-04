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
        parser();

        bool getError();

        // Adds a token to the list according to inputChar
        void tokenSwitch(const char inputChar, tokenId & id);

        // Tokenizes the given string 
        void stringTokenizer(const std::string input, tokenList & list);

        // Expression
        void expr(tokenList & list);

        // Expression'
        void expr1(tokenList & list);

        // Function expression
        void functionExpr(tokenList & list);

        // Parantheses expression
        void paranthesesExpr(tokenList & list);

        // Prints the expression
        void printExpression(const std::string input, tokenList & list);

    private:
        bool error;
        
};

#endif