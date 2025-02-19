#include <iostream>

#include "BMPImages.h"
#include "HoffmanTree.h"

using std::cout;
using std::cin;

int main() {
    HoffmanTree hTree("image-lion.bmp");
    hTree.inorderWalk(hTree.getRoot(), "");
}