#ifndef HOFFMANTREE_H
#define HOFFMANTREE_H
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include <map>

using namespace std;

class HoffmanTree {
public:
    HoffmanTree(const char* fileName);

    void inorderWalk(Node* node, string code);

    void makeMap(const char* filename);

    Node* getRoot()const{return root;}

private:
    Node* root;
};


#endif //HOFFMANTREE_H
