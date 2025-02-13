#include <iostream>
#include "HoffmanTree.h"

using std::cout;
using std::cin;

int main() {
    HoffmanTree hTree;
    hTree.buildHoffmanTree("input.txt");

    //hTree.inorderWalk();

    return 0;
}