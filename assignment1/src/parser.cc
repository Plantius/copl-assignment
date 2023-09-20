#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"

using namespace std;

enum tokenId {lpar, rpar, lambda, var, space, dot};

// Checks the given tokenList for syntax errors
bool syntaxCheck(tokenList* tList){
    int i = 0;

    while (tList->getToken(i)){
        
    }
}// syntaxCheck


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

    // First we're going to count the amount of parantheses
    int leftParCounter = 0;
    int rightParCounter = 0;

    int size = tList -> getLength();
    for (int i = 0; i < size; i++){
        int tempToken = tList->getToken(i)->id; // check ik later wel ff
        if (tempToken == lpar){
            leftParCounter ++;
        }
        if ( tempToken == rpar){
            rightParCounter ++;
        }
    }

    if (leftParCounter!=rightParCounter){
        cout << "The token is invalid: not enough beginning/closing parantheses." << endl;
        return false;
    }

    // Now we're checking whether the parantheses contain an expression or variable
    for (int j = 0; j < size; j++){
        int tempToken = tList->getToken(j)->id; // check ik later wel ff
        if (tempToken == rpar){
            int temp2 = tList->getToken(j-1)->id;
            if (temp2 == lpar){
                cout << "No variable or expression in parantheses." << endl;
                return false;
            }
        }
    }
    

    return true;    
}


// Tokenizes the given string, and adds them to the given token list
void stringTokenizer(const string input, tokenList* tList){
    int i = 0;

    while(input[i] != '\0'){
        tokenSwitch(input[i], tList);
        i++;
    }


}// stringTokenizer
