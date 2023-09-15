/**
* Implementation of the main function
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* main.cc
* 15-09-2023
**/

#include "../include/standard.h"
using namespace std;

int main(){
    string input = "";

    cin >> input;
    if(valid_input(input)){
        print_cout(input);
        return 0;
    }

    return 1;
}