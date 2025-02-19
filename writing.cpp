#include "writing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#define BIT8 8
using namespace std;

void encoding_file(char* filein, char* fileout, map<unsigned char, string> dict)
{
	string linein;
	string linebyte;
	
	ifstream fr;
	ofstream fw;
	
	fr.open(filein, ios::binary | ios::in);
	fw.open(fileout, ios::binary | ios::out);
	if (fr.is_open()) {
		while (getline(fr, linein)) {
			for (int i = 0;i < linein.length();i++) {
				linebyte += dict[linein[i]];
			}
			int len = linebyte.length() / BIT8;
			if (linebyte.length() % BIT8) {
				len += 1;
			}
			cout << linebyte<<endl;
			char* out;
			out = new char[len];
			convert_byte_to_str(linebyte,out);
			fw << out << endl;
			delete[] out;
		}
		
	}
	fr.close();
	fw.close();
	
}
void decoding_file(char* filein, char* fileout, map<unsigned char, string> dict)
{

}
void convert_byte_to_str( string& in,char *res)
{
	int len = in.length() / BIT8;
	int tail = in.length() % BIT8;
	BIT2CHAR symb;
	for (int i = 0; i < len; ++i)
	{
		symb.mbit.b1 = in[i * BIT8 + 0];
		symb.mbit.b2 = in[i * BIT8 + 1];
		symb.mbit.b3 = in[i * BIT8 + 2];
		symb.mbit.b4 = in[i * BIT8 + 3];
		symb.mbit.b5 = in[i * BIT8 + 4];
		symb.mbit.b6 = in[i * BIT8 + 5];
		symb.mbit.b7 = in[i * BIT8 + 6];
		symb.mbit.b8 = in[i * BIT8 + 7];
		res[i] = symb.symb;
		cout << 1 << "\n";
		cout << symb.symb << "\n";
	}
	if (tail > 0) {
		symb.symb = 0;
		symb.mbit.b1 = len * BIT8 + 7 < len * BIT8 + tail ? in[len * BIT8 + 7] : 0;
		symb.mbit.b2 = len * BIT8 + 6 < len * BIT8 + tail ? in[len * BIT8 + 6] : 0;
		symb.mbit.b3 = len * BIT8 + 5 < len * BIT8 + tail ? in[len * BIT8 + 5] : 0;
		symb.mbit.b4 = len * BIT8 + 4 < len * BIT8 + tail ? in[len * BIT8 + 4] : 0;
		symb.mbit.b5 = len * BIT8 + 3 < len * BIT8 + tail ? in[len * BIT8 + 3] : 0;
		symb.mbit.b6 = len * BIT8 + 2 < len * BIT8 + tail ? in[len * BIT8 + 2] : 0;
		symb.mbit.b7 = len * BIT8 + 1 < len * BIT8 + tail ? in[len * BIT8 + 1] : 0;
		symb.mbit.b8 = len * BIT8 + 0 < len * BIT8 + tail ? in[len * BIT8 + 0] : 0;
		res[len] = symb.symb; 
		cout << 2 << "\n";
		cout << symb.symb << "\n";
	}
	return;
}



