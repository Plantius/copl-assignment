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
        std::string tokenChar;

};// token


class tokenList{
    public:
        tokenList();
        ~tokenList();

        bool addToken(const int id, const std::string tokenChar);
        token* getToken(const int index);
        int getLength();
        bool isEmpty();
        void clear();
        
        int peekToken(const int index);
        bool nextToken(const int id, int &index);
        void skipToken(const int id, int &index);
        void printList();

    private:
        token* begin;
        token* end;
        int length;
    
};// tokenList


#endif