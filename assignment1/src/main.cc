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


int main(){
    clock_t t1, t2;
    tokenList* tList = new tokenList;
    string input = "", filePath = ""; 

    getInput(filePath); 
    if (validInput(filePath)){
        for(int i = 0; i < filePath.length(); i++){
            cout << int(filePath[i]) << " ";
        }
        input = readFile("/home/niels/year2/CoPL/copl-assignment/tests/input.txt");
        if(validInput(input)){
            t1 = clock();
            cout << "Valid: " << stringTokenizer(input, tList) << endl;
            t2 = clock();

            cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
            tList->printList();
        }
    }
    delete tList;
    return 0;
}// main