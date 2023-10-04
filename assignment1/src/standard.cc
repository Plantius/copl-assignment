/**
* Implementation of the standard functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* standard.cc
* 04-10-2023
**/

#include "../include/standard.h"
#include <fstream>
#include <sstream>
using namespace std;


// Reads input from stdin and concatenates it to a string
// until a newline or a carriage-return and newline character is met
void getInput(string & input){
    char c = invalidChar;
    while (c != '\n' && c != '\r'){
        c = getchar();
        if ((u_char)c > 127){
            throw string("Invalid input: outside standard ASCII range");
        }
        input += c;
    }
}// getInput


// Reads an istream from a file, and reads it into a stringstream 
string readFile(const string filepath){
    ifstream file(filepath);
    stringstream buffer;
    if(!file.good() || !file.is_open()){
        throw string("Invalid input: file does not exist/is corrupted");
    }
    buffer << file.rdbuf();
    return buffer.str();
}// readFile


// Checks if the given string contains only ASCII-characters
void validInput(const string input){
    int i = 0;
    while(input[i] != '\0'){
        if ((u_char)input[i] > 127){
            throw string("Invalid input: contains non-ASCII characters");
        }
        i++;
    }
}// valid_input

// Prints the given string to stdout
void printError(const string input){
    cerr << string(input.length(), '-') << endl 
         << input << endl << string(input.length(), '-') << endl;
}// print_cout