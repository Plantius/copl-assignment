#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"

using namespace std;

enum tokenId {lpar, rpar, lambda, var, space, dot};

void tokenSwitch(const string inputChar, tokenList* tList){
    int i = 0;
    tokenId id;

    while(inputChar[i] != '\0'){

        // for all the special characters
       switch(inputChar[i]){
        case '(':
            id = lpar; 
            if(!tList -> addToken(id, '(')){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case ')':
            id = rpar;
            if(!tList -> addToken(id, ')')){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case '\\':
            id = lambda;
            if(!tList -> addToken(id,'\\')){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case ' ':
            id = space;
            if(!tList -> addToken(id, ' ')){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        case '.': 
            id = dot;
            if(!tList -> addToken(id, '.')){
                cerr << "Failed to add token to the list" << endl;
            }
            break;
        default:
            break;
       }

        if((int(inputChar[i]) >= 65 && int(inputChar[i]) <= 90) || (int(inputChar[i]) >=97 && int(inputChar[i]) <= 122) || (int(inputChar[i]) >=48 && int(inputChar[i]) <= 57)){
            id = var;
            if(!tList -> addToken(id, inputChar[i])){
                cerr << "Failed to add token to the list" << endl;
            }
        }
    }

}// tokenSwitch


void stringTokenizer(const string input){
    tokenList* tList = new tokenList;        
    int i = 0;

    while(input[i] != '\0'){
        if (input[i] != ' '){
            
        }
        i++;
    }
}// stringTokenizer
