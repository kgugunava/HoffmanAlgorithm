#include <benchmark.h>
#include "HoffmanTree.h"
#include <chrono>
#include <thread>
#include <map>

using namespace std;



int main() {

    const char ** test = new const char*[]{"point.bmp", "input.txt", "war.txt"};

    //startTests(test,  3);

//encoding
    map<char, string> dict_for_encode;
    dict_for_encode['k'] = "00";
    dict_for_encode['t'] = "01";
    dict_for_encode['e'] = "100";
    dict_for_encode['f'] = "101";
    dict_for_encode['m'] = "11";
    //keftemme - 00100101011001111100
    string str = "keftemmee";
    int iter = 0;//end;
    string output_code = "";
    while(iter != str.length()) {
        output_code +=  dict_for_encode[str[iter]];
        //строку выше надо побитово закодировать
        ++iter;
    }

    cout << output_code << "\n";

// decoding
    map<string, char> dict_for_decode;
    dict_for_decode["00"] = 'k';
    dict_for_decode["01"] = 't';
    dict_for_decode["100"] = 'e';
    dict_for_decode["101"] = 'f';
    dict_for_decode["11"] = 'm';
    //keftemme - 00100101011001111100
    //string input_str = "00100101011001111100";
    string input_str = output_code;
    int i = 0;//end;
    string buff = "";
    string output_string = "";
    while(i != input_str.length()) {
        buff.push_back(input_str[i]);
        if(dict_for_decode[buff]) {
            output_string.push_back(dict_for_decode[buff]);
            buff = "";
        }
        ++i;
    }

    cout << output_string << "\n";





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