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
#include "../include/error.h"
using namespace std;

parser::parser(){
    row = 1, col = 1;
}// Default constructor


// Checks what id the given inputChar has in tokenId
tokenId parser::tokenSwitch(const char inputChar) const{
    // for all the special characters
    switch(inputChar){
        case '(': return LPAR; 
        case ')': return RPAR;
        case '\\': return LAMBDA;
        case '.': return DOT;
        case ' ': return SPACE;
        
        default: break;
    }
    if ((int(inputChar) >= 65 && int(inputChar) <= 90) || 
            (int(inputChar) >=97 && int(inputChar) <= 122) || 
                (int(inputChar) >=48 && int(inputChar) <= 57)){
        return VAR;
    }
    return INVALID;
}// tokenSwitch

void parser::expr(tokenList & list) const{
    lambdaExpr(list);
    expr1(list);
}// expr


void parser::expr1(tokenList & list) const{
    if (list.peekToken() == EOL){
        return;
    }
    lambdaExpr(list);
    expr1(list);
}// expr1


// Checks if the token at the given index is a parexpr or a lambda expression
void parser::lambdaExpr(tokenList & list) const{
    if (list.peekToken() == LAMBDA){
        list.consumeToken();
        if (list.peekToken() == VAR){
            list.consumeToken();
            if(list.peekToken() == EOL){
                throw syntaxError("No expression after lambda.", row, col);
            }
            lambdaExpr(list);
        }else{
            throw syntaxError("No variable after lambda.", row, col);
        }
    }else{
        varExpr(list);
    }
}// fexpr


// Checks if the token at the given index is a paranthesis or a variable
void parser::varExpr(tokenList & list) const{
    if (list.peekToken() == VAR){
        list.consumeToken();
    }else if ((list.peekToken() == LPAR)){
        list.consumeToken();  
        expr(list);
    }else {
        throw syntaxError("No variable or opening paranthesis.", row, col);
    }
}// parexpr


// Tokenizes the given string, and adds them to the given token list
void parser::stringTokenizer(const string input){
    tokenList list;
    int lparCounter = 0, rparCounter = 0;
    int size = input.length();
    int i = 0;
    tokenId id = INVALID;
    string tempVar = emptyStr;


    while(input[i] != '\0'){
        id = tokenSwitch(input[i]);
        // Checks if the input is a var, which can be of indefinite size
        if (id == VAR){ 
            if (tempVar.empty() && (int(input[i]) >= 48 && int(input[i]) <= 57)){
                throw tokenError("Variable name starts with a number.", row, col);

            }if (i < size){
                tokenId tempId = tokenSwitch(input[i+1]);
                if (tempId == VAR){
                    tempVar += input[i];
                }else {
                    tempVar += input[i];
                    if(!list.addToken(id, tempVar)){
                        throw tokenError("Failed to add token to the list.", row, col);
                    }
                    tempVar.clear();
                }
            }
        }else {
            if (id == LPAR){
                lparCounter++;
            }if (id == RPAR){
                rparCounter++;
            }
            if(!(list.addToken(id, string(1, input[i])))){
                throw tokenError("Failed to add token to the list.", row, col);
            }
        }
        i++;
        col++;
    }
    if(!(list.addToken(EOL, "#"))){
        throw tokenError("Failed to add token to the list.", row, col);
    }
            
    if (lparCounter != rparCounter){
        throw syntaxError("Number of beginning and closing parantheses do not match.", row, col);
    }
    expr(list);
    list.printList();
    col = 0, row++;

}// stringTokenizer

void parser::printExpression(const string input, tokenList & list){
    int length = list.getLength();
    int linkerhaakje = 0;
    if (!(list.isEmpty())){
        for (int i = 0; i < length; i++){
            if (input[i] == LAMBDA || input[i] == VAR){
                cout <<"(" << input[i];
            }
            if (input[i] == VAR && (linkerhaakje % 2 == 1)){
                cout << input[i] << ')';
            }
            cout << input[i] << endl; //?? not done
        }
    }
    else{
        cout << " " << endl;
    }
    
}

node::node(){
    left = nullptr;
    right = nullptr;
}

tree::tree(){
    begin = nullptr;
}

tree::~tree(){

}

bool tree::isEmpty(){
    if (begin == nullptr){
        return true;
    }
    return false;
}

bool tree::makeNode(tokenId id, node* & index){
    if (isEmpty()){
       // Als de boom leeg is, begint de boom met het eerste element
        begin = new node;
        begin->id = id;
        index = begin;
        return true;
    }

    else{
        
    }
    return false;
}