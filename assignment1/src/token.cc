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

    if (temp != nullptr){
        while (temp->next != nullptr){
            temp = temp->next;
            delete destructor;
            destructor = temp;
        }
        delete temp;
        begin = nullptr;
    }
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
    if (getToken(index) != nullptr){
        tempToken = getToken(index)->id;
    }

    return tempToken;
}// peekToken


// Checks if the given id is equal to to token at the given index
bool tokenList::nextToken(const int id, int &index){
    if (peekToken(index) != id){
        return false;
    }
    return true;
}// nextToken


// Skips tokens of the given id
void tokenList::skipToken(const int id, int & index){
    if (nextToken(id, index)){
        index++;
    }
    
}// skipToken


// Returns the token-object at the given list index
// If the index is greater then half of the list length, the
// walk is started from the end of the list, instead of the beginning
token* tokenList::getToken(const int index){
    token* temp = nullptr;

    if (index < int(length/2)){
        temp = begin;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
    }else {
        temp = end;
        for(int i = getLength()-1; i > index; i--){
            temp = temp->prev;
        }
    }
    return temp;
}// getToken


// Adds a token-object at the back of the tokenList
bool tokenList::addToken(const int id, const string tokenChar){
    if(isEmpty()){
        token* newToken = new token;
        newToken->id = id;
        newToken->tokenChar = tokenChar;
        begin = newToken;
        end = newToken;
        length++;

        return true;
    }else {
        token* temp = begin;
        token* newToken = new token;
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
