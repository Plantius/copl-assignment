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
#include "../include/tokenId.h"

class node{
    public:
        node();

        node* left;
        node* right;

        tokenId id;
        std::string tokenChar;
};

class tree{
    public:
        void deleteNode(node* & walker) const;
        node* getBegin();

        bool isEmpty(node* leaf) const;
        bool isOperator(const node* node) const;
        bool makeNode(const tokenId id, const std::string nodeChar, node* & walker);
        void makeTree();
        void deleteNode() const;

        void printRecursion(node* & walker);
        void printTree();
    private:
        node* begin;
};

#endif