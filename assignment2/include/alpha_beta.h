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

class alpha_beta{
    public:
        alpha_beta() : M(), N(), x(emptyStr) {};

        bool performReduction(tokenList &L);
        void needsAlpha(node* &start);
        bool needsBeta(node* &start, tree &T);
        void makeAbstract(tokenList &L, tree &T);

        void findVar(node* &start, std::set<std::string> &varList) const;

    private:
        tokenList M;
        tokenList N;
        std::string x;
};

#endif