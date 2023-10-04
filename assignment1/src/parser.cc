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
            id = LPAR; 
            break;
        case ')':
            id = RPAR;
            break;
        case '\\':
            id = LAMBDA;
            break;
        case '.': 
            id = DOT;
            break;
        case ' ': 
            id = SPACE;
            break;
        default: 
            id = INVALID;
            break;
    }
    if ((int(inputChar) >= 65 && int(inputChar) <= 90) || 
            (int(inputChar) >=97 && int(inputChar) <= 122) || 
                (int(inputChar) >=48 && int(inputChar) <= 57)){
        id = VAR;
    }
}// tokenSwitch

void parser::expr(tokenList & list){
    functionExpr(list);
    expr1(list);
}// expr


void parser::expr1(tokenList & list){
    if (list.peekToken() == EOL){
        return;
    }
    functionExpr(list);
    expr1(list);
}// expr1


// Checks if the token at the given index is a parexpr or a lambda expression
void parser::functionExpr(tokenList & list){
    if (list.peekToken() == LAMBDA){
        list.consumeToken();
        if (list.peekToken() == VAR){
            list.consumeToken();
            if(list.peekToken() == EOL){
                printError("Syntax error: no expression after lambda");
                error = true;
                return;
            }
            functionExpr(list);
        }else{
            printError("Syntax error: no variable after lambda");
            error = true;
            return;
        }
    }else{
        paranthesesExpr(list);
    }
}// fexpr


// Checks if the token at the given index is a paranthesis or a variable
void parser::paranthesesExpr(tokenList & list){
    if (list.peekToken() == VAR){
        list.consumeToken();
    }else if ((list.peekToken() == LPAR)){
        list.consumeToken();  
        expr(list);
    }else {
        printError("Syntax error: no variable or left paranthesis");
        error = true;
        return;
    }
}// parexpr


// Tokenizes the given string, and adds them to the given token list
void parser::stringTokenizer(const string input, tokenList & list){
    int lparCounter = 0, rparCounter = 0;
    int size = input.length();
    int i = 0;
    tokenId id = INVALID;
    string temp = "";


    while(input[i] != '\0'){
        if (input[i] == '\n'){
            if (list.isEmpty()){
                break;
            }
            if(!(list.addToken(EOL, "$"))){
                printError("Error: Failed to add token to the list.");
            }
            list.printList();
            
            if (lparCounter != rparCounter){
                printError("The token is invalid: not enough beginning/closing parantheses.");
                error = true;
                return;
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
            if (id == VAR){ 
                if (temp.empty() && (int(input[i]) >= 48 && int(input[i]) <= 57)){
                    printError("The token is invalid: variable name starts with a number.");
                    error = true;
                    return;

                }if (i < size){
                    tokenId tempId = INVALID;
                    tokenSwitch(input[i+1], tempId);
                    if (tempId == VAR){
                        temp += input[i];
                    }else {
                        temp += input[i];
                        if(!list.addToken(id, temp)){
                            printError("Error: Failed to add token to the list.");
                        }
                        temp.clear();
                    }
                }
            }else {
                if (id == LPAR){
                    lparCounter++;
                }if (id == RPAR){
                    rparCounter++;
                }
                if(!(list.addToken(id, string(1, input[i])))){
                    printError("Error: Failed to add token to the list.");
                }
            }
        }
        i++;
    }
    if(!(list.addToken(EOL, "$"))){
        printError("Error: Failed to add token to the list.");
    }
    list.printList();
            
    if (lparCounter != rparCounter){
        printError("The token is invalid: not enough beginning/closing parantheses.");
        error = true;
        return;
    }
    expr(list);

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
