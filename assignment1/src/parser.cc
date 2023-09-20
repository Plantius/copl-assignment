#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"

using namespace std;

enum tokenId {lpar, rpar, lambda, var, space, dot};

void tokenSwitch(const char inputChar, tokenList* tList){
    tokenId id;

    // Switch for the special characters
    switch(inputChar){
        case '(':
            id = lpar; 
            if(!(tList->addToken(id, '('))){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case ')':
            id = rpar;
            if(!(tList->addToken(id, ')'))){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case '\\':
            id = lambda;
            if(!(tList->addToken(id,'\\'))){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case ' ':
            id = space;
            if(!(tList->addToken(id, ' '))){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case '.': 
            id = dot;
            if(!(tList->addToken(id, '.'))){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        default: 

            break;
    }

    // For the normal characters
    if((int(inputChar) >= 65 && int(inputChar) <= 90) || (int(inputChar) >=97 && int(inputChar) <= 122) || (int(inputChar) >=48 && int(inputChar) <= 57)){
        id = var;
        if(!tList -> addToken(id, inputChar)){
            cerr << "Failed to add token to the list" << endl;
        }
    }
}// tokenSwitch


bool tokenValid(tokenList* tList){

    // RIGHT OF SYMBOL:
    // LPAR: only VAR, LPAR, SPACE
    // RPAR: only VAR, LPAR, RPAR, SPACE

    // LEFT OF SYMBOL
    // LPAR: only VAR, LPAR, RPAR, SPACE
    // RPAR: only VAR, SPACE, RPAR

    // cannot start with RPAR
    
    

    
}


// Tokenizes the given string, and adds them to the given token list
void stringTokenizer(const string input, tokenList* tList){
    int i = 0;

    while(input[i] != '\0'){
        tokenSwitch(input[i], tList);
        i++;
    }

}// stringTokenizer
