#include "benchmark.h"
#include <iostream>
#include "writing.h"
#include "HoffmanTree.h"
#include <chrono>
#include <thread>
#include <map>

using namespace std;


int main() {
    string files[4] = {"wav-test/wav-test1MB.wav", "wav-test/wav-test2MB.wav", "wav-test/wav-test5MB.wav", "wav-test/wav-test10MB.wav"};
    startTests(files, 4, "Logs.txt", "output.txt");
    // string inputFileName = "wav-test/wav-test10MB.wav";
    // HoffmanTree hTree(inputFileName);
    // hTree.inorderWalk(hTree.getRoot(), "");
    // map<string, unsigned char> dictForDecoding;
    // hTree.makeMap("outputMap.txt");
    //
    // getMapForDecodingFromFile("outputMap.txt", dictForDecoding);
    // encoding_file(inputFileName, "output.txt", get_map());
    // decoding_file("output.txt", "output2.wav", dictForDecoding);
}
