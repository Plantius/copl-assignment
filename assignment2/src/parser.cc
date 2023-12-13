/**
* Implementation of the parser functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* parser.cc
* 04-10-2023
**/ 

#include "../include/parser.h"
#include "../include/error.h"
#include "../include/alpha_beta.h"
using std::cout, std::endl;

// Checks what id the given inputChar has in tokenId
tokenId parser::tokenSwitch(const char inputChar) const{
    // for all the special characters
    switch(inputChar){
        case '(': return LPAR; 
        case ')': return RPAR;
        case '\\': return LAMBDA;
        case '.': return DOT;
        case ' ': return APPLICATION;
        
        default: break;
    }
    if (islower(inputChar) || isupper(inputChar) || isdigit(inputChar)){
        return VAR;
    }
    return INVALID;
}// tokenSwitch


/* 
===========================================================
                      PARSE EXPRESSION
===========================================================
*/


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
                throw parseError("No expression after lambda.", row, col);
            }
            lambdaExpr(list);

        }else{
            throw parseError("No variable after lambda.", row, col);
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
        throw parseError("No variable or opening paranthesis.", row, col);
    }
}// parexpr


/* 
===========================================================
                      TOKENIZE STRING
===========================================================
*/


// Tokenizes the given std::string, and adds them to the given token list
void parser::stringTokenizer(const std::string input){
    tokenList list;
    alphaBeta ab;

    int lparCounter = 0, rparCounter = 0;
    tokenId id = INVALID, tempId = INVALID;
    std::string tempVar = emptyStr, character = emptyStr;

    for (size_t i = 0; i < input.size(); i++){
        id = tokenSwitch(input[i]);
        if ((id == APPLICATION && character == "\\") || (id == APPLICATION && character == "@")){
            continue;
        }
        character = input[i];
        // Checks if the input is a var, which can be of indefinite size
        if (id == VAR){ 
            if (tempVar.empty() && isdigit(input[i])){
                throw tokenError("Variable name starts with a number.", row, col);

            }if (i < input.size()){
                tempId = tokenSwitch(input[i+1]);
                if (tempId == VAR){
                    tempVar += input[i];
                }else {
                    tempVar += input[i];
                    list.addToken(id, tempVar);
                    tempVar.clear();
                }
            }
        }else {
            lparCounter += (id == LPAR) ? 1 : 0;
            rparCounter += (id == RPAR) ? 1 : 0;
           
            if (id == APPLICATION){
                character = "@";
            }
            list.addToken(id, character);
        }
        col++;
    }
    list.addToken(EOL, "#");
            
    if (lparCounter != rparCounter){
        throw parseError("Number of beginning and closing parantheses do not match.", row, col);
    }
    expr(list);
    col = 1, row++;

    parseTree.makeTree(list);
    parseTree.printTree();
    
    ab.makeAbstract(list, parseTree);
    parseTree.printTree();
}// stringTokenizer


void parser::debugTree(const std::string filename) const {
    parseTree.saveDOT(filename);
}// debugTree