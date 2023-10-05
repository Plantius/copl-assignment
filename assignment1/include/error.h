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
    protected:
        std::string error;
};// errorHandler

// Handles memory errors
class memoryError : public errorHandler{
    public:
        memoryError(const std::string err);
};// memoryError

// Handles syntax errors
class syntaxError : public errorHandler{
    public:
        syntaxError(const std::string err);
};// syntaxError

// Handles tokenization errors
class tokenError : public errorHandler{
    public:
        tokenError(const std::string err);
};// tokenError

// Handles input errors
class inputError : public errorHandler{
    public:
        inputError(const std::string err);
};// inputError

#endif