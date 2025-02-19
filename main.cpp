#include <benchmark.h>
#include "HoffmanTree.h"
#include <chrono>
#include <thread>


using namespace std;



int main() {

    const char ** test = new const char*[]{"point.bmp", "input.txt", "war.txt"};

    startTests(test,  3);

    //auto start = startTime();

    //HoffmanTree hTree("wav.wav");
    //hTree.inorderWalk(hTree.getRoot(), "");

    //HoffmanTree one("point.bmp");
    //one.inorderWalk(one.getRoot(), "");

    //HoffmanTree two("war.txt");
    //two.inorderWalk(two.getRoot(), "");

    //duration(start); // time processing


    return 0;
}