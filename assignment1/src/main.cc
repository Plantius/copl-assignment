/**
* Implementation of the main function
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* main.cc
* 15-09-2023
**/ 

#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
using namespace std;

enum test { lpar, rpar, lambda, var};

int main(){
    tokenList * tList = new tokenList;

    string input = ""; 
    getInput(input);
    
    if(validInput(input)){
        stringTokenizer(input, tList);
        // printCout(input);
        // t1 = clock();
        // for (int i = 0; i < tList->getLength(); i++){
        //     cout << tList->getToken(i)->id << ":" << tList->getToken(i)->tokenChar << " "; 
        // }cout << endl;
        // t2 = clock();
        // cout << "GetToken " << (((double)(t2-t1))/CLOCKS_PER_SEC) << endl;
        // t1 = clock();
        tList->printList();
        // t2 = clock();
        // cout << "printList " << (((double)(t2-t1))/CLOCKS_PER_SEC) << endl;
    }
    
    delete tList;
    return 0;
}// main