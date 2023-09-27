/**
* Declaration of the token class
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* parser.h
* 15-09-2023
**/

#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "../include/tokenId.h"

class token{
    public:
        token();
        token* next;
        token* prev;

        tokenId id;
        std::string tokenChar;

};// token


class tokenList{
    public:
        tokenList();
        ~tokenList();

        bool addToken(const tokenId id, const std::string tokenChar);
        token* getToken(const int index);
        int getLength();
        bool isEmpty();
        void clear();
        
        int peekToken(const int index);
        bool nextToken(const tokenId id, int &index);
        void skipToken(const tokenId id, int &index);
        void printList();

    private:
        token* begin;
        token* end;
        int length;
    
};// tokenList


#endif