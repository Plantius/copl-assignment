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
using std::cout, std::endl;

alpha_beta::alpha_beta(){

} // constructor

void alpha_beta::makeAbstract(tokenList &L){
    bool done = true;
    int times = 0;
    while(done){
        done = false;
        if(needsBeta(L)){
            if(needsAlpha(L)){
                performConversion();
            }
            done = performReduction(L);
            times ++;
        }
        if (times >= MAX_IT){
            done = false;
        }
    }

} // makeAbstract

bool alpha_beta::needsBeta(tokenList &L){
    x = "$";
    L.setIndex(0);
    M.setIndex(0);
    N.setIndex(0);
    int i = 0;

    while(i < L.getLength()){
        if (L.getToken(i)->id == LAMBDA){
            x = L.peekToken();
            i++;
        }
        else if (x != "$" ){
            int j=0;
            while ((L.getToken(i)->id != RPAR) && (i < L.getLength())){
                M.insertToken(L.getToken(i)->id, L.getToken(i)->tokenChar, j);
                i++;
                j++;
            } // while M'

            j = 0;

            if (i < L.getLength()){
                while (i < L.getLength()){
                    N.insertToken(L.getToken(i)->id, L.getToken(i)->tokenChar, j);
                    i++;
                    j++;
                } // while N
                return true;
            }
        }else {
            i++;
        }
    } // while L
    return false;
} // needsBeta


bool alpha_beta::needsAlpha(tokenList &L){
    if (needsBeta(L)){
        for (int i = 0; i < N.getLength(); i++){
            if (x == N.getToken(i)->tokenChar){
                return true;
            }
        }
    }

    return false;

} // needsAlpha

bool alpha_beta::performReduction(tokenList & L){

    for (int i = 0; i < M.getLength(); i++){
        if (M.getToken(i)->tokenChar == x){
            for (int j = 0; j < N.getLength(); j++){
                M.insertToken(N.getToken(i)->id, N.getToken(i)->tokenChar, i);
            }
            M.deleteToken(i);
        }
    }

    L.clear();
    for (int k = 0; k < M.getLength(); k++){
        L.addToken(M.getToken(k)->id, M.getToken(k)->tokenChar);
    }

    return true;
} // performReduction

bool alpha_beta::performConversion(){

    return true;
    
} //performConversion