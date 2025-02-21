#include "benchmark.h"
#include <iostream>
#include "writing.h"
#include "HoffmanTree.h"
#include <chrono>
#include <thread>
#include <map>
#include <fstream>
using namespace std;



int main() {


    const char** test = new const char* { "input.txt" };
    //const char** test = new const char* { "merl.txt" };
    //const char** test = new const char* { "wav.wav };
    //const char** test = new const char* { "input.txt" };
    //const char** test = new const char* { "input.txt" };
    startTests(test,1);


    /*string inputFileName = "resource/mir.txt";
    HoffmanTree hTree(inputFileName);
    hTree.inorderWalk(hTree.getRoot(), "");
    map<string, unsigned char> dictForDecoding;
    hTree.makeMap("resource/outputMap.txt");

    getMapForDecodingFromFile("resource/outputMap.txt", dictForDecoding);
    encoding_file(inputFileName,"resource/output.txt", get_map());
    decoding_file("resource/output.txt", "resource/output2.txt", dictForDecoding);*/

    
}