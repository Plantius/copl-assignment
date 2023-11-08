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
using namespace std;

node::node(){
    left = nullptr;
    right = nullptr;
    id = INVALID;
    tokenChar = invalidChar;
}// Default constructor

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

bool tree::makeNode(const tokenId id, const std::string nodeChar, node* & walker, node* & start) const{
    bool var = false;

    if (isEmpty(walker) && isEmpty(start)){
       // If the tree is empty, the tree makes the first element
        start = new node;
        start->id = id;
        start->tokenChar = nodeChar;
        walker = begin;
        return true;
    }

    if (isOperator(walker)){
        if(walker->left != nullptr){
            var = makeNode(id, nodeChar, walker->left, start);
        }else{
            walker->left = new node;
            walker->left->id = id;
            walker->left->tokenChar = nodeChar;
            return true;
            }
        if(!var){
            if (walker->right != nullptr){
                var = makeNode(id, nodeChar, walker->right, start);
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

    printRecursion(walker->left);

    cout << walker->tokenChar;
    
    printRecursion(walker->right);
}// printRecursion

void tree::printTree() {
    node* walker = begin;

    printRecursion(walker);
    cout << endl;
}// printTree

void tree::makeTree(tokenList & list, node* & walker){
    clearTree();
    walker = begin;
    int lparN = 0;
    int rparN = 0;
    string type = "$";
    bool parSeen = false; 

    // rewriting makeNode so that it makes a node based on the type
    for (int i = 0; i < list.getLength(); i++){
        switch (list.getToken(i)->id){
        case LPAR:
            lparN++;
            type = "@";
            makeNode(LPAR, type, walker, begin);
            break;

        case RPAR:
            rparN++;
            type = "$";
            makeNode(RPAR, type, walker, begin);
            break;

        case LAMBDA:
            type = "\\";
            makeNode(LAMBDA, type, walker, begin);
            break;
            
        case VAR:
            if (list.peekToken() == SPACE){
                type = "@";
                makeNode(SPACE, type, walker, begin);
            }
            type = list.getToken(i)->tokenChar;
            makeNode(VAR, type, walker, begin);
            break;

        default:
            break;
        }
    }
} // makeTree 