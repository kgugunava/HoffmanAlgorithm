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
    HoffmanTree(string fileName);

    void inorderWalk(Node* node, string code);

    void makeMap(string filename);

    Node* getRoot()const{return root;}

private:
    Node* root;
};


#endif //HOFFMANTREE_H
