/**
* Implementation of the tree functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* tree.cc
* 01-11-2023
**/ 

#include "../include/tree.h"
#include "../include/error.h"
#include "../include/standard.h"
#include <stack>
#include <fstream>
using std::cout, std::endl;

tree::~tree(){
    deleteNode(this->begin);
    begin = nullptr;
}// Destructor


void tree::clearTree(){
    deleteNode(begin);
    begin = nullptr;
}// clearTree


// Verwijdert recursief alle takken
void tree::deleteNode(node* & walker) const{
    if (walker == nullptr){
        return;
    }

    deleteNode(walker->left);
    deleteNode(walker->right);

    delete walker;
}// verwijderTak


bool tree::isOperator(node* node) const {
    if (node != nullptr){
        if (node->id == LAMBDA || node->id == APPLICATION || node->id == LPAR || node->id == RPAR){
            return true;
        }
    }
    return false;
}// isOperator


/* 
===========================================================
                        MAKE TREE
===========================================================
*/


void tree::makeTree(tokenList &list){
    tokenList* prefix = nullptr;
    token* temp = nullptr;
    node* walker = nullptr;
    clearTree();

    prefix = infixToPrefix(list);
    for (int i = 0; i < prefix->getLength(); i++){
        temp = prefix->getToken(i);
        if (temp->id == EOL){
            continue;
        }
        makeNode(temp->id, temp->tokenChar, walker, begin, i);
    }
    correctTree();

    delete prefix;
} // makeTree 


tokenList* tree::infixToPrefix(tokenList &list){
    tokenList* prefix = new tokenList;
    token* temp = nullptr;
    std::stack<token*> tokenStack;

    list.reverseList();
    for(int i = 0; i < list.getLength(); i++){
        temp = list.getToken(i);
        if (temp->id == VAR){
            prefix->addToken(temp->id, temp->tokenChar);
        }else if (temp->id == LPAR){
            tokenStack.push(temp);
        }else if (temp->id == RPAR){
            while (tokenStack.top()->id != LPAR){
                prefix->addToken(tokenStack.top()->id, tokenStack.top()->tokenChar);
                tokenStack.pop();
            }
            tokenStack.pop();
        }else{
            while(!tokenStack.empty() && temp->id == APPLICATION && tokenStack.top()->id == LAMBDA){
                prefix->addToken(tokenStack.top()->id, tokenStack.top()->tokenChar);
                tokenStack.pop();
            }
            if (temp->id != EOL){
                tokenStack.push(temp);
            }
        }
    }
    while(!tokenStack.empty()){
        prefix->addToken(tokenStack.top()->id, tokenStack.top()->tokenChar);
        tokenStack.pop();
    }
    prefix->reverseList();
    return prefix;
}// infixToPrefix


bool tree::makeNode(const tokenId id, const std::string tokenChar, node* &walker, node* &start, const int index){
    bool var = false;

    if (isEmpty(walker) && isEmpty(start)){
       // If the tree is empty, the tree makes the first element
        start = new node(id, tokenChar);
        start->index = index;
        walker = start;
        return true;
    }
    if (isOperator(walker)){
        if(walker->left != nullptr){
            var = makeNode(id, tokenChar, walker->left, start, index);
        }else{
            walker->left = new node(id, tokenChar);
            walker->left->index = index;
            return true;
            }
        if(!var){
            if (walker->right != nullptr){
                var = makeNode(id, tokenChar, walker->right, start, index);
            }else{
                walker->right = new node(id, tokenChar);
                walker->right->index = index;
                return true;
            }
            return var;
        }else {
            return true;
        }
    }
    return false;
}// makeNode


/* 
===========================================================
                        PRINT TREE
===========================================================
*/


void tree::printRecursion(node* & walker, std::string &output){
    if (walker == nullptr){
        return;
    }
    if (walker->id == APPLICATION || walker->id == LAMBDA){
        output += "(";
    }

    if (walker->id == LAMBDA){
        output += walker->tokenChar + walker->left->tokenChar + " ";
        printRecursion(walker->right, output);
    }else {
        printRecursion(walker->left, output);

        if (walker->id != APPLICATION){
            output += walker->tokenChar;
        }else {
            output += " ";
        }
        printRecursion(walker->right, output);
    }
    if (walker->id == APPLICATION || walker->id == LAMBDA){
        output += ")";
    }
}// printRecursion


void tree::printTree() {
    node* walker = begin;
    std::string output = emptyStr;

    printRecursion(walker, output);
    if (output.back() == ')'){
        output.pop_back();
    }if (output[0] == '('){
        output.erase(0, 1);
    }
    cout << output << endl;
}// printTree


/* 
===========================================================
                        COPY TREE
===========================================================
*/

void tree::recursionCopy(node* &walker, node* &copyWalker, node* &copyStart){
    if (walker == nullptr){
        return;
    }
    makeNode(walker->id, walker->tokenChar, 
             copyWalker, copyStart, walker->index);
    
    recursionCopy(walker->left, copyWalker, copyStart);
    recursionCopy(walker->right, copyWalker, copyStart);
} // recursionCopy

void tree::copyTree(node* &copyStart, node* start){
    node* walker = start;
    node* copyWalker = copyStart;
    
    recursionCopy(walker, copyWalker, copyStart);
} // copyTree


/* 
===========================================================
                        CORRECT TREE
===========================================================
*/


void tree::recursionCorrectTree(node* &walker){
    node* help = nullptr;
    if (walker == nullptr){
        return;
    }
    recursionCorrectTree(walker->left);
    recursionCorrectTree(walker->right);
    if ((walker->id == LAMBDA || walker->id == APPLICATION) && 
        (walker->left == nullptr || walker->right == nullptr)){
        
        if (walker->right != nullptr){
            help = walker->right;
            walker->left = help->left;
            walker->right = help->right;
        }else if (walker->left != nullptr){
            help = walker->left;
            walker->left = help->left;
            walker->right = help->right;
        }
        walker->id = help->id;
        walker->index = help->index;
        walker->tokenChar = help->tokenChar;
        delete help;
    }
}// recursionCorrectTree


void tree::correctTree(){
    node* walker = this->begin;
    recursionCorrectTree(walker);
}// correctTree


/* 
===========================================================
                        DOT NOTATION
===========================================================
*/


void tree::recursionDOT(node* &walker, std::ofstream &file) const{
    if (walker->id == LAMBDA || walker->id == APPLICATION){
        if(walker->left != nullptr){
            if(!walker->seen){
                file << walker->index << " -> ";
            }
            walker->seen = true;
            recursionDOT(walker->left, file);
        }
        file << walker->index << " -> ";
        if (walker->right != nullptr){
            if(!walker->seen){
                file << walker->index << ";\n\t";
            }
            walker->seen = true;
            recursionDOT(walker->right, file);
        }
    }else {
        if (!walker->seen){
            file << walker->index << ";\n\t";
        }
        walker->seen = true;
    }
}// loopBoom


void tree::labelTree(node* &walker, std::ofstream &file) const{
    if(walker == nullptr){
        return;
    }
    if (walker->id == LAMBDA){
        file << "\t" << walker->index << " [label = " <<"\""<<walker->seen<< "\u03bb" << walker->index << "\"];\n"; 
    }else {
        file << "\t" << walker->index << " [label = " << "\"" <<walker->seen<< walker->tokenChar << walker->index <<"\"];\n";
    }
    walker->seen = false;
    
    labelTree(walker->left, file);
    labelTree(walker->right, file);
}// labelnode


void tree::saveDOT(const std::string filenaam) const{
    node* walker = begin;
    if (begin != nullptr){
        std::ofstream file(filenaam);
        if(file.is_open()){
            file << "digraph tree{\n";
            labelTree(walker, file); 
            file << "\t";
            walker = begin;
            recursionDOT(walker, file);
            file << "\n}";
            file.close();
        }
    }else {
        throw inputError("The tree is empty.");
    }
}// opslaanDOT