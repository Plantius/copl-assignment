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
    // First we're going to count the amount of parantheses
    int leftParCounter = 0;
    int rightParCounter = 0;

    int size = tList->getLength();
    for (int i = 0; i < size; i++){
        int tempToken = tList->getToken(i)->id;
        if (tempToken == lpar){
            leftParCounter ++;
        }

         // We're also checking whether the parantheses contain an expression or variable
        // If there is a left paranthesis before the right one, then the parantheses are empty
        if ( tempToken == rpar){
            rightParCounter ++;
            int tempTerug = tList->getToken(i-1) -> id;
            if (tempTerug == lpar){
                cerr << "No variable or expression in parantheses." << endl;
            }
            int tempBack = tList->getToken(i-1) -> id;
            if (tempBack == lpar){
                cerr << "No variable or expression in parantheses." << endl;
                return false;
            }
        }

         // Also the lambda expressions are checked (very efficient use of a for loop)
        if (tempToken == lambda){
            int tempNext = tList->getToken(i+1) -> id;
            int tempDoubleNext = tList->getToken(i+2) -> id; 
            int tempMoreNext = tList->getToken(i+3) -> id; // In the case the lambda expression uses a dot
            if ((tempNext != var) || (tempDoubleNext == rpar)){ // klopt nog niet want er moeten nog veel spaties tussen kunnen
                cerr << "Lambda expression incorect." << endl;
                return false; 

            }
        }
    }

    if (leftParCounter!=rightParCounter){
        cerr << "The token is invalid: not enough beginning/closing parantheses." << endl;
        return false;
    }
    
    return true;    
} //tokenValid


// Tokenizes the given string, and adds them to the given token list
void stringTokenizer(const string input, tokenList* tList){
    int i = 0;

    while(input[i] != '\0'){
        tokenSwitch(input[i], tList);
        i++;
    }
    cout << tokenValid(tList) << endl;

}// stringTokenizer
