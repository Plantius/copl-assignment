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

        void alphaConversion(node* &start) const;
        void betaReduction(node* &start, tree &T) const;
        void makeAbstract(tree &T) const;

        void findBeta(node* &walker, node* &startApplication, bool &betaPossible) const;
        void findVar(node* &start, std::set<std::string> &varList) const;
        void replaceFreeVar(node* &start, std::set<std::string> &varList, const std::string replaceVar) const;

        bool isInTree(node* &walker, const std::string letter, bool where, node* & whereVar) const;

    private:
};

#endif