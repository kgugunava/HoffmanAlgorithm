#include "writing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#define BIT8 8
using namespace std;

void encoding_file(string filein, string fileout, map<unsigned char, string> dict)
{
	
	string linein;
	
	ifstream fr;
	ofstream fw;
	
	fr.open(filein, ios::binary | ios::in);
	fw.open(fileout, ios::binary | ios::out);
	if (fr.is_open()) {
		while (getline(fr, linein)) {
			cout << linein << endl;
			string linebyte;
			for (int i = 0;i < linein.length();i++) {
				linebyte += dict[linein[i]];
			}
			int len = linebyte.length() / BIT8;
			if (linebyte.length() % BIT8 ) {
				len += 1;
			}
			/*cout << len<<"\n";
			cout << linebyte<<endl;*/
			if (len) {
				char* out;
				out = new char[len] {0};
				cout << "->1 " << out[0] << "-" << out[1] << endl;
				convert_byte_to_str(linebyte, out);
				cout << "->" << out[0] << "-" << out[1] << endl;
				fw.write(out, len);
				/*for (int i = 0;i < len;i++) {
					fw.put(out[i]);
				}
				fw << "\n";*/
				fw << "\n";
				delete[] out;
				out = nullptr;
			}
			else {
				fw << "\n";
			}

		}
	}
	fr.close();
	fw.close();
	
}
void decoding_file(string filein, string fileout, map<string, unsigned char> dict)
{
	cout << "DECODE" << "\n";
	string linein;

	ifstream fr;
	ofstream fw;

	fr.open(filein, ios::binary | ios::in);
	fw.open(fileout, ios::binary | ios::out);
	if (fr.is_open()) {
		while (getline(fr, linein)) {
			cout << linein<<endl;
			string lineout;
			string in;
			for (int i = 0;i < linein.length();i++) {
				
				BIT2CHAR symb;
				symb.symb = linein[i];
				
				char symbol;
				convert_for_decode(dict, &symb, in, symbol);


			}
			cout << in << "\n";
			int st = 0;
			for (int i = 0;i < in.length();i++) {
				if(dict[in.substr(st,i-st)]){
					//fw.put(dict[in.substr(st, i - st)]);
					lineout += dict[in.substr(st,i - st)];
					st = i;
				}
			}
			if (dict[in.substr(st, in.length() - st)]) {
				cout << dict[in.substr(st, in.length() - st)];
				//fw.put(dict[in.substr(st, in.length() - st)]);
				lineout += dict[in.substr(st, in.length() - st)];
			}

			fw << lineout << "\n";
		}
	}
	fr.close();
	fw.close();


}

void convert_for_decode(map<string, unsigned char> dict,BIT2CHAR * symb,string& in,char& symbol)
{
	in += to_string((char)symb->mbit.b1);
	in += to_string((char)symb->mbit.b2);
	in += to_string((char)symb->mbit.b3);
	in += to_string((char)symb->mbit.b4);
	in += to_string((char)symb->mbit.b5);
	in += to_string((char)symb->mbit.b6);
	in += to_string((char)symb->mbit.b7);
	in += to_string((char)symb->mbit.b8);

}

void convert_byte_to_str(string& in, char* res)
{
	int len = in.length() / BIT8;
	int tail = in.length() % BIT8;
	if (tail) {
		len += 1;
	}
	if (((!len) && tail) || len) {
		//cout << "len " << len << "\n";
		BIT2CHAR symb;
		for (int i = 0; i < len; ++i)
		{
			//cout << i << "\n";
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
		
	}
	return;
}



