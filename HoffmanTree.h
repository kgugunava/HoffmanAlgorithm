#ifndef HOFFMANTREE_H
#define HOFFMANTREE_H
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class HoffmanTree {
public:
    HoffmanTree(const char* fileName);

    void inorderWalk(Node* node, string code);

    Node* getRoot()const{return root;}

private:
    Node* root;
};


#endif //HOFFMANTREE_H
