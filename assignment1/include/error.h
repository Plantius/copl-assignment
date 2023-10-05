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

class errorHandler{
    public:
        errorHandler();
        std::string getError();
    protected:
        std::string error;
};

class memoryError : public errorHandler{
    public:
        memoryError(const std::string err);
};

class syntaxError : public errorHandler{
    public:
        syntaxError(const std::string err);
};

#endif