#ifndef HOFFMANTREE_H
#define HOFFMANTREE_H
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class HoffmanTree {
public:
    HoffmanTree() {
        root = nullptr;
    }
    void buildHoffmanTree(const char* text);

    void inorderWalk(Node* node, string code);

    Node* getRoot()const{return root;}

    //Node getTree()const{return nodes[0];}
private:
    vector<Node> nodes;
    Node* root = nullptr;
};


#endif //HOFFMANTREE_H
