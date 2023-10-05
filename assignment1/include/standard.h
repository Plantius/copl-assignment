/**
* Declaration of the standard functions: valid_input, print_cout
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* standard.h
* 05-10-2023
**/

#ifndef STANDARD_H
#define STANDARD_H
#include <iostream>

const char invalidChar = '$';
const std::string emptyStr = "";

// Reads input from a file
std::string readFile(const std::string filepath);

// Reads a constant string and checks if it is valid, e.i. if
// it only contains ASCII-characters
void validInput(const std::string input);

#endif