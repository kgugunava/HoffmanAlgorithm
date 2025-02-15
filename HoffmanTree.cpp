#include "HoffmanTree.h"
#include <iostream>
#include <algorithm>
#include <map>

vector<Node> allNodes;
map<unsigned char, string> dict; // coding dictionary


using namespace std;

bool comp(Node x, Node y) {
    return x.number_of_freq() > y.number_of_freq();
}

void inorderWalking(Node* root, string code) {

    if(root->getLeft() == nullptr && root->getRight() == nullptr) { //Out Condition

        if(root->number_of_value() != '\0') {

            dict[root->number_of_value()] = code; // recording in map (if you comment this line, a program will compile successfully)

            cout << root->number_of_value() << " - " << root->number_of_freq() << " - " << code <<"\n";
        }

        return;
    }

    inorderWalking(root->getLeft(), code + "0");
    inorderWalking(root->getRight(), code + "1");

    /*
    if(root == nullptr || root == NULL) {
        return;
    }



    if(root->number_of_value() != '\0') {


        //dict[root->number_of_value()] = new char[code.length()];
        //dict[root->number_of_value()] = code;

        cout << root->number_of_value() << " - " << root->number_of_freq() << " - " << code <<"\n";
        //cout << root->number_of_value() << " - " << root->number_of_freq() << " - " << code <<"\n";
    }

    inorderWalking(root->getLeft(), code + "0");
    inorderWalking(root->getRight(), code + "1");
    */

}

void HoffmanTree::buildHoffmanTree(const char* filename) {

    FILE* fr = fopen(filename, "rb");
    if (!fr)
        return;
    fseek(fr, 0L, SEEK_END);
    long length = ftell(fr);
    fseek(fr, 0, SEEK_SET);

    map<char, int> freqOfSymbol;

    for (int i = 0; i < length; i++) {
        freqOfSymbol[fgetc(fr)] += 1;
    }
    for (auto x : freqOfSymbol) {
        Node newNode(x.second, x.first);
        this->nodes.push_back(newNode);
    }
    sort(nodes.begin(), nodes.end(), comp);

    while (nodes.size() != 1) {
        Node newNode;
        newNode.setFreq(nodes.back().number_of_freq() + nodes[nodes.size() - 2].number_of_freq()); // sum of 2 prev nodes
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



void HoffmanTree::inorderWalk() {

    inorderWalking(root, "");

    cout << "--->" << dict['e'] << "\n";

}
