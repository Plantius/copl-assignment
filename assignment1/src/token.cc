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


bool tokenList::addToken(){

}// addToken
