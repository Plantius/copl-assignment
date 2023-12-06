/**
* Implementation of the main function
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* main.cc
* 05-10-2023
**/ 

#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/error.h"
#include <fstream>
using std::cout, std::endl;

// Tokenizes a given string, and parses it
int main(int argc, char* argv[]){
    tree T;
    parser parse(T); 
    std::string input = emptyStr, filepath = "NULL";
    bool debug = false;

    if (argc >= 2 && std::string(argv[1]) == "d"){
        debug = true;
    }

    try{
        if (debug){
            filepath = std::string(argv[2]);
        }
       
        while (getline(std::cin >> std::ws, input)){
            try
            {
                validInput(input) ? true : throw inputError("Contains non-standard ASCII characters");
                // Checks if any errors are thrown from the stringTokenizer function
                parse.stringTokenizer(input);
                if (debug){
                    parse.debugTree((validInput(filepath) ? filepath : "NULL"));
                }
                input.clear();
            }
            catch(const parseError error){
                error.printError();
                continue;
            }catch(const inputError error){
                error.printError();
                continue;
            }
        }
    }
    catch(const memoryError error){
        error.printError();
        return EXIT_FAILURE;
    }catch(const tokenError error){
        error.printError();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}// main