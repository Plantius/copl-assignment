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

// Tokenizes a given string, and parses it
int main(int argc, char* argv[]){
    tree parseTree;
    
    parser parse(parseTree); 
    std::string input = emptyStr, filepath = "NULL";
    bool debug = false;

    if (argc >= 2 && std::string(argv[1]) == "d"){
        filepath = std::string(argv[2]);
        debug = true;
    }

    try{
        while (getline(std::cin >> std::ws, input)){
            try
            {
                if (validInput(input)){
                    // Checks if any errors are thrown from the stringTokenizer function
                    parse.stringTokenizer(input);
                    if (debug){
                        parse.debugTree((validInput(filepath) ? filepath : "NULL"));
                    }
                    input.clear();
                }else {
                    throw inputError("Contains non-standard ASCII characters");
                }
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