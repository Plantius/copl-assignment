/**
* Declaration of the standard functions: valid_input, print_cout
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* standard.h
* 15-09-2023
**/

#ifndef STANDARD_H
#define STANDARD_H
#include <iostream>

const char invalidChar = '$';

// Reads input from stdin
void getInput(std::string & input);

// Reads input from a file
std::string readFile(const std::string filepath);

// Reads a constant string and checks if it is valid, e.i. if
// it only contains ASCII-characters
void validInput(const std::string input);

// Reads a constant string and prints it to stdout
void printError(const std::string error, const std::string filepath, const std::string errType);

#endif