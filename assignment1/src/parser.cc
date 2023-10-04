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
        case ' ': 
            id = space;
            break;
        case '\0': 
            id = eof;
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

void parser::expr(tokenList* tList){
    functionExpr(tList);
    expr1(tList);
}// expr


void parser::expr1(tokenList* tList){
    functionExpr(tList);
    expr1(tList);
}// expr1


// Checks if the token at the given index is a parexpr or a lambda expression
void parser::functionExpr(tokenList* tList){
    if (!(tList->getIndex() < 0 || tList->getIndex() >= tList->getLength())){
        paranthesesExpr(tList);
        
        if (tList->peekToken() == lambda){
            tList->consumeToken();
            functionExpr(tList);
        }
    }
    
}// fexpr


// Checks if the token at the given index is a paranthesis or a variable
void parser::paranthesesExpr(tokenList* tList){
    if (!(tList->getIndex() < 0 || tList->getIndex() >= tList->getLength())){
        if ((tList->peekToken() == lpar)){
            tList->skipToken(lpar);
            expr(tList);
            tList->skipToken(rpar);
        }
        else if (tList->peekToken() == var){
            tList->consumeToken();
        }
    }else {
        cerr << "Invalid token: index out of bounds" << endl;
        exit(1);
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
        if (input[i] == '\n'){
            continue;
        }
        
        tokenSwitch(input[i], id);
        // Checks if the input is a var, which can be of indefinite size
        if (id == var){ 
            if (temp.empty() && (int(input[i]) >=48 && int(input[i]) <= 57)){
                cerr << "The token is invalid: variable name starts with a number." << endl;
                exit(1);

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
        exit(1);
    }
    cout << "Length " << tList->getLength() << endl;
    expr(tList);
}// stringTokenizer

void parser::printExpression(const string input, int& index, tokenList* tList){
    int length = tList -> getLength();
    if (!(tList->isEmpty())){
        for (int i = 0; i < length; i++){
            cout << input[i] << endl; //?? not done
        }
    }
    else{
        cout << "" << endl;
    }
    
}
