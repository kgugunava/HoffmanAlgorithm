#include "benchmark.h"
#include <chrono>
#include <fstream>
#include <numeric>
#include <vector>

#include "writing.h"
#include "HoffmanTree.h"


using namespace std;

// int findAverageTimeForTXT(string files[5], int size, string secs) {
//     vector<int> times;
//     int secsInInt = stoi(secs);
//     times.push_back(secsInInt);
//     int averageTime = accumulate(times.begin(), times.end(), 0) / times.size();
//     return averageTime;
// }

vector<int> allSeconds;

void printSpaceAndTime(string fileName, string logsFileName, chrono::time_point<chrono::high_resolution_clock> start, string outputFileName) {
    FILE *file = fopen(fileName.c_str(), "rb");
    FILE *outputFile = fopen(outputFileName.c_str(), "rb");
    if (!file)
        return;
    fseek(file, 0,SEEK_END);
    string size = to_string(ftell(file)); // get size of provided file
    string outputSize = to_string(ftell(outputFile)); // size of decoded file

    auto end = std::chrono::high_resolution_clock::now(); // end of program
    auto sec = chrono::duration_cast<std::chrono::seconds>(end - start); // sec's
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start); // millisec's

    string milSecs = to_string(duration.count()); // in millisecinds
    string secs = to_string(sec.count()); // time in seconds
    // int secsInInt = stoi(secs);
    // allSeconds.push_back(secsInInt);

    ofstream out(logsFileName, std::ios::app); // open for writing with saved before part
    if (!out.is_open())
        return;

    out << "File: " + fileName + "\n";
    // out << "Original_Memory: " + size + "\n";
    // out << "Encoded_Memory: " + outputSize + "\n";
    out << "Seconds: " + secs + "\n";
    out << "MilliSeconds: " + milSecs + "\n\n\n";
}


void startTests(string files[4], int size, string logs, string encodedFileName) {
    ofstream out;
    out.open(logs);
    for (int i = 0; i < size; ++i) {
        auto start = startTime();
        // HoffmanTree test(files[i]);
        // test.inorderWalk(test.getRoot(),"");
        string inputFileName = files[i];
        HoffmanTree hTree(inputFileName);
        hTree.inorderWalk(hTree.getRoot(), "");
        map<string, unsigned char> dictForDecoding;
        hTree.makeMap("outputMap.txt");

        getMapForDecodingFromFile("outputMap.txt", dictForDecoding);
        encoding_file(inputFileName, "output.txt", get_map());
        decoding_file("output.txt", "output2.wav", dictForDecoding);

        printSpaceAndTime(files[i], logs, start, "output.txt");
    }
    // int averageTime = accumulate(allSeconds.begin(), allSeconds.end(), 0) / allSeconds.size();
    // out << "Average Time: %d\n" + averageTime;
    // out.close();
}

std::chrono::time_point<std::chrono::high_resolution_clock> startTime() {
    return std::chrono::high_resolution_clock::now();
}

// void startSpace(std::string fileName, std::string logs) {
//     FILE *file = fopen(fileName.c_str(), "rb");
//
//     if (!file)
//         return;
//
//     fseek(file, 0,SEEK_END);
//
//     string size = to_string(ftell(file));
//
//     //ofstream out; // open for writing with created
//
//
//     ofstream out(logs, std::ios::app);
//     // out.open(logs);
//
//     if (!out.is_open())
//         return;
//
//     out << "Logs for " + fileName + ":\n";
//     out << "Space before:\t" + size + " bytes\n";
//
//     cout << "\tLogs for " + fileName + ":\n";
//     cout << "Space before:\t" + size + " bytes\n";
//
//     fclose(file);
//     out.close();
// }


// void duration(std::chrono::time_point<std::chrono::high_resolution_clock> start, string logs, string file) {
//     auto end = std::chrono::high_resolution_clock::now(); // end of program
//     auto sec = chrono::duration_cast<std::chrono::seconds>(end - start); // sec's
//     auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start); // millisec's
//
//     string milli = to_string(duration.count());
//     string secs = to_string(sec.count());
//
//     ofstream out(logs, std::ios::app); // open for writing with saved before part
//     if (!out.is_open())
//         return;
//
//     out << "File: " + file + "\n";
//     out << "Time:\t" + secs + " seconds\n";
//     out << "Time:\t" << milli << " milliseconds\n";
//
//     out.close();
//
//     std::cout << "Time taken by function: " << milli << " milliseconds" << std::endl;
//     std::cout << "Time taken by function: " << secs << " seconds" << std::endl;
// }
