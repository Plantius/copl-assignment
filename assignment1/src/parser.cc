#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
#include "../include/tokenId.h"
using namespace std;

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
    int size = tList->getLength();
    
    for (int i = 0; i < size; i++){
        int tempToken = tList->peekToken(i);
        if (tempToken == invalid){
            cerr << "Invalid token." << endl;
            return false;
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
        }
    }
    
    return true;    
} //tokenValid


// Tokenizes the given string, and adds them to the given token list
bool stringTokenizer(const string input, tokenList* tList){
    int id = invalid;
    int lparCounter = 0, rparCounter = 0;
    int size = input.length();
    string temp = "", singleChar = "";

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
            if (id == lpar){
                lparCounter++;
            }if (id == rpar){
                rparCounter++;
            }
            if(!(tList->addToken(id, singleChar))){
                cerr << "Failed to add token to the list." << endl;
            }
        }
    }
    if (lparCounter != rparCounter){
        cerr << "The token is invalid: not enough beginning/closing parantheses." << endl;
        return false;
    }
    return syntaxCheck(tList);
}// stringTokenizer


void expr(int &index, tokenList* tList){
    fexpr(index, tList);
    expr1(index, tList);
}// expr

void expr1(int &index, tokenList* tList){
    fexpr(index, tList);
    expr1(index, tList);
}


void fexpr(int &index, tokenList* tList){
    parexpr(index,tList);

    if (tList -> peekToken(index)==lambda){
        tList->skipToken(lambda, index);
        if (!tList -> nextToken(var, index)){
            cerr << "Syntax error: no variable after lambda expression" << endl;
        }
        fexpr(index, tList); 
        
    }


}

bool parexpr(int &index, tokenList* tList){

    if ((tList -> peekToken(index) == lpar) || (tList -> peekToken(index) == rpar)){
        expr(index, tList);
    }
    else if (tList -> peekToken(index) == var){
        return true;
    }

    return false;

}