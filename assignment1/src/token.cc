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
