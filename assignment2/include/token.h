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

// Token class
class token{
    public:
        token();
        token(const tokenId newId, token* newNext, token* newPrev, const std::string newTokenChar);
        token* next;
        token* prev;

        tokenId id;
        std::string tokenChar;

};// token

// Token list class
class tokenList{
    public:
        tokenList() : begin(nullptr), end(nullptr), length(0), index(0) {};
        ~tokenList();

        // Adds a token to the list
        void addToken(const tokenId id, const std::string tokenChar);
        
        // Inserts a token in the list
        bool insertToken(const tokenId id, const std::string tokenChar, const int index);
        
        // Returns the type of the token at the current index
        int peekToken();
        
        // Consumes the current token
        void consumeToken();

        // Returns the token a the given index
        token* getToken(const int index) const;

        // Returns the current list size
        int getLength() const;
        
        // Returns the current index
        int getIndex() const;
        
        // Returns if the list is empty
        bool isEmpty() const;

        // Clears the list
        void clear();
        
        // Prints the list
        void printList() const;

    private:
        token* begin;
        token* end;
        int length;
        int index;
    
};// tokenList


#endif