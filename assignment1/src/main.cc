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

void menuChoice(){
    cout << endl << "0: Input a file to be parsed" << endl;
    cout << "1: Input a string to be parsed" << endl;
    cout << "2: Exit the program" << endl;
}// menuChoice

// Main menu
void mainMenu(const int option){
    clock_t t1, t2;
    tokenList* list = new tokenList;
    string input = "", filepath = "";
    parser p; 

    switch (option)
    {
    case 0:
        cout << "Enter the path of the file: ";
        cin >> filepath;
        if (validInput(filepath)){
            cout << "Reading from " << filepath << ":" <<endl;
            input = readFile(filepath);
            if(validInput(input)){
                t1 = clock();
                p.stringTokenizer(input, list);
                t2 = clock();

                cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
            }
        }
        break;
    case 1:
        cout << "Enter the string to parse: ";
        getInput(input);
        if(validInput(input)){
            t1 = clock();
            p.stringTokenizer(input, list);
            t2 = clock();

            cout << "Tokenizer " << (((double)(t2-t1))/CLOCKS_PER_SEC) << " in " << (t2-t1) << " ticks"<< endl; 
        }
        break;
    case 2:
        cout << "Exit program" << endl;
        break;
    default:
        break;
    }
    delete list;
}// mainMenu

int main(){
    int option = 0;
    
    while(option != 2){
        menuChoice();
        cout << "Enter an option: ";
        cin >> option;
        mainMenu(option);
    }
    return 0;
}// main