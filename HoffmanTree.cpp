#include "HoffmanTree.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>

vector<Node> allNodes;
map<unsigned char, string> dict; // coding dictionary
map<char, int> freqOfSymbol; // frequency of every symbol in the text


using namespace std;

bool comp(Node x, Node y) {
    return x.number_of_freq() > y.number_of_freq();
}

void inorderWalking(Node *root, string code) {
    if (root->getLeft() == nullptr && root->getRight() == nullptr) {
        //Out Condition
        // if (root->number_of_value() != '\0') {
            dict[root->number_of_value()] = code;
            // recording in map (if you comment this line, a program will compile successfully)

            cout << root->number_of_value() << " - " << root->number_of_freq() << " - " << code << "\n";
        // }

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

void HoffmanTree::buildHoffmanTree(const char *filename) {
    string line;
    ifstream in(filename);
    if (in.is_open()) {
        while (getline(in, line)) {
            for (int i = 0; i < line.size(); i++) {
                freqOfSymbol[line[i]]++;
            }
        }
    }
    in.close();

    for (auto x: freqOfSymbol) {
        Node newNode(x.second, x.first);
        this->nodes.push_back(newNode);
    }
    sort(nodes.begin(), nodes.end(), comp);

    while (nodes.size() != 1) {
        Node newNode;
        newNode.setFreq(nodes.back().number_of_freq() + nodes[nodes.size() - 2].number_of_freq());
        // sum of 2 prev nodes
        allNodes.push_back(nodes[nodes.size() - 2]);
        allNodes.push_back(nodes.back());
        newNode.setLeft(&allNodes[allNodes.size() - 2]);
        newNode.setRight(&allNodes[allNodes.size() - 1]);
        nodes.pop_back();
        nodes.pop_back();
        nodes.push_back(newNode);
        sort(nodes.begin(), nodes.end(), comp);
    }
    this->root = &nodes[0];
    cout << "Hoffman tree built with the root in value " << this->root->number_of_value() << "\n";
}

void HoffmanTree::inorderWalk() {
    inorderWalking(this->root, "");
    cout << "--->" << dict['b'] << "\n";
}


// void HoffmanTree::printTree(Node* node) {
//     cout << "fgfdg";
//     if (node == nullptr) {
//         return;
//     }
//     // First recur on left subtree
//     printTree(node->getLeft());
//
//     // Now deal with the node
//     cout << node->number_of_freq() << " ";
//
//     // Then recur on right subtree
//     printTree(node->getRight());
// }

