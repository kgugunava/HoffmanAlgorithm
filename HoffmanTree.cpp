#include "HoffmanTree.h"
#include "Node.h"
#include "benchmark.h"
#include <iostream>
#include <map>
#include <queue>
#include <fstream>

#define BUFF_SIZE 10000

vector<Node> allNodes;
Node buff[BUFF_SIZE];
int buffCount = 0;

map<int, string> dict; // coding dictionary

using namespace std;


map<int, string>& get_map() {
    return dict;
}
struct Comp {
    bool operator()(const Node &a, const Node &b) {
        return a.getFreq() > b.getFreq();
    }
};

HoffmanTree::HoffmanTree(string filename) {
    // startSpace(filename);
    priority_queue<Node, vector<Node>, Comp> queue;


    FILE *fr = fopen(filename.c_str(), "rb");
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

    for (auto x: freqOfSymbol) {
        Node newNode;
        newNode.setData(x.first);
        newNode.setFreq(x.second);
        queue.push(newNode);
    }
    //making tree
    while (!queue.empty()) {
        if (queue.size() == 1) {
            buff[buffCount] = queue.top();
            root = &buff[buffCount];
            break;
        }

        buff[buffCount] = queue.top();
        buffCount++; //+1
        queue.pop();
        buff[buffCount] = queue.top();
        buffCount++; //+1
        queue.pop();

        Node newNode(&buff[buffCount - 2], &buff[buffCount - 1]);
        queue.push(newNode);
    }
    buffCount = 0;
}

void HoffmanTree::inorderWalk(Node *node, string code) {
    if (node) {
        inorderWalk(node->getLeft(), code + "0");
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            dict[node->getData()] = code;
        }
        inorderWalk(node->getRight(), code + "1");
    }
}

void HoffmanTree::makeMap(string filename) {
    ofstream out;
    out.open(filename);
    if (out.is_open()) {
        for (auto x: dict) {
            out << x.first << " " << x.second << "\n";
        }
        out << "*";
    }
    out.close();
}
