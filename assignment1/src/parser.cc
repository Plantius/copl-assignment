#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
#include "../include/tokenId.h"
using namespace std;

// Checks what id the given inputChar has in tokenId
void parser::tokenSwitch(const char inputChar, tokenId & id){
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

void parser::expr(int &index, tokenList* tList){
    functionExpr(index, tList);
    expr1(index, tList);
}// expr


void parser::expr1(int &index, tokenList* tList){
    functionExpr(index, tList);
    expr1(index, tList);
}// expr1


// Checks if the token at the given index is a parexpr or a lambda expression
void parser::functionExpr(int &index, tokenList* tList){
    paranthesesExpr(index, tList);

    if (!(index < 0 || index >= tList->getLength())){
        if (tList -> peekToken(index) == lambda){
            tList->skipToken(lambda, index);
            while (tList -> nextToken(var, index)){
                // cout << tList->getToken(index)->tokenChar << endl;
                index++;
            }
            
            functionExpr(index, tList);
        }
    }
    
}// fexpr


// Checks if the token at the given index is a paranthesis or a variable
void parser::paranthesesExpr(int &index, tokenList* tList){
    if (!(index < 0 || index >= tList->getLength())){
        if ((tList->peekToken(index) == lpar)){
            tList->skipToken(lpar, index);
            expr(index, tList);
            tList->skipToken(rpar, index);
        }
        else if (tList -> peekToken(index) == var){
            // cout << tList->getToken(index)->tokenChar << endl;
            index++;
        }
    }

}// parexpr


// Tokenizes the given string, and adds them to the given token list
void parser::stringTokenizer(const string input, tokenList* tList){
    int index = 0;
    int lparCounter = 0, rparCounter = 0;
    int size = input.length();
    tokenId id = invalid;
    string temp = "";

    for(int i = 0; i < size; i++){
        if (input[i] == ' ' || input[i] == '\n'){
            continue;
        }
        
        tokenSwitch(input[i], id);
        // Checks if the input is a var, which can be of indefinite size
        if (id == var){ 
            if (temp.empty() && (int(input[i]) >=48 && int(input[i]) <= 57)){
                cerr << "The token is invalid: variable name starts with a number." << endl;
                // error

            }if (i < size-1){
                tokenId tempId = invalid;
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
            if(!(tList->addToken(id, string(1, input[i])))){
                cerr << "Failed to add token to the list." << endl;
            }
        }
    }
    if (lparCounter != rparCounter){
        cerr << "The token is invalid: not enough beginning/closing parantheses." << endl;
        // error
    }
    cout << "Length " << tList->getLength() << endl;
    expr(index, tList);
}// stringTokenizer