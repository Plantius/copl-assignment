/**
* Implementation of the main function
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* main.cc
* 15-09-2023
**/ 

#include "../include/standard.h"
#include "../include/parser.h"
#include "../include/token.h"
using namespace std;

// Reads the file and writes it to a string
string readInput(string filepath){
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
    string input = "", filepath = "";
    parser parse; 
    int option = 0;
    try{
        while(option != 1){
            menuChoice();
            cout << "Enter an option: ";
            cin >> option;

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
        
                list.clear();
                break;
            case 1: // Exits the program
                cout << "Exit program" << endl;
                break;
            default:
                cout << "Invalid input, try again." << endl;
                break;
            }
        }
    }catch(const string error){
        printError(error);
        return 1;
    }
    return 0;
}// main