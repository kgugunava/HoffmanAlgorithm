#include <iostream>
#include <writing.h>
#include "HoffmanTree.h"

using namespace std;

int main() {
    HoffmanTree hTree("input.txt");
    hTree.inorderWalk(hTree.getRoot(), "");
    hTree.makeMap("outputMap.txt");
    getMapForDecodingFromFile("outputMap.txt");
    cout << getOutputFileName("input.txt");
}