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
#include "../include/tree.h"

class parser{
    public:
        parser();
        ~parser() {delete parseTree;};
        // Adds a token to the list according to inputChar
        tokenId tokenSwitch(const char inputChar) const;

        // Tokenizes the given string 
        void stringTokenizer(const std::string input);

        // Expression
        void expr(tokenList & list, node* & walker) const;

        // Expression'
        void expr1(tokenList & list, node* & walker) const;

        // Function expression
        void lambdaExpr(tokenList & list, node* & walker) const;

        // Parantheses expression
        void varExpr(tokenList & list, node* & walker) const;

        // Prints the expression
        void printExpression(const std::string input, tokenList & list);

    private:
        int row = 1, col = 1;
        tree* parseTree;
        node* begin;
};

#endif