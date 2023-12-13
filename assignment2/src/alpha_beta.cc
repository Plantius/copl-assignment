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

bool alphaBeta::betaReduction(node* & start, tree &T){
    std::string x = "$";
    bool needsBeta = false;
    node* walker = nullptr;
    node* whereWalker = nullptr;
    node* copy = nullptr;

    if(start->id == APPLICATION){
        if(start->left->id == LAMBDA){
            // LINKER BOOM VAN APP
            x = start->left->left->tokenChar;
            walker = start->left->right;
            // maar enkele variabele
            if (walker == nullptr){
                if(walker->tokenChar == x){
                    whereWalker = walker;
                    needsBeta = true;
                }
            }
            // door subboom kijken
            else{
                needsBeta = isInTree(walker, x, true, whereWalker);
              
            }

            if(needsBeta){
                T.copyTree(copy, start->right);
                whereWalker->id = copy->id;
                whereWalker->tokenChar = copy->tokenChar;
                if (copy!=nullptr){
                    whereWalker->left = copy->left;
                    whereWalker->right = copy->right;
                }
                delete copy;
                copy = nullptr;
                
            }
        }
    }
    walker = nullptr;
    whereWalker = nullptr;

    return false;
} // betaReduction

void alphaBeta::alphaConversion(node* &start){
    if (start == nullptr){
        return;
    }
    std::set<std::string> varList, allVar;
    node* temp = start;

    // find @ lambda
    // findAlpha(temp);
    if (temp->id == APPLICATION){
        if(temp->left->id == LAMBDA){
            findVar(temp->right, varList);
            for (auto i : varList){
                cout << i;
            }cout << endl;
            
            replaceFreeVar(temp->left->right, varList);
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