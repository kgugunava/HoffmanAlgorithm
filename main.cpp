#include <iostream>
#include "writing.h"
#include "HoffmanTree.h"

using namespace std;

int main() {
   
    string inputFileName = "mir.txt";
    HoffmanTree hTree(inputFileName);
    hTree.inorderWalk(hTree.getRoot(), "");
    map<string, unsigned char> dictForDecoding;
    hTree.makeMap("outputMap.txt");

    getMapForDecodingFromFile("outputMap.txt", dictForDecoding);
    encoding_file(inputFileName,"output.txt", get_map());
    decoding_file("output.txt", "output2.txt", dictForDecoding);

    
}