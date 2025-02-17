#include <iostream>
#include "HoffmanTree.h"

using std::cout;
using std::cin;

int main() {
    HoffmanTree hTree("input.txt");

    hTree.inorderWalk(hTree.getRoot(), "");

    return 0;
}