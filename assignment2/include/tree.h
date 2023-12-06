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
        node () : left(nullptr), right(nullptr), 
                id(INVALID), tokenChar(emptyStr), 
                index(0), seen(false) {};
        node (const tokenId id, const std::string tokenChar) : 
                left(nullptr), right(nullptr), 
                id(id), tokenChar(tokenChar), 
                index(0), seen(false) {};

        node* left;
        node* right;

        tokenId id;
        std::string tokenChar;

        int index;
        bool seen;
};

class tree{
    public:
        tree() : begin(nullptr) {};
        ~tree();

        void clearTree();
        void deleteNode(node* & walker) const;
        node* getBegin() const {return this->begin;};

        bool isEmpty(const node* leaf) const {return (leaf == nullptr);};
        bool isOperator(node* node) const;
        bool makeNode(const tokenId id, const std::string tokenChar, node* &walker, const int index);
        void makeTree(tokenList &list);

        void printRecursion(node* &walker, std::string &output);
        void printTree();

        tokenList* infixToPrefix(tokenList &list);

        void recursionCorrectTree(node* &walker);
        void correctTree();

        void saveDOT(const std::string file) const;
        void labelTree(node* &walker, std::ofstream &file) const;
        void recursionDOT(node* &walker, std::ofstream &file) const;
    private:
        node* begin;
};

#endif