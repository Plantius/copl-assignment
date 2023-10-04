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
            cerr << "Invalid input: outside standard ASCII range" << endl;
            exit(1);
        }
        input += c;
    }
}// getInput


// Reads an istream from a file, and reads it into a stringstream 
string readFile(const string filepath){
    ifstream file(filepath);
    stringstream buffer;
    if(!file.good()){
        cerr << "Invalid input: file does not exist/is corrupted" << endl;
        exit(1);
    }
    buffer << file.rdbuf();
    return buffer.str();
}// readFile


// Checks if the given string contains only ASCII-characters
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

// Prints the given string to stdout
void printError(const string input){
    cout << input << endl;
}// print_cout