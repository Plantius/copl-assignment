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
#include "../include/tree.h"

class alpha_beta{
    public:
        alpha_beta();
        bool performConversion(node* begin);
        bool performReduction(node* begin);
        bool needsAlpha(node* begin, tokenList & L);
        bool needsBeta(node* begin, tokenList & L);
        void makeAbstract(node* begin, tokenList & L);

    private:
        tree T;
        tokenList M;
        tokenList N;
        std::string x;


};

#endif