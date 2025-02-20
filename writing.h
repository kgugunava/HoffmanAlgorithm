#ifndef WriteH
#define WriteH

#include <map>
#include <string>

using namespace std;

typedef union bit2char {
    char symb;

    struct bit {
        unsigned b1: 1;
        unsigned b2: 1;
        unsigned b3: 1;
        unsigned b4: 1;
        unsigned b5: 1;
        unsigned b6: 1;
        unsigned b7: 1;
        unsigned b8: 1;
    } mbit;
} BIT2CHAR;

void encoding_file(string filein, string fileout,map<int,string> dict);
void decoding_file(string filein, string fileout, map< string, unsigned char> dict);
void convert_for_decode(map<string, unsigned char> dict, BIT2CHAR* symb, string& in);
void convert_byte_to_str( string& in,char *res);

void getMapForDecodingFromFile(string filename, map<string, unsigned char> &dictForDecoding);

string getOutputFileName(string inputFileName);

#endif
