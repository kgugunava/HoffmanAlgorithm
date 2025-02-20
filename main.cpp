#include "benchmark.h"
#include <iostream>
#include "writing.h"
#include "HoffmanTree.h"
#include <chrono>
#include <thread>
#include <map>

using namespace std;



int main() {
    const char** test = new const char*{ "mir.txt" };
    startTests(test,1);
    string inputFileName = "mir.txt";
    HoffmanTree hTree(inputFileName);
    hTree.inorderWalk(hTree.getRoot(), "");
    map<string, unsigned char> dictForDecoding;
    hTree.makeMap("outputMap.txt");

    getMapForDecodingFromFile("outputMap.txt", dictForDecoding);
    encoding_file(inputFileName,"output.txt", get_map());
    decoding_file("output.txt", "output2.txt", dictForDecoding);

    
}