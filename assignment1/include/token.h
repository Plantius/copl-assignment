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
        token* getToken(const int index);
        int getLength();
        bool isEmpty();
        
        bool compNext(const int id);
        bool skipNext(token* walker);
        token* valueNext(const int id);

        void printList();

    private:
        token* begin;
    
};// tokenList


#endif