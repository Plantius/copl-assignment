/**
* Declaration of the alpha concersion and beta reduction
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* alpha_beta.h
* 15-11-2023
**/

#ifndef ALPHA_BETA_H
#define ALPHA_BETA_H    
#include <iostream>
#include <set>
#include "../include/tree.h"

class alphaBeta{
    public:
        alphaBeta() {};

        void alphaConversion(node* &start);
        bool betaReduction(node* &start, tree &T);
        void makeAbstract(tokenList &L, tree &T);

        void findAlpha(node* &walker);
        void findVar(node* &start, std::set<std::string> &varList) const;
        void replaceFreeVar(node* &start, std::set<std::string> &varList);

        bool isInTree(node* &walker, const std::string letter, bool where, node* & whereVar) const;

    private:
};

#endif