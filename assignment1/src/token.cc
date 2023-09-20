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
    end = nullptr;
    length = 0;
}// default constructor


// Deletes the list of tokens
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


// Returns the length of the list
int tokenList::getLength(){
    return length;
}// getLength

// Returns the token-object at the given list index
token* tokenList::getToken(const int index){
    token* temp = nullptr;
    
    if (index < int(length/2)){
        temp = end;
        for(int i = getLength(); i > index+1; i--){
            temp = temp->prev;
        }
    }else {
        temp = begin;
        for(int i = 0; i < getLength(); i++){
            temp = temp->next;
        }
    }
    
    return temp;
}// getToken


// Adds a token-object at the back of the tokenList
bool tokenList::addToken(const int id, const char tokenChar){
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
