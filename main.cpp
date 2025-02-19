#include <iostream>

#include "BMPImages.h"
#include "HoffmanTree.h"

using std::cout;
using std::cin;

int main() {
    HoffmanTree hTree("input.txt");
    hTree.inorderWalk(hTree.getRoot(), "");
    hTree.makeMap("ouputMap.txt");
}