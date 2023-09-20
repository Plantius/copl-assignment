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
        token* front;
        token();
        token* back;

    private:
        char tokenChar;

};

class tokenList{
    public:
        tokenList();

        token* makeList();
        bool addToken();

        bool isEmpty();

    private:
    
};

void stringTokenizer(const std::string input);

#endif