#include <iostream>
#include "HoffmanTree.h"

using std::cout;
using std::cin;

int main() {
    HoffmanTree hTree;
    hTree.buildHoffmanTree("input.txt");

    //cout << hTree.getTree().getLeft()->getLeft()->getLeft()->number_of_value() << "\n";

    hTree.inorderWalk(hTree.getRoot(), "");

    return 0;
}