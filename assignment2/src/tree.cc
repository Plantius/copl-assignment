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
using namespace std;

tree::tree(){
    begin = nullptr;
}// Default constructor

tree::~tree(){
    deleteNode(begin);
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

node* tree::getBegin() const{
    return begin;
}

bool tree::isEmpty(const node* leaf) const{
    if (leaf == nullptr){
        return true;
    }
    return false;
}// isEmpty

bool tree::isOperator(node* node) const {
    if (node != nullptr){
        if (node->id == LAMBDA || node->id == SPACE || node->id == LPAR || node->id == RPAR){
            return true;
        }
    }
    return false;
}// isOperator

tokenList* tree::infixToPrefix(tokenList &list){
    tokenList* prefix = new tokenList;
    token* temp = nullptr;
    stack<token*> tokenStack;

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
            while(!tokenStack.empty() && temp->id == SPACE && tokenStack.top()->id == LAMBDA){
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


bool tree::treeFull(node* & walker){
    if (walker == nullptr){
        return false;
    }
    if ((walker->left == nullptr && isOperator(walker->left)) \
        	|| (walker->right == nullptr && isOperator(walker->right))){
        return false;
    }

    treeFull(walker->left);
    treeFull(walker->right);

    return true;
} // treeFull


bool tree::makeNode(const tokenId id, const std::string tokenChar, node* &walker, const int index){
    bool var = false;

    if (isEmpty(walker) && isEmpty(begin)){
       // If the tree is empty, the tree makes the first element
        begin = new node(id, tokenChar);
        begin->index = index;
        walker = begin;
        return true;
    }
    if (isOperator(walker)){
        if(walker->left != nullptr){
            var = makeNode(id, tokenChar, walker->left, index);
        }else{
            walker->left = new node(id, tokenChar);
            walker->left->index = index;
            return true;
            }
        if(!var){
            if (walker->right != nullptr){
                var = makeNode(id, tokenChar, walker->right, index);
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

void tree::printRecursion(node* & walker){
    if (walker == nullptr){
        return;
    }
    if (walker->id == LAMBDA){
        cout << walker->tokenChar << walker->left->tokenChar;
        printRecursion(walker->right);
    }else {
        printRecursion(walker->left);
        cout << walker->tokenChar;
        printRecursion(walker->right);
    }
}// printRecursion

void tree::printTree() {
    node* walker = begin;
    printRecursion(walker);
    cout << endl;
}// printTree

void tree::makeTree(tokenList &list){
    tokenList* prefix = nullptr;
    token* temp = nullptr;
    node* walker = nullptr;
    clearTree();

    prefix = infixToPrefix(list);
    for (int i = 0; i < prefix->getLength(); i++){
        temp = prefix->getToken(i);
        makeNode(temp->id, temp->tokenChar, walker, i);
    }
    delete prefix;
} // makeTree 


void tree::recursionDOT(node* &walker, std::ofstream &file) const{
    // Als het node een binaire operator is word left en right verder doorgelopen,  
    // anders is er een unaire operator bereikt, en dus een eind-node
    if (walker->id == LAMBDA || walker->id == SPACE){
        // Als het node een gonio operator is, heeft deze maar 1 rechter kind, dus
        // word alleen right doorgelopen
    
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
        file << "\t" << walker->index << " [label = " << "\"\\" << walker->tokenChar << "\"];\n"; 
    }else {
        file << "\t" << walker->index << " [label = " << "\"" << walker->tokenChar << "\"];\n";
    }
    
    labelTree(walker->left, file);
    labelTree(walker->right, file);
}// labelBlad


void tree::saveDOT(const std::string filenaam) const{
    node* walker = begin;
    int count = 0;
    if (begin != nullptr){
        std::ofstream file(filenaam);
        if(file.is_open()){
            file << "digraph tree{\n";
            labelTree(walker, file); 
            file << "\t";
            walker = begin;
            recursionDOT(walker, file);
            file << "}";
            file.close();
        }
    }else {
        throw inputError("The tree is empty.");
    }
}// opslaanDOT