/**
* Declaration of the string parser
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* parser.h
* 05-10-2023
**/

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include "../include/token.h"

class parser{
    public:
        // Adds a token to the list according to inputChar
        void tokenSwitch(const char inputChar, tokenId & id) const;

        // Tokenizes the given string 
        void stringTokenizer(const std::string input, tokenList & list);

        // Expression
        void expr(tokenList & list) const;

        // Expression'
        void expr1(tokenList & list) const;

        // Function expression
        void lambdaExpr(tokenList & list) const;

        // Parantheses expression
        void varExpr(tokenList & list) const;

        // Prints the expression
        void printExpression(const std::string input, tokenList & list);

        void setRowcol(const int row, const int col);
    private:
        int row = 1, col = 1;
};

#endif