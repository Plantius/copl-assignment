#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"

using namespace std;

enum tokenId {lpar, rpar, lambda, var, space, dot};

void tokenSwitch(const char inputChar, tokenList* tList){
    tokenId id;

    // for all the special characters
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

    if((inputChar >= 65 && inputChar <= 90) || (inputChar >=97 && inputChar <= 122)){
        id = var;
        if(!(tList->addToken(id, inputChar))){
            cerr << "Failed to add token to the list" << endl;
        }
    }
    

}// tokenSwitch


void stringTokenizer(const string input, tokenList* tList){
    int i = 0;

    while(input[i] != '\0'){
        tokenSwitch(input[i], tList);
        i++;
    }

}// stringTokenizer
