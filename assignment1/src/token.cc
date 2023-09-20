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

bool tokenList::isEmpty(){
    if (begin != nullptr){
        return false;
    }
    return true;
}// isEmpty


bool tokenList::addToken(const int id, const char tokenChar){
    if(isEmpty()){
        token* newToken = new token;
        newToken->id = id;
        newToken->tokenChar = tokenChar;
        begin = newToken;
    }else {

    }

}// addToken
