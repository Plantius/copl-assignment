#include "../include/standard.h"
#include "../include/token.h"
#include "../include/tokenId.h"
using namespace std;

// Default constructor
token::token(){
    next = nullptr;
    prev = nullptr;
    id = invalid;
    tokenChar = "$";
}// default constructor


// Default constructor
tokenList::tokenList(){
    begin = nullptr;
    end = nullptr;
    length = 0;
}// default constructor


// Deletes the list of tokens
tokenList::~tokenList(){
    clear();
}// destructor

void tokenList::clear(){
    token* temp = begin;
    token* destructor = begin;

    while (temp != nullptr){
        temp = temp->next;
        delete destructor;
        destructor = temp;
        length--;
    }
    begin = nullptr;
    
}


// Checks if the tokenList is empty
bool tokenList::isEmpty(){
    if (begin != nullptr){
        return false;
    }
    return true;
}// isEmpty


// Returns the length of the list
int tokenList::getLength(){
    return length;
}// getLength


// Returns the token type of the token at the given index
int tokenList::peekToken(const int index){
    int tempToken = invalid;
    token* nextToken = getToken(index);
    if (nextToken != nullptr){
        tempToken = nextToken->id;
    }

    return tempToken;
}// peekToken


// Checks if the given id is equal to to token at the given index
bool tokenList::nextToken(const tokenId id, int &index){
    if (peekToken(index) != id || index >= length){
        return false;
    }
    return true;
}// nextToken


// Skips tokens of the given id
void tokenList::skipToken(const tokenId id, int & index){
    if (nextToken(id, index)){
        index++;
    }
    
}// skipToken


// Returns the token-object at the given list index
// If the index is greater then half of the list length, the
// walk is started from the end of the list, instead of the beginning
token* tokenList::getToken(const int index){
    token* temp = nullptr;
    // cout << int(length/2) << " "<<index << endl;
    if (index < int(length/2)){
        temp = begin;
        for(int i = 0; i < index; i++){
            if (temp != nullptr){
                temp = temp->next;
            }else {
                cerr << "Index out of bounds" << endl;
                return temp;
            }   
        }
    }else {
        temp = end;
        for(int i = getLength()-1; i > index; i--){
            if (temp != nullptr){
                temp = temp->prev;
            }else {
                cerr << "Index out of bounds" << endl;
                return temp;
            }
        }
    }
    return temp;
}// getToken


// Adds a token-object at the back of the tokenList
bool tokenList::addToken(const tokenId id, const string tokenChar){
    if(isEmpty()){
        token* newToken = new token;
        if (newToken == nullptr){
            cerr << "Memory allocation failed" << endl;
            return false;
        }
        newToken->id = id;
        newToken->tokenChar = tokenChar;
        begin = newToken;
        end = newToken;
        length++;

        return true;
    }else {
        token* temp = begin;
        token* newToken = new token;
        if (newToken == nullptr){
            cerr << "Memory allocation failed" << endl;
            return false;
        }
        newToken->id = id;
        newToken->tokenChar = tokenChar;
        
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newToken;
        newToken->prev = temp;
        end = newToken;
        length++;

        return true;
    }

    return false;
}// addToken


// Prints the contents of tokenList to stdout
void tokenList::printList(){
    token* temp = begin;

    while(temp != nullptr){
        cout << temp->id << ":" << temp->tokenChar << " ";
        temp = temp->next;
    }cout << endl;
}// printList
