/**
* Implementation of the tree functions
* Niels Versteeg (s3322637)
* Lana van Sprang (s3272192)
* tree.cc
* 01-11-2023
**/ 

#include "../include/tree.h"
#include "../include/error.h"
#include "../include/standard.h"
#include <stack>
using namespace std;

tree::tree(){
    begin = nullptr;
}// Default constructor

tree::~tree(){
    deleteNode(begin);
    begin = nullptr;
}// Destructor

void tree::clearTree(){
    deleteNode(begin);
    begin = nullptr;
}// clearTree

// Verwijdert recursief alle takken
void tree::deleteNode(node* & walker) const{
    if (walker == nullptr){
        return;
    }

    deleteNode(walker->left);
    deleteNode(walker->right);

    delete walker;
}// verwijderTak

node* tree::getBegin() const{
    return begin;
}

bool tree::isEmpty(node* leaf) const{
    if (leaf == nullptr){
        return true;
    }
    return false;
}// isEmpty

bool tree::isOperator(node* node) const {
    if (node == nullptr){
        cout << "WA" << endl;
    }
    if (node != nullptr){
        if (node->id == LAMBDA || node->id == SPACE || node->id == LPAR || node->id == RPAR){
            return true;
        }
    }
    return false;
}// isOperator

tokenList* tree::infixToPrefix(tokenList &list){
    tokenList* prefix = new tokenList;
    token* temp = nullptr;
    stack<token*> tokenStack;

    list.reverseList();
    for(int i = 0; i < list.getLength(); i++){
        temp = list.getToken(i);
        if (temp->id == VAR){
            prefix->addToken(temp->id, temp->tokenChar);
        }else if (temp->id == LPAR){
            tokenStack.push(temp);
        }else if (temp->id == RPAR){
            while (tokenStack.top()->id != LPAR){
                prefix->addToken(tokenStack.top()->id, tokenStack.top()->tokenChar);
                tokenStack.pop();
            }
            tokenStack.pop();
        }else{
            while(!tokenStack.empty() && temp->id == SPACE && tokenStack.top()->id == LAMBDA){
                prefix->addToken(tokenStack.top()->id, tokenStack.top()->tokenChar);
                tokenStack.pop();
            }
            if (temp->id != EOL){
                tokenStack.push(temp);
            }
        }
    }
    while(!tokenStack.empty()){
        prefix->addToken(tokenStack.top()->id, tokenStack.top()->tokenChar);
        tokenStack.pop();
    }
    prefix->reverseList();
    return prefix;
}// infixToPrefix



bool tree::treeFull(node* & walker){
    if (walker == nullptr){
        return false;
    }
    if ((walker->left == nullptr && isOperator(walker->left)) \
        	|| (walker->right == nullptr && isOperator(walker->right))){
        return false;
    }

    treeFull(walker->left);
    treeFull(walker->right);

    return true;
} // treeFull

// bool tree::makeNode(const tokenId id, const std::string nodeChar, node* & walker, node* & start){
//     bool var = false;

//     if (treeFull(walker)){
//         if (nodeChar == "$"){
//             return true;
//         }
//         else{
//             node* new_root = new node;
//             new_root->id = id;
//             new_root->tokenChar = nodeChar;
//             new_root->left = start;
//             new_root->right = nullptr;

//             walker = new_root;
//             return true;
//         }
//     }


//     if (isEmpty(walker) && isEmpty(start)){
//        // If the tree is empty, the tree makes the first element
//         start = new node;
//         start->id = id;
//         start->tokenChar = nodeChar;
//         walker = begin;
//         return true;
//     }

//     if (isOperator(walker)){
//         if(walker->left != nullptr){
//             var = makeNode(id, nodeChar, walker->left, start);
//         }else{
//             walker->left = new node;
//             walker->left->id = id;
//             walker->left->tokenChar = nodeChar;
//             return true;
//             }
//         if(!var){
//             if (walker->right != nullptr){
//                 var = makeNode(id, nodeChar, walker->right, start);
//             }else{
//                 walker -> right = new node;
//                 walker -> right -> id = id;
//                 walker->right->tokenChar = nodeChar;
//                 return true;
//             }
//             return var;
//         }else {
//             return true;
//         }
//     }
//     return false;
// }// makeNode


bool tree::makeNode(const tokenId id, const std::string tokenChar, node* &walker){
    bool var = false;

    if (isEmpty(walker) && isEmpty(begin)){
       // If the tree is empty, the tree makes the first element
        begin = new node(id, tokenChar);
        walker = begin;
        return true;
    }
    if (isOperator(walker)){
        if(walker->left != nullptr){
            var = makeNode(id, tokenChar, walker->left);
        }else{
            walker->left = new node(id, tokenChar);
            return true;
            }
        if(!var){
            if (walker->right != nullptr){
                var = makeNode(id, tokenChar, walker->right);
            }else{
                walker -> right = new node(id, tokenChar);
                return true;
            }
            return var;
        }else {
            return true;
        }
    }
    return false;
}// makeNode

void tree::printRecursion(node* & walker){
    if (walker == nullptr){
        return;
    }
    if (walker->id == LAMBDA){
        cout << walker->tokenChar << walker->left->tokenChar;
        printRecursion(walker->right);
    }else {
        printRecursion(walker->left);
        cout << walker->tokenChar;
        printRecursion(walker->right);
    }
}// printRecursion

void tree::printTree() {
    node* walker = begin;
    printRecursion(walker);
    cout << endl;
}// printTree

void tree::makeTree(tokenList &list){
    tokenList* prefix = nullptr;
    token* temp = nullptr;
    node* walker = nullptr;
    clearTree();

    prefix = infixToPrefix(list);
    for (int i = 0; i < prefix->getLength(); i++){
        temp = prefix->getToken(i);
        makeNode(temp->id, temp->tokenChar, walker);
    }
    delete prefix;
    // prefix.printList();
    // temp = prefix.getBegin();
    // while (temp->next != nullptr){
    //     // makeNode(temp, walker, begin);
    //     cout << (temp == nullptr) << endl;
    //     temp = temp->next;
    // }
    // // rewriting makeNode so that it makes a node based on the type
    // for (int i = 0; i < list.getLength(); i++){
    //     switch (list.getToken(i)->id){
    //     case LPAR:
    //         lparN++;
    //         type = "@";
    //         makeNode(LPAR, type, walker, begin);
    //         break;

    //     case RPAR:
    //         rparN++;
    //         type = "$";
    //         makeNode(RPAR, type, walker, begin);
    //         break;

    //     case LAMBDA:
    //         type = "\\";
    //         makeNode(LAMBDA, type, walker, begin);
    //         break;

    //     case VAR:
    //         if (list.peekToken() == SPACE){
    //             type = "@";
    //             makeNode(SPACE, type, walker, begin);
    //         }
    //         type = list.getToken(i)->tokenChar;
    //         makeNode(VAR, type, walker, begin);
    //         break;

    //     default:
    //         break;
    //     }
    // }
} // makeTree 