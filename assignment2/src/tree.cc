/**
* Implementation of the tree functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* tree.cc
* 01-11-2023
**/ 

#include "../include/tree.h"
#include "../include/token.h"
#include "../include/tokenId.h"
#include "../include/error.h"
using namespace std;


node::node(){
    left = nullptr;
    right = nullptr;
}// Default constructor

tree::tree(){
    begin = nullptr;
}// Default constructor

tree::~tree(){

}// Destructor

bool tree::isEmpty() const{
    if (begin == nullptr){
        return true;
    }
    return false;
}// isEmpty

bool tree::isOperator(const node* node) const {
    return false;
}// isOperator

bool tree::makeNode(tokenId id, node* & index){
    bool var = false;

    if (isEmpty()){
       // Als de boom leeg is, begint de boom met het eerste element
        begin = new node;
        begin->id = id;
        index = begin;
        return true;
    }

    if (isOperator(index)){
        if(index->left != nullptr){
            var = makeNode(id, index->left);
        }else{
            index->left = new node;
            index->left->id = id;
            return true;
            }
        if(!var){
            if (index->right != nullptr){
                var = makeNode(id, index->right);
            }else{
                index -> right = new node;
                index -> right -> id = id;
                return true;
            }
            return var;
        }else {
            return true;
        }
    }
    return false;
}// makeNode