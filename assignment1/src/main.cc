/**
* Implementation of the main function
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* main.cc
* 05-10-2023
**/ 

#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
#include "../include/error.h"
#include <fstream>
using namespace std;

// Tokenizes a given string, and parses it
int main(int argc, char* argv[]){
    clock_t t1, t2;
    parser* parse = new parser; 
    string input = emptyStr, filepath = "NULL";
    bool debug = false;
    
    if(argc < 2){
        delete parse;
        return 2;
    }else if (string(argv[1]) == "d"){
        debug = true;
    }

    try{
        if (!debug){
            filepath = string(argv[1]);
            ifstream file(filepath);
            if(!file.good() || !file.is_open()){
                throw inputError("File does not exist or is corrupted");
            }
            while (getline(file, input)){
                validInput(input);
                t1 = clock();
                // Checks if any errors are thrown from the stringTokenizer function
                parse->stringTokenizer(input);
                input.clear();
                t2 = clock();
                cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
            }
            
            t1 = clock();
            // Checks if any errors are thrown from the stringTokenizer function
            parse->stringTokenizer(input);
            t2 = clock();
            cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
        }else {
            while (getline(cin >> ws, input)){
                validInput(input);
                t1 = clock();
                // Checks if any errors are thrown from the stringTokenizer function
                parse->stringTokenizer(input);
                t2 = clock();
                cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
                input.clear();
            }
        }
    }
    catch(memoryError & error){
        printError<memoryError>(error, filepath);
        delete parse;
        return EXIT_FAILURE;
    }catch(syntaxError & error){
        printError<syntaxError>(error, filepath);
        delete parse;
        return EXIT_FAILURE;
    }catch(tokenError & error){
        printError<tokenError>(error, filepath);
        delete parse;
        return EXIT_FAILURE;
    }catch(inputError & error){
        printError<inputError>(error, filepath);
        delete parse;
        return EXIT_FAILURE;
    }
    delete parse;
    return EXIT_SUCCESS;
}// main