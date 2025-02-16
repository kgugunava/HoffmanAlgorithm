#include "writing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#define BIT8 8
using namespace std;

void writing_to_file(char* filein, char* fileout, map<unsigned char, string> dict)
{
	string linein;
	string linebyte;
	
	ifstream fr;
	ofstream fw;
	
	fr.open(filein, ios::binary | ios::in);
	fw.open(fileout, ios::binary | ios::out);
	if (fr.is_open()) {
		while (getline(fr, linein)) {
			string lineout;
			for (int i = 0;i < linein.length();i++) {
				linebyte += dict[linein[i]];
			}
			//cout << linebyte<<endl;
			int count = linebyte.length() / BIT8;
			int len = count + 1;
			char* out = (char*)malloc((len) * sizeof(char));
			convert_byte_to_str(linebyte,out,len);
			fw << out << endl;
		}
		
	}
	fr.close();
	fw.close();
	
}
void convert_byte_to_str( string& in,char *res,int len)
{
	
	       
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
	}
	return;
}
