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
#include "../include/standard.h"

// Token class
class token{
    public:
        token() : next(nullptr), prev(nullptr), 
                  id(INVALID), tokenChar(emptyStr) {};
        token(token* next, token* prev, const tokenId newId, const std::string newTokenChar) : 
              next(next), prev(prev), id(newId), tokenChar(newTokenChar) {};
        
        token(const token&) = delete;
        token(token&&) = delete;
        token& operator=(const token&) = delete;
        token& operator=(token&&) = delete;
    	~token() {delete[] next; delete[] prev;};

        token* next;
        token* prev;

        tokenId id;
        std::string tokenChar;

};// token

// Token list class
class tokenList{
    public:
        tokenList() : begin(nullptr), end(nullptr), length(0), index(0) {};
        ~tokenList() {clear();};

        void deleteToken(const int index) const;
        void reverseList();

        // Adds a token to the list
        void addToken(const tokenId id, const std::string tokenChar);
        
        // Inserts a token in the list
        bool insertToken(const tokenId id, const std::string tokenChar, const int index);
        
        // Returns the type of the token at the current index
        tokenId peekToken();
        
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

        token* getBegin() const {return this->begin;};

        void setIndex(const int number);

    private:
        token* begin;
        token* end;
        int length;
        int index;
    
};// tokenList


#endif