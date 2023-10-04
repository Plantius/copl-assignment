/**
* Implementation of the parser functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* parser.cc
* 04-10-2023
**/ 

#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
#include "../include/tokenId.h"
using namespace std;

parser::parser(){
    error = false;
}// default constructor


bool parser::getError(){
    return error; 
}// getError


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

void parser::expr(tokenList & list){
    functionExpr(list);
    expr1(list);
}// expr


void parser::expr1(tokenList & list){
    if (list.peekToken() == eol){
        return;
    }
    functionExpr(list);
    expr1(list);
}// expr1


// Checks if the token at the given index is a parexpr or a lambda expression
void parser::functionExpr(tokenList & list){
    if (list.peekToken() == lambda){
        list.consumeToken();
        if (list.peekToken() == var){
            list.consumeToken();
            if(list.peekToken() == eol){
                cerr << "Syntax error: no expression after lambda" << endl;
                error = true;
                return;
            }
            functionExpr(list);
        }else{
            cerr << "Syntax error: no variable after lambda"<<endl;
            error = true;
            return;
        }
    }else{
        paranthesesExpr(list);
    }
}// fexpr


// Checks if the token at the given index is a paranthesis or a variable
void parser::paranthesesExpr(tokenList & list){
    if (list.peekToken() == var){
        list.consumeToken();
    }else if ((list.peekToken() == lpar)){
        list.consumeToken();  
        expr(list);
    }else {
        cerr << "Syntax error: no variable or left paranthesis" << endl;
        error = true;
        return;
    }
}// parexpr


// Tokenizes the given string, and adds them to the given token list
void parser::stringTokenizer(const string input, tokenList & list){
    int lparCounter = 0, rparCounter = 0;
    int size = input.length();
    int i = 0;
    tokenId id = invalid;
    string temp = "";


    while(input[i] != '\0'){
        if (input[i] == '\n'){
            if (list.isEmpty()){
                break;
            }
            if(!(list.addToken(eol, "$"))){
                cerr << "Error: Failed to add token to the list." << endl;
            }
            list.printList();
            
            if (lparCounter != rparCounter){
                cerr << "The token is invalid: not enough beginning/closing parantheses." << endl;
                exit(1);
            }
            expr(list);
            if(error){
                return;
            }
            list.clear();
            lparCounter = 0;
            rparCounter = 0;
        }else {
            tokenSwitch(input[i], id);
            // Checks if the input is a var, which can be of indefinite size
            if (id == var){ 
                if (temp.empty() && (int(input[i]) >= 48 && int(input[i]) <= 57)){
                    cerr << "The token is invalid: variable name starts with a number." << endl;
                    exit(1);

                }if (i < size-1){
                    tokenId tempId = invalid;
                    tokenSwitch(input[i+1], tempId);
                    if (tempId == var){
                        temp += input[i];
                    }else {
                        temp += input[i];
                        if(!list.addToken(id, temp)){
                            cerr << "Error: Failed to add token to the list." << endl;
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
                if(!(list.addToken(id, string(1, input[i])))){
                    cerr << "Error: Failed to add token to the list." << endl;
                }
            }
        }
        i++;
    }
}// stringTokenizer

void parser::printExpression(const string input, tokenList & list){
    int length = list.getLength();
    if (!(list.isEmpty())){
        for (int i = 0; i < length; i++){
            cout << input[i] << endl; //?? not done
        }
    }
    else{
        cout << "" << endl;
    }
    
}
