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

}// defaul constructor

string errorHandler::getError(){
    return error;
}// getError

memoryError::memoryError(const string err){
    error = err;
}// default memory error constructor

syntaxError::syntaxError(const string err){
    error = err;
}// default syntax error constructor

tokenError::tokenError(const string err){
    error = err;
}// default token error constructor

inputError::inputError(const string err){
    error = err;
}// default token error constructor