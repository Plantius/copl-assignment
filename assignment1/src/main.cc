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
#include <memory>
using namespace std;

void menuChoice(){
    cout << endl << "0: Input a file to be parsed" << endl;
    cout << "1: Exit the program" << endl;
}// menuChoice


int main(){
    clock_t t1, t2;
    tokenList list;
    string input = "", filepath = "";
    parser parse; 
    int option = 0;
    
    while(option != 1){
        menuChoice();
        cout << "Enter an option: ";
        cin >> option;

        // Switch statement to choose the required option
        switch (option)
        {
        case 0: // Reads the given file, and parses it
            cout << "Enter the path of the file: ";
            cin >> filepath;
            if (validInput(filepath)){
                cout << "Reading from " << filepath << ":" <<endl;
                input = readFile(filepath);
                cout << input << endl;
                if(validInput(input)){
                    t1 = clock();
                    parse.stringTokenizer(input, list);
                    t2 = clock();

                    cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
                    if(parse.getError()){
                        return 1;
                    }
                }
            }
            break;
        case 1: // Exits the program
            cout << "Exit program" << endl;
            break;
        default:
            cout << "Invalid input, try again." << endl;
            break;
        }
    }
    return 0;
}// main