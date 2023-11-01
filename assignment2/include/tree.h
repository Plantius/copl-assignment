/**
* Declaration of the tree class
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* tree.h
* 01-11-2023
**/

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "../include/parser.h"

class node{
    public:
        node ();

        node* left;
        node* right;

        tokenId id;
        std::string tokenChar;
};

class tree{
    public:
        tree();
        ~tree();

        bool isEmpty() const;
        bool isOperator(const node* node) const;
        bool makeNode(const tokenId id, node* & index);
        void makeTree();
        void deleteNode() const;
        void printTree() const;


    private:
        node* begin;
};

#endif