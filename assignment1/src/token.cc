#include "../include/standard.h"
#include "../include/token.h"
using namespace std;

// Default constructor
token::token(){
    next = nullptr;
    prev = nullptr;
    id = 0;
    tokenChar = '$';
}// default constructor


// Default constructor
tokenList::tokenList(){
    begin = nullptr;
}// default constructor


// Deletes the tokenList
tokenList::~tokenList(){
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
}// destructor


// Checks if the tokenList is empty
bool tokenList::isEmpty(){
    if (begin != nullptr){
        return false;
    }
    return true;
}// isEmpty


// Adds a token-object at the back of the tokenList
bool tokenList::addToken(const int id, const char tokenChar){
    if(isEmpty()){
        token* newToken = new token;
        newToken->id = id;
        newToken->tokenChar = tokenChar;
        begin = newToken;

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

        return true;
    }

    return false;
}// addToken



// Prints the contents of tokenList to stdout
void tokenList::printList(){
    token* temp = begin;
    
    while(temp != nullptr){
        cout << temp->id << ":" << temp->tokenChar << endl;
        temp = temp->next;
    }
}
