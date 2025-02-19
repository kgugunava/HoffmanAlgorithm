#include <iostream>
#include <writing.h>
#include "HoffmanTree.h"

using namespace std;

int main() {
    string inputFileName = "image-lion.bmp";
    HoffmanTree hTree(inputFileName);
    hTree.inorderWalk(hTree.getRoot(), "");
    hTree.makeMap("outputMap.txt");
    getMapForDecodingFromFile("outputMap.txt");
    cout << getOutputFileName(inputFileName);
}