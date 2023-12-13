/**
* Implementation of the alpha conversion 
  and beta reduction.
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* alphaBeta.cc
* 15-11-2023
**/ 

#include "../include/standard.h"
#include "../include/error.h"
#include "../include/alpha_beta.h"
#include <fstream>
using std::cout, std::endl;

void alphaBeta::makeAbstract(tokenList &L, tree &T){
    node* start = T.getBegin();
    bool done = true;
    int times = 0;
    alphaConversion(start);
    // beta
    // Find var of left lambda
    // Copy right subtree of application
    // Walk through right side of left lambda, replace all lambda
    // var with subtree
    // 

    // while(done){
    //     done = false;
    //     // if(needsBeta(L)){
    //         // done = performReduction(L);
    //         // M.clear();
    //         // N.clear();
    //         times ++;
    //     // }
    //     if (times >= MAX_IT){
    //         done = false;
    //     }
    // }

} // makeAbstract

bool alphaBeta::needsBeta(node* & start, tree &T){
    x = "$";
    node* walker = nullptr;
    if(start->id == APPLICATION){
        if(start->left->id == LAMBDA){
            x = start->left->left->tokenChar;
            walker = start->left->right;
            // maar enkele variabele
            if (walker == nullptr){
                if(walker->tokenChar == x){

                }
            }
            // door subboom kijken
            else{
                
            }
        }
    }
   
   // ***********************************************************
   
    // L.setIndex(0);
    // M.setIndex(0);
    // N.setIndex(0);
    // int i = 0;

    // if(T.isEmpty(T.getBegin())){
    //     return false;
    // }

    // while(i < L.getLength()){
    //     if (L.getToken(i)->id == LAMBDA){
    //         x = L.peekToken();
    //         i++;
    //     }
    //     else if (x != "$" ){
    //         int j=0;
    //         while ((L.getToken(i)->id != RPAR) && (i < L.getLength())){
    //             M.insertToken(L.getToken(i)->id, L.getToken(i)->tokenChar, j);
    //             i++;
    //             j++;
    //         } // while M'

    //         j = 0;

    //         if (i < L.getLength()){
    //             while (i < L.getLength()){
    //                 N.insertToken(L.getToken(i)->id, L.getToken(i)->tokenChar, j);
    //                 i++;
    //                 j++;
    //             } // while N
    //             return true;
    //         }
    //     }else {
    //         i++;
    //     }
    // } // while L
    // return false;
} // needsBeta

// NOG NIET GOED    
void alphaBeta::alphaConversion(node* &start){
    if (start == nullptr){
        return;
    }
    std::set<std::string> varList, allVar;
    node* temp = start;

    // find @ lambda
    findAlpha(temp);
    if (temp->id == APPLICATION){
        if(temp->left->id == LAMBDA){
            findVar(temp->right, varList);
            for (auto i : varList){
                cout << i;
            }cout << endl;
            
            replaceFreeVar(temp, varList);
            // // findfreevar
            // // For every lambda right of application, 
            // // if lambda var in set, remove from set
            // // replacefreevar
            // // For every var in set, if applicatoon left lambda right 
            // // replace with new var 
          
        }
     }
} // alphaConversion


void alphaBeta::findAlpha(node* &walker) {

}// findAlpha


void alphaBeta::replaceFreeVar(node* &start, std::set<std::string> &varList){
    if (start == nullptr){
        return;
    }

    if (start->id == LAMBDA && isInTree(start->right, start->left->tokenChar, false, start)){
        for (auto i : varList){
            if (start->left->tokenChar == i){
                start->left->tokenChar = (i+i);
            }
        }
    }
    replaceFreeVar(start->left, varList);
    replaceFreeVar(start->right, varList);

}


void alphaBeta::findVar(node* &start, std::set<std::string> &varList) const{
    if (start  == nullptr){
        return;
    }
    
    if (start->id == VAR){
        varList.insert(start->tokenChar);
    }
    
    findVar(start->left, varList);
    findVar(start->right, varList);
    if (start->id == LAMBDA){
        if (varList.find(start->left->tokenChar) != varList.end()){
            varList.erase(start->left->tokenChar);
        }
    }
}// findVar


bool alphaBeta::isInTree(node* &walker, const std::string letter, bool where, node* & whereVar) const{
    if (walker == nullptr){
        return false;
    }
    if (walker->id == VAR && walker->tokenChar == letter){
        if (where){
            whereVar = walker;
            where = false;
        }
        return true;
    }
    if (isInTree(walker->left, letter, where, whereVar)){
        return true;
    }
    if (isInTree(walker->right, letter, where, whereVar)){
        return true;
    }
    return false;
    
}


bool alphaBeta::performReduction(tokenList & L){

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
