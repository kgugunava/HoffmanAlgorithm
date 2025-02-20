#include "benchmark.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include "writing.h"
#include "HoffmanTree.h"


using namespace std;


void startTests(const char **files, int size, const char* logs) {

    ofstream out;
    out.open(logs);
    out.close();
    for(int i = 0; i < size; ++i) {
        auto start = startTime();
        HoffmanTree test(files[i]);
        test.inorderWalk(test.getRoot(),"");
        HoffmanTree hTree(files[i]);
        hTree.inorderWalk(hTree.getRoot(), "");
        map<string, unsigned char> dictForDecoding;
        hTree.makeMap("outputMap.txt");

        getMapForDecodingFromFile("outputMap.txt", dictForDecoding);
        encoding_file(files[i], "output.txt", get_map());
        decoding_file("output.txt", "output2.txt", dictForDecoding);
        duration(start);
    }

}

void startSpace(std::string fileName, std::string logs) {

    FILE* file = fopen(fileName.c_str(),"rb");

    if (!file)
        return;

    fseek(file,0,SEEK_END);

    string size = to_string(ftell(file));

    //ofstream out; // open for writing with created


    ofstream out(logs, std::ios::app);
    //out.open(logs);

    if(!out.is_open())
        return;

    out << "\tLogs for " + fileName +  ":\n";
    out << "Space before:\t" + size + " bytes\n";

    cout << "\tLogs for " + fileName +  ":\n";
    cout << "Space before:\t" + size + " bytes\n";

    fclose(file);
    out.close();

}


std::chrono::time_point<std::chrono::high_resolution_clock> startTime() {
    return std::chrono::high_resolution_clock::now();
}


void duration(std::chrono::time_point<std::chrono::high_resolution_clock> start, const char* logs) {
    auto end = std::chrono::high_resolution_clock::now();  // end of program
    auto sec = chrono::duration_cast<std::chrono::seconds>(end - start); // sec's
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);  // millisec's

    string milli = to_string(duration.count());
    string secs = to_string(sec.count());

    ofstream out(logs, std::ios::app); // open for writing with saved before part
    if(!out.is_open())
        return;

    out << "Time:\t" + secs + " seconds\n";
    out << "Time:\t" <<milli << " milliseconds\n";

    out.close();

    std::cout << "Time taken by function: " << milli << " milliseconds" << std::endl;
    std::cout << "Time taken by function: " << secs << " seconds" << std::endl;


}
