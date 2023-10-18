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
        parser();
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

        // Prints the expression
        void printExpression(const std::string input, tokenList & list);

    private:
        int row = 1, col = 1;
};

class node{
    public:
        node ();

        node* left;
        node* right;

        tokenId id;
        std::string tokenChar;
};

class tree{
    public:
        tree();
        ~tree();

        bool isEmpty() const;
        bool isOperator(const node* node) const;
        bool makeNode(const tokenId id, node* & index);
        void makeTree();
        void deleteNode() const;
        void printTree() const;


    private:
        node* begin;
};

#endif