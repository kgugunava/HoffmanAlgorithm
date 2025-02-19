#include <iostream>
//#include "HoffmanTree.h"
#include "writing.h"
#include <map>
#include<string>

using namespace std;

//using std::cout;
//using std::cin;


int main() {
    /*HoffmanTree hTree;
    hTree.buildHoffmanTree("input.txt");

    hTree.inorderWalk();

    return 0;*/
    map<unsigned char, string> dict;
    dict['q'] = "000000";
    dict['f'] = "0011";
    dict['w'] = "100";
    dict['e'] = "1010";
    dict['r'] = "1011";
    dict['t'] = "1100";
    dict['y'] = "1101";
    dict['u'] = "1110";
    dict['\n'] = "1111";


    encoding_file("input.txt", "output.txt",dict);
}