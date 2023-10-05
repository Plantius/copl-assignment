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
        parser(const int row, const int col);
        // Adds a token to the list according to inputChar
        void tokenSwitch(const char inputChar, tokenId & id);

        // Tokenizes the given string 
        void stringTokenizer(const std::string input, tokenList & list);

        // Expression
        void expr(tokenList & list);

        // Expression'
        void expr1(tokenList & list);

        // Function expression
        void lambdaExpr(tokenList & list);

        // Parantheses expression
        void varExpr(tokenList & list);

        // Prints the expression
        void printExpression(const std::string input, tokenList & list);

        int getRow(); // Returns the last read row
        int getCol(); // Returns the last read column 

        void setVar(const int row, const int col);

    private:
        int row, col;
};

#endif