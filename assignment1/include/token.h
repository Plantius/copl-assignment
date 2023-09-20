/**
* Declaration of the string parser
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* parser.h
* 15-09-2023
**/

#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

const enum tokenId {lpar, rpar, lambda, var, space, dot};

class token{
    public:
        token();
        token* next;
        token* prev;

    private:
        int id;
        char tokenChar;

};

class tokenList{
    public:
        tokenList();
        ~tokenList();

        bool addToken();
        bool isEmpty();

    private:
        token* begin;
    
};


#endif