/**
* Implementation of the error handler
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* error.cc
* 05-10-2023
**/

#include "../include/error.h"

memoryError::memoryError(const std::string err){
    error = err;
    type = "Memory Error";
}// default memory error constructor

syntaxError::syntaxError(const std::string err, const int newRow, const int newCol){
    error = err;
    row = newRow;
    col = newCol;
    type = "Syntax Error";
}// default syntax error constructor

tokenError::tokenError(const std::string err, const int newRow, const int newCol){
    error = err;
    row = newRow;
    col = newCol;
    type = "Token Error";
}// default token error constructor

inputError::inputError(const std::string err){
    error = err;
    type = "Input Error";
}// default token error constructor

