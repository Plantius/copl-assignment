#include "../include/parser.h"
using namespace std;

void stringTokenizer(const string input){
        
    int i = 0;

    while(input[i] != '\0'){
        if (input[i] != ' '){
            if(!listEmpty()){
                addToken();
            }
        }
        i++;
    }
}// string_tokenizer
