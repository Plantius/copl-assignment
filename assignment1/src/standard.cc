/**
* Implementation of the standard header, containing the valid_input and 
* print_cout functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* standard.cc
* 15-09-2023
**/

#include "../include/standard.h"
using namespace std;

bool validInput(const string input){
    int i = 0;

    while(input[i] != '\0'){
        if ((u_char)input[i] > 127){
            return false;
        }
        i++;
    }
    return true;
}// valid_input

void printCout(const string input){
    cout << input << endl;
}// print_cout