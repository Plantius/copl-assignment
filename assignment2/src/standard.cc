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


// Checks if the given string contains only ASCII-characters
bool validInput(const std::string input){
    for (auto c : input) {
        if (!isascii(c)){
            return false;
        }
    }
    return true;
}// valid_input

std::string chooseVar(const std::set<std::string> varList){
    std::string temp;
    for (auto letter : alphabet){
        temp = letter;
        if (varList.find(temp) == varList.end()){
            return temp;
        }
    }
    return (temp+temp);
}

