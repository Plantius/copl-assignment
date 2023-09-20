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


class token{
    public:
        token();
        token* next;
        token* prev;

        int id;
        char tokenChar;

};// token

class tokenList{
    public:
        tokenList();
        ~tokenList();

        bool addToken(const int id, const char tokenChar);
        bool isEmpty();

        void printList();

    private:
        token* begin;
    
};// tokenList


#endif