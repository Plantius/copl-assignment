/**
* Implementation of the token functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* token.cc
* 04-10-2023
**/ 

#include "../include/standard.h"
#include "../include/token.h"
#include "../include/tokenId.h"
#include "../include/error.h"
using namespace std;

// Default constructor
token::token(){
    next = nullptr;
    prev = nullptr;
    id = INVALID;
    tokenChar = emptyStr;
}// default constructor


// Default constructor
token::token(const tokenId idToken, token* nextToken, token* prevToken, const std::string c){
    next = nextToken;
    prev = prevToken;
    id = idToken;
    tokenChar = c;
}// default constructor


// Deletes the list of tokens
tokenList::~tokenList(){
    clear();
}// destructor

void tokenList::clear(){
    token* temp = begin;

    while (temp != nullptr){
        temp = temp->next;
        delete begin;
        begin = temp;
        length--;
    }
    begin = nullptr;
    end = nullptr;
    index = 0;
}


// Checks if the tokenList is empty
bool tokenList::isEmpty() const{
    if (begin != nullptr){
        return false;
    }
    return true;
}// isEmpty


// Returns the length of the list
int tokenList::getLength() const{
    return length;
}// getLength


// Returns the current index
int tokenList::getIndex() const{
    return index;
}// getIndex


void tokenList::reverseList(){
    token* temp = end;
    token* walker = end;
    while(temp != nullptr){
        if(temp->id == LPAR){
            temp->id = RPAR;
            temp->tokenChar = ")";
        }else if (temp->id == RPAR){
            temp->id = LPAR;
            temp->tokenChar = "(";
        }
        walker = walker->prev;
        temp->prev = temp->next;
        temp->next = walker;
        temp = walker;
    }
    temp = end;
    end = begin;
    begin = temp;
    if (begin->id == EOL){
        addToken(EOL, "#");
        temp = begin->next;
        delete begin;
        begin = temp;
        length--;
    }else {
        addToken(EOL, "#");
    }
    

}// reverseList

// Returns the token type of the token at the given index
tokenId tokenList::peekToken(){
    token* nextToken = getToken(index);
    if (nextToken != nullptr){
        while(nextToken->next != nullptr && (nextToken->id == SPACE || nextToken->id == RPAR)){
            nextToken = nextToken->next;
            index++;
        }
        
        if(nextToken != nullptr){
            if (nextToken->id == INVALID){
                throw inputError("Token id is invalid");
            }
            return nextToken->id;
        }
    }
    return INVALID;
}// peekToken


// Consumes the current token
void tokenList::consumeToken(){
    if (index < length-1){
        index++;
    }
}// consumeToken


// Returns the token-object at the given list index
// If the index is greater then half of the list length, the
// walk is started from the end of the list, instead of the beginning
token* tokenList::getToken(const int index) const{
    token* temp = nullptr;

    if (index < 0 || index >= length){
        throw inputError("Index out of bounds");
    }

    if (index < int(length/2)){
        temp = begin;
        for(int i = 0; i < index; i++){
            if (temp != nullptr){
                temp = temp->next;
            }else {
                throw inputError("Index out of bounds");
            }   
        }
    }else {
        temp = end;
        for(int i = getLength()-1; i > index; i--){
            if (temp != nullptr){
                temp = temp->prev;
            }else {
                throw inputError("Index out of bounds");
            }
        }
    }
    return temp;
}// getToken


// Adds a token-object at the back of the tokenList
void tokenList::addToken(const tokenId id, const string tokenChar){
    if(isEmpty()){
        token* newToken = new token(id, nullptr, nullptr, tokenChar);
        if (newToken == nullptr){
            throw memoryError("Memory allocation failed");
        }
        begin = newToken;
        end = newToken;
        length++;
    }else {
        token* temp = end;
        token* newToken = new token(id, nullptr, end, tokenChar);
        if (newToken == nullptr){
            throw memoryError("Memory allocation failed");
        }
        temp->next = newToken;
        end = newToken;
        length++;
    }
}// addToken

// Adds a token-object at the back of the tokenList
bool tokenList::insertToken(const tokenId id, const string tokenChar, const int index){
    if(!isEmpty()){
        token* temp = getToken(index);

        token* newToken = new token(id, temp->next, temp, tokenChar);
        
        if (newToken == nullptr){
            throw memoryError("Memory allocation failed");
        }
        
        if (temp->next != nullptr){
            temp->next->prev = newToken;
            temp->next = newToken;

        }else {
            temp->next = newToken;
            end = newToken;
        }
        length++;

        return true;
    }else {
        addToken(id, tokenChar);
        return true;
    }

    return false;
}// addToken

// Prints the contents of tokenList to stdout
void tokenList::printList() const{
    token* temp = begin;

    while(temp != nullptr){
        cout << temp->tokenChar;
        temp = temp->next;
    }cout << endl;
}// printList

void tokenList::setIndex(const int number){
    index = number;
} // setIndex
