/**
* Implementation of the error handler
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* error.cc
* 05-10-2023
**/

#include "../include/error.h"
using namespace std;

errorHandler::errorHandler(){
    error = "";
    row = 0;
    col = 0;
}// default constructor

string errorHandler::getError(){
    return error;
}// getError

int errorHandler::getRow(){
    return row;
}// getRow

int errorHandler::getCol(){
    return col;
}// getCol

memoryError::memoryError(const string err){
    error = err;
}// default memory error constructor

syntaxError::syntaxError(const string err, const int newRow, const int newCol){
    error = err;
    row = newRow;
    col = newCol;
}// default syntax error constructor

tokenError::tokenError(const string err, const int newRow, const int newCol){
    error = err;
    row = newRow;
    col = newCol;
}// default token error constructor

inputError::inputError(const string err){
    error = err;
}// default token error constructor

