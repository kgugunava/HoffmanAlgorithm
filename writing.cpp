#include "writing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#define BIT8 8
using namespace std;



void encoding_file(string filein, string fileout, map< int, string> dict)
{
	cout << "ENCODE" << "\n";
	string linein;
	
	ifstream fr;
	ofstream fw;
	
	fr.open(filein, ios::binary | ios::in);
	fw.open(fileout, ios::binary | ios::out);
	fw << " ";
	string linebyte;
	if (fr.is_open()) {
		while (getline(fr, linein)) {
			
			//cout << linein << endl;
			
			for (int i = 0;i < linein.length();i++) {
				linebyte += dict[linein[i]];
			}
		}

		int len = linebyte.length() / BIT8;
		if (linebyte.length() % BIT8) {
			len += 1;
		}
		//cout << len<<"\n";
		//cout << linebyte<<endl;
		char* out;
		out = new char[len] {0};
		//cout << "->1 " << out[0] << "-" << out[1] << endl;
		convert_byte_to_str(linebyte, out);
		//cout << "->" << out[0] << "-" << out[1] << endl;
		fw.write(out, len);
		/*for (int i = 0;i < len;i++) {
			fw.put(out[i]);
		}
		fw << "\n";*/
		//fw << "\n";
		delete[] out;
		out = nullptr;
		fw.seekp(0);
		fw << linebyte.length() % BIT8;
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

		char tail = fr.get();
		string in;
		
		while (getline(fr, linein)) {
			for (int i = 0;i < linein.length();i++) {
				BIT2CHAR symb;
				symb.symb = linein[i];
				convert_for_decode(dict, &symb, in);
			}
			cout << "read line";
			int len;
			if (tail - '0') {
				len = in.length() - BIT8 + (tail - '0');
			}
			else {
				len = in.length();
			}
			
			int i = 0;//end;
			int st = 0;
			string buff = "";
			string lineout = "";
			while (i != len) {
				buff.push_back(in[i]);
				if (dict[buff]) {
					lineout.push_back(dict[buff]);
					buff = "";
				}
				++i;
			}
			fw << lineout;
		}
		
		
		
	}
	fr.close();
	fw.close();


}

void convert_for_decode(map<string, unsigned char> dict,BIT2CHAR * symb,string& in)
{
	int len = in.length();
	in.insert(len,to_string((char)symb->mbit.b1));
	in.insert(len+1, to_string((char)symb->mbit.b2));
	in.insert(len+2, to_string((char)symb->mbit.b3));
	in.insert(len+3, to_string((char)symb->mbit.b4));
	in.insert(len+4, to_string((char)symb->mbit.b5));
	in.insert(len+5, to_string((char)symb->mbit.b6));
	in.insert(len+6, to_string((char)symb->mbit.b7));
	in.insert(len+7, to_string((char)symb->mbit.b8));

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

string getOutputFileName(string inputFileName) {
	string outputFileName = inputFileName.substr(0, inputFileName.size() - 4) + "-encoded";
	string extension = inputFileName.substr(inputFileName.size() - 4, 4);
	outputFileName += extension;
	return outputFileName;
}

void getMapForDecodingFromFile(string filename, map<string, unsigned char> &dictForDecoding) {
	ifstream in(filename);
	string currentLine;
	if (in.is_open()) {
		while (getline(in, currentLine)) {
			if (currentLine == "*") {
				// конец мапы
				return;
			}
			int whereSpaceWas;
			for (int i = 0; i < currentLine.size(); i++) {
				if (currentLine[i] == ' ') {
					whereSpaceWas = i;
					break;
				}
			}
			string codeForSymbol = currentLine.substr(whereSpaceWas + 1, currentLine.size() - 2);
			int symbolInInteger = atoi(currentLine.substr(0, whereSpaceWas).c_str());
			dictForDecoding[codeForSymbol] = (char)symbolInInteger;
			// cout << codeForSymbol << " : " << dictForDecoding[codeForSymbol] << "\n";
		}
	}
}


