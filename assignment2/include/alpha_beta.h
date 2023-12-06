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
        alpha_beta() : T(), M(), N(), x(emptyStr) {};
        alpha_beta(tree &T) : T(T), M(), N(), x(emptyStr) {};

        bool performConversion();
        bool performReduction(tokenList &L);
        bool needsAlpha(node* leaf);
        bool needsBeta(tokenList &L);
        void makeAbstract(tokenList &L);

        void findVar(node* &start, std::set<std::string> &varList) const;

    private:
        tree T;
        tokenList M;
        tokenList N;
        std::string x;
};

#endif