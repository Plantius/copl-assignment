#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
using namespace std;

enum tokenId {lpar, rpar, lambda, var, space, dot};

// Checks what id the given inputChar has in tokenId
void tokenSwitch(const char inputChar, int & id){
    // for all the special characters
    switch(inputChar){
        case '(':
            id = lpar; 
            break;
        case ')':
            id = rpar;
            break;
        case '\\':
            id = lambda;
            break;
        case ' ':
            id = space;
            break;
        case '.': 
            id = dot;
            break;
        default: 
            break;
    }
    if ((int(inputChar) >= 65 && int(inputChar) <= 90) || 
            (int(inputChar) >=97 && int(inputChar) <= 122) || 
                (int(inputChar) >=48 && int(inputChar) <= 57)){
        id = var;
    }
}// tokenSwitch


// Checks the syntax of the given token list
bool syntaxCheck(tokenList* tList){
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
        if (tempToken == rpar){
            if (i == 0){
                cerr << "Invalid parantheses." << endl;
                return false;
            }
            rightParCounter ++;
            // int tempTerug = tList->getToken(i-1) -> id;
            // if (tempTerug == lpar){
            //     cerr << "No variable or expression in parantheses." << endl;
            // }
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
bool stringTokenizer(const string input, tokenList* tList){
    int id;
    string temp = "", singleChar = "";
    int size = input.length();
    
    for(int i = 0; i < size-1; i++){
        singleChar = input[i];
        
        tokenSwitch(input[i], id);
        // Checks if the input is a var, which can be of indefinete size
        if (id == var){ 
            if (temp.empty() && (int(input[i]) >=48 && int(input[i]) <= 57)){
                cerr << "Variable name starts with a number." << endl;
                return false;
            }if (i < size-1){
                int tempId = 0;
                tokenSwitch(input[i+1], tempId);
                if (tempId == var){
                    temp += input[i];
                }else {
                    temp += input[i];
                    if(!tList -> addToken(id, temp)){
                        cerr << "Failed to add token to the list." << endl;
                    }
                    temp.clear();
                }
            }
        }else {
            if(!(tList->addToken(id, singleChar))){
                cerr << "Failed to add token to the list." << endl;
            }
        }
    }
    return syntaxCheck(tList);
}// stringTokenizer
