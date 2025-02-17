#ifndef HOFFMANTREE_H
#define HOFFMANTREE_H
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class HoffmanTree {
public:
    void buildHoffmanTree(const char *text);

    void inorderWalk();

    void printTree(Node* node);

    Node* getRoot() {
        return this->root;
    }

private:
    vector<Node> nodes;
    Node *root = nullptr;
};


#endif //HOFFMANTREE_H
