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
using namespace std;

// Reads the file and writes it to a string
string readInput(string & filepath){
    cout << "Enter the path of the file: ";
    cin >> filepath;

    // Checks if the given input-string contains only ASCII characters
    validInput(filepath);
    cout << "Reading from " << filepath << ":" <<endl;
    return readFile(filepath);
}// readInput

void menuChoice(){
    cout << endl << "0: Input a file to be parsed" << endl;
    cout << "1: Exit the program" << endl;
}// menuChoice

// Tokenizes a given string, and parses it
int main(){
    clock_t t1, t2;
    tokenList list;
    int clockCount = 0, count = 0, nr = 1000;
    parser parse; 

    string input = emptyStr, filepath = "NULL";
    int option = 0;
    
    try{
        while(option != 1){
            menuChoice();
            cout << "Enter an option: ";
            if(!(cin >> option)){
                throw inputError("Invalid option");
            }

            // Switch statement to choose the required option
            switch (option)
            {
            case 0: // Reads the given file, and parses it
                input = readInput(filepath);

                validInput(input);
                t1 = clock();
                // Checks if any errors are thrown from the stringTokenizer function
                parse.stringTokenizer(input, list);
                t2 = clock();
                cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
        
                parse.setRowcol(1, 1);
                list.clear();
                break;
            case 1: // Exits the program
                cout << "Exit program" << endl;
                break;

            case 2:
                cout << "Running test" << endl;
                filepath = "../tests/in";
                input = readFile(filepath);
                while (count < nr){
                    t1 = clock();
                    // Checks if any errors are thrown from the stringTokenizer function
                    parse.stringTokenizer(input, list);
                    t2 = clock();
                    parse.setRowcol(1, 1);
                    list.clear();
                    clockCount += t2-t1;
                    count++;
                }
                cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
                cout << "Average " << (((double)(clockCount/nr))/CLOCKS_PER_SEC) << " in " << int(clockCount/nr) << " ticks"<< endl; 
                clockCount = 0, count = 0;
                
                break;

            default:
                cout << "Invalid input, try again." << endl;
                break;
            }
        }
    }catch(memoryError & error){
        printError<memoryError>(error, filepath);
        return EXIT_FAILURE;
    }catch(syntaxError & error){
        printError<syntaxError>(error, filepath);
        return EXIT_FAILURE;
    }catch(tokenError & error){
        printError<tokenError>(error, filepath);
        return EXIT_FAILURE;
    }catch(inputError & error){
        printError<inputError>(error, filepath);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}// main