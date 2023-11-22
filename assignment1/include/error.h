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
        errorHandler() : error(""), row(0), col(0) {};
        errorHandler(const std::string err) : error(err) {};
        std::string getError() const {
            return error;};
        int getRow() const { 
            return row;};
        int getCol() const {
            return col;};
        std::string getType() const 
            {return type;};

    protected:
        std::string error;
        std::string type;
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
                    const int r, const int c);
};// syntaxError

// Handles tokenization errors
class tokenError : public errorHandler{
    public:
        tokenError(const std::string err, 
                    const int r, const int c);
};// tokenError

// Handles input errors
class inputError : public errorHandler{
    public:
        inputError(const std::string err);
};// inputError

// Prints the given error to cerr
template<class C>
void printError(C error, const std::string filepath){
    std::cerr << std::string((error.getError()).length(), '-') << std::endl 
         << filepath << ": "<< error.getRow() << ":" << error.getCol() <<": " << error.getType() 
         << "\n\t " << error.getError() << std::endl << std::string((error.getError()).length(), '-') << std::endl;
}// printError

#endif