/**
* Implementation of the tree functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* tree.cc
* 04-10-2023
**/ 

#include "../include/standard.h"
#include "../include/error.h"
#include "../include/tree.h"
using namespace std;

node::node(){
    left = nullptr;
    right = nullptr;
    id = INVALID;
    tokenChar = invalidChar;
}// Default constructor


// Verwijdert recursief alle takken
void tree::deleteNode(node* & walker) const{
    if (walker == nullptr){
        return;
    }

    deleteNode(walker->left);
    deleteNode(walker->right);

    delete walker;
}// verwijderTak

node* tree::getBegin(){
    return begin;
}

bool tree::isEmpty(node* leaf) const{
    if (leaf == nullptr){
        return true;
    }
    return false;
}// isEmpty

bool tree::isOperator(const node* node) const {
    if (node != nullptr){
        if (node->id != VAR && node->id != EOL && node->id != INVALID){
            return true;
        }
    }
    return false;
}// isOperator

bool tree::makeNode(const tokenId id, const std::string nodeChar, node* & walker){
    bool var = false;

    if (isEmpty(walker) && isEmpty(begin)){
       // Als de boom leeg is, begint de boom met het eerste element
        begin = new node;
        begin->id = id;
        begin->tokenChar = nodeChar;
        walker = begin;
        return true;
    }

    if (isOperator(walker)){
        if(walker->left != nullptr){
            var = makeNode(id, nodeChar, walker->left);
        }else{
            walker->left = new node;
            walker->left->id = id;
            walker->left->tokenChar = nodeChar;
            return true;
            }
        if(!var){
            if (walker->right != nullptr){
                var = makeNode(id, nodeChar, walker->right);
            }else{
                walker -> right = new node;
                walker -> right -> id = id;
                walker->right->tokenChar = nodeChar;
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

    cout << walker->tokenChar;

    printRecursion(walker->left);
    printRecursion(walker->right);
}// printRecursion

void tree::printTree() {
    node* walker = begin;

    printRecursion(walker);
    cout << endl;
}// printTree