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
    parser p;
    string input = "", filePath = ""; 

    // getInput(filePath); 
    if (validInput(filePath)){
        input = readFile("/home/niels/year2/CoPL/copl-assignment/tests/input.txt");
        
        if(validInput(input)){
            t1 = clock();
            p.stringTokenizer(input, tList);
            t2 = clock();

            cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
        }
    }
    delete tList;
    return 0;
}// main