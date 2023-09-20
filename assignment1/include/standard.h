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

// Reads input from stdin
void getInput(std::string & input);

// Reads a constant string and checks if it is valid, e.i. if
// it only contains ASCII-characters
bool validInput(const std::string input);

// Reads a constant string and prints it to stdout
void printCout(const std::string input);

#endif