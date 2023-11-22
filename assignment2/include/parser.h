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
    private:
        int row = 1, col = 1;
        tree parseTree;
        node* begin;
        
    public:
        parser(tree &parseTree) : row(1), col(1), 
               parseTree(parseTree), begin(parseTree.getBegin()) {};
        ~parser() {};
        // Adds a token to the list according to inputChar
        tokenId tokenSwitch(const char inputChar) const;

        // Tokenizes the given string 
        void stringTokenizer(const std::string input);

        // Expression
        void expr(tokenList & list) const;

        // Expression'
        void expr1(tokenList & list) const;

        // Function expression
        void lambdaExpr(tokenList & list) const;

        // Parantheses expression
        void varExpr(tokenList & list) const;

        void debugTree(const std::string filename) const;

        // Prints the expression
        void printExpression(const std::string input, tokenList & list);

    
};

#endif