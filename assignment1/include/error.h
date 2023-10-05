/**
* Declaration of the error handler
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* error.h
* 05-10-2023
**/

#ifndef ERROR_H
#define ERROR_H
#include <iostream>

// Base error class
class errorHandler{
    public:
        errorHandler();
        std::string getError();
        int getRow();
        int getCol();

    protected:
        std::string error;
        int row, col;
};// errorHandler

// Handles memory errors
class memoryError : public errorHandler{
    public:
        memoryError(const std::string err);
};// memoryError

// Handles syntax errors
class syntaxError : public errorHandler{
    public:
        syntaxError(const std::string err, 
                    const int row, const int col);
};// syntaxError

// Handles tokenization errors
class tokenError : public errorHandler{
    public:
        tokenError(const std::string err, 
                    const int row, const int col);
};// tokenError

// Handles input errors
class inputError : public errorHandler{
    public:
        inputError(const std::string err);
};// inputError

// Prints the given error to cerr
template<class C>
void printError(C error, const std::string filepath, const std::string errType){
    std::cerr << std::string((error.getError()).length(), '-') << std::endl 
         << filepath << ": "<< error.getRow() << ":" << error.getCol() <<": " << errType 
         << "\n\t " << error.getError() << std::endl << std::string((error.getError()).length(), '-') << std::endl;
}// printError

#endif