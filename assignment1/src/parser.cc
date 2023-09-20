#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"

using namespace std;

enum tokenId {lpar, rpar, lambda, var, space, dot};

void tokenSwitch(const string inputChar, tokenList* tList){
    int i = 0;
    tokenId id;

    while(inputChar[i] != '\0'){
       switch(inputChar[i]){
        case '(':
            id = lpar; 
            tList->addToken(id, '(');
        case ')':
            tList->addToken(id, ')');
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
