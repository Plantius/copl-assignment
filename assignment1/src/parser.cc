#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
using namespace std;

enum tokenId {lpar, rpar, lambda, var, space, dot, invalid};

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
            id = invalid;
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
    int leftParCounter = 0, rightParCounter = 0;

    int size = tList->getLength();
    for (int i = 0; i < size; i++){
        int tempToken = tList->peekToken(i);
        if (tempToken == invalid){
            cerr << "Invalid token." << endl;
            return false;
        }
        
        if (tempToken == lpar){
            leftParCounter ++;
        }

        // We're also checking whether the parantheses contain an expression or variable
        // If there is a left paranthesis before the right one, then the parantheses are empty
        if (tempToken == rpar){
            if (i == 0){
                cerr << "The token is invalid: closing parantheses at start." << endl;
                return false;
            }if (tList->peekToken(i-1) == lpar){
                cerr << "The token is invalid: no variable or expression in parantheses." << endl;
                return false;
            }
            rightParCounter ++;
        }

         // Also the lambda expressions are checked (very efficient use of a for loop)
        if (tempToken == lambda){
            int k = i+1;
            tList->skipToken(space, k);

            if (tList->peekToken(k) != var){
                cerr << "The token is invalid: no variable after lambda expression." << endl;
                return false;
            }
            tList->skipToken(lpar, k);
            tList->skipToken(space, k);
            
            if (k == size-1 || !(tList->peekToken(k) == var || tList->peekToken(k) == lambda)){
                cerr << "The token is invalid: no variable or expression after lambda expression" << endl;
                return false;
            }
            if (k == size-1 || tList->peekToken(k) == rpar){
                cerr << "The token is invalid: no variable or expression after lambda expression" << endl;
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
                cerr << "The token is invalid: variable name starts with a number." << endl;
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
