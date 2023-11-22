/**
* Implementation of the alpha conversion 
  and beta reduction.
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* alpha_beta.cc
* 15-11-2023
**/ 

#include "../include/standard.h"
#include "../include/error.h"
#include "../include/alpha_beta.h"
#include <fstream>
using namespace std;

alpha_beta::alpha_beta(){

} // constructor

void alpha_beta::makeAbstract(node* begin,  tokenList & L){
    bool done = false;
    if(needsBeta(begin, L)){
        if(needsAlpha(begin, L)){
            performConversion(begin);
        }
        done = performReduction(begin);
        if(!done){
            cout << "There went something wrong." << endl;
        }
    }

} // makeAbstract

bool alpha_beta::needsBeta(node* begin, tokenList & L){
    char x;
    int M;
    int N;
    L.setIndex(0);
    for(int i=0; i < L.getLength(); i++){
        if (L.getToken(i)->id == LAMBDA){
            x = L.peekToken();

        }
    }

    return true;
} // needsBeta


bool alpha_beta::needsAlpha(node* begin, tokenList & L){

    return true;

} // needsAlpha

bool alpha_beta::performReduction(node* begin){

    return true;

} // performReduction

bool alpha_beta::performConversion(node* begin){

    return true;
    
} //performConversion