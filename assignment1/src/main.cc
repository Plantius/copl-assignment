/**
* Implementation of the main function
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* main.cc
* 15-09-2023
**/ 

#include "../include/standard.h"
#include "../include/parser.h"
using namespace std;

int main(){
    for (string input; getline(cin, input);){
        if(valid_input(input)){
            string_tokenizer(input);
            print_cout(input);
        }
    }
    
    return 0;
}// main