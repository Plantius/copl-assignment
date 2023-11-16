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
#include "../include/standard.h"
#include "../include/tokenId.h"
#include "../include/token.h"

class node{
    public:
        node () : left(nullptr), right(nullptr), id(INVALID), tokenChar(emptyStr) {};
        node (const tokenId id, const std::string tokenChar) : 
            left(nullptr), right(nullptr), id(id), tokenChar(tokenChar){};

        node* left;
        node* right;

        tokenId id;
        std::string tokenChar;
};

class tree{
    public:
        tree();
        ~tree();
        void clearTree();
        void deleteNode(node* & walker) const;
        node* getBegin() const;

        bool isEmpty(const node* leaf) const;
        bool isOperator(node* node) const;
        bool makeNode(const tokenId id, const std::string tokenChar, node* &walker);
        void makeTree(tokenList &list);
        void deleteNode() const;

        void printRecursion(node* & walker);
        void printTree();

        bool treeFull(node* & walker);
        
        tokenList* infixToPrefix(tokenList &list);

    private:
        node* begin;
};

#endif