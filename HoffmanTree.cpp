#include "HoffmanTree.h"
#include "Node.h"
#include <iostream>
#include <algorithm>
#include <map>

vector<Node> allNodes;


map<unsigned char, string> dict; // coding dictionary


using namespace std;

bool comp(Node x, Node y) {
    return x.getFreq() > y.getFreq();
}


void HoffmanTree::buildHoffmanTree(const char* filename) {

    FILE* fr = fopen(filename, "rb");
    if (!fr)
        return;

    fseek(fr, 0L, SEEK_END);

    long length = ftell(fr);

    fseek(fr, 0, SEEK_SET);

    // map_1
    map<char, int> freqOfSymbol;

    for (int i = 0; i < length; i++) {
        freqOfSymbol[fgetc(fr)] += 1;
    }


    for (auto x : freqOfSymbol) {
        Node newNode(x.first, x.second);
        this->nodes.push_back(newNode);
    }

    sort(nodes.begin(), nodes.end(), comp);

    while (nodes.size() != 1) {
        Node newNode;
        newNode.setFreq(nodes.back().getFreq() + nodes[nodes.size() - 2].getFreq()); // sum of 2 prev nodes
        allNodes.push_back(nodes[nodes.size() - 2]);
        allNodes.push_back(nodes.back());
        newNode.setLeft(&allNodes[allNodes.size() - 2]);
        newNode.setRight(&allNodes[allNodes.size() - 1]);
        nodes.pop_back();
        nodes.pop_back();
        nodes.push_back(newNode);
        sort(nodes.begin(), nodes.end(), comp);
    }

    root = &nodes[0];

}



void HoffmanTree::inorderWalk(Node* node, string code) {

    if(node) {
        //if(!node->getLeft() && !node->getRight()) {
            inorderWalk(node->getLeft(), code + "0");
            //dict[node->getFreq()] = code;
            cout << (char)node->getData() << " - " << node->getFreq() << " - " << code <<"\n";
            inorderWalk(node->getRight(), code + "1");
        //}
    }

}
