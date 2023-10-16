/**
* Implementation of the standard functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* standard.cc
* 05-10-2023
**/

#include "../include/standard.h"
#include "../include/error.h"
#include <fstream>
#include <sstream>
using namespace std;

// Reads an istream from a file, and reads it into a stringstream 
string readFile(const string filepath){
    ifstream file(filepath);
    string input;
    if(!file.good() || !file.is_open()){
        throw inputError("File does not exist or is corrupted");
    }
    while (getline(file, input)){
        
    }
    return input;
}// readFile


// Checks if the given string contains only ASCII-characters
void validInput(const string input){
    int i = 0;
    while(input[i] != '\0'){
        if ((u_char)input[i] > 127){
            throw inputError("Contains non-standard ASCII characters");
        }
        i++;
    }
}// valid_input

