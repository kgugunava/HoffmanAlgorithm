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
    dict['q'] = "00011";
    dict['f'] = "0011";
    dict['w'] = "010";
    dict['e'] = "1010";
    dict['r'] = "1011";
    dict['t'] = "1100";
    dict['y'] = "1101";
    dict['u'] = "1110";
    dict['\n'] = "00000001";

    map< string, unsigned char> dict2;
    dict2["00011"] = 'q';
    dict2["010"] = 'w';
    dict2["00000001"] = '\n';

    string in = "input.txt";
    string out1 = "output.txt";
    string out2 = "output2.txt";
    encoding_file(in, out1, dict);
    decoding_file(out1,out2, dict2);
}