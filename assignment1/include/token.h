/**
* Declaration of the token class
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* parser.h
* 05-10-2023
**/

#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "../include/tokenId.h"

class token{
    public:
        token();
        token(const tokenId id, token* next, token* prev, const std::string tokenChar);
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
        bool insertToken(const tokenId id, const std::string tokenChar, const int index);
        token* getToken(const int index) const;
        int getLength() const;
        bool isEmpty() const;
        void clear();
        
        int peekToken();
        void consumeToken();
        void printList() const;

        int getIndex() const;

    private:
        token* begin;
        token* end;
        int length;
        int index;
    
};// tokenList


#endif