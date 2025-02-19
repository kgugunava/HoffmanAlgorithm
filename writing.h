#ifndef WriteH
#define WriteH

#include <map>
#include <string>

using namespace std;

typedef union bit2char {
	char symb;
	struct bit {
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
		unsigned b8 : 1;
	}mbit;
}BIT2CHAR;

void writing_to_file(char* filein, char* fileout,map<unsigned char,string> dict);

void convert_byte_to_str( string& in,char *res,int len);

#endif
