#include "writing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#define BIT8 8
using namespace std;

void print_buff(char* buff,int in) {
	cout << "---\n";
	for (int i = 0;i < in;i++) {
		cout << buff[i];
	}
	cout << "\n---\n";
}

void encoding_file(string filein, string fileout, map< int, string> dict)
{
	cout << "ENCODE" << "\n";
	
	ifstream fr;
	ofstream fw;
	
	fr.open(filein, ios::binary | ios::in);
	fw.open(fileout, ios::binary | ios::out);
	if (fr.is_open()) {
		fw << " ";
		int ind_buff = 0;
		char* bufer = new char[8];
		char symbol;
		while (fr >> noskipws >> symbol) {
			auto x = dict.find(symbol);
			int len = x->second.length();
			//cout <<"symbol:"<< symbol << " "<< x->second<<"\n";
			if (ind_buff + len < 9) {
				for (int i = ind_buff;i < ind_buff + len;i++) {
					bufer[i] = x->second[i - ind_buff];

				}
				ind_buff += len;
				//print_buff(bufer, ind_buff);
			}
			else{
				int c = 0;
				for (int i = ind_buff;i < 8;i++) {
					bufer[i] = x->second[i - ind_buff];
					c = i - ind_buff+1;
					
				}
				ind_buff = 8;
				//print_buff(bufer, ind_buff);
				char out;
				convert_byte_to_str(bufer, out);
				fw.put(out);
				ind_buff = 0;
				//cout << "c: "<<c<<"\n";
				for (int i = ind_buff;i < len - c;i++) {
					bufer[i] = x->second[i - ind_buff+c];
					
				}
				ind_buff = len - c;
				//print_buff(bufer, ind_buff);
			}
			if (ind_buff== 8) {
				char out;
				convert_byte_to_str(bufer, out);
				fw.put(out);
				ind_buff = 0;
			}
		}
		if (ind_buff) {
			//print_buff(bufer, ind_buff);
			char out;
			convert_byte_to_str(bufer, out);
			fw.put(out);
		}
		fw.seekp(0);
		fw.put(static_cast<char>(ind_buff));

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
		

		char symbol;
		string code="";
		char tail;
		fr >> tail;
		string buff;
		while (fr >> noskipws >> symbol) {
			//cout << symbol;
			BIT2CHAR symb;
			symb.symb = symbol;
			convert_for_decode(symbol, code,&symb);
			int i = 0;
			//cout << "-->" << code << "\n";
			//cout << buff << "\n";
			while (i != 8) {
				//cout << "-" << code[0] << "\n";
				buff.push_back(code[i]);
				//cout << buff << "\n";
				if (dict.find(buff)!=dict.end()){
					//cout << "-->" << dict.find(buff)->second << "\n";
					fw.put(dict.find(buff)->second);
					buff = "";
				}
				++i;
			}
			code = "";
		}
	}
	fr.close();
	fw.close();


}

void convert_for_decode(char symbol,string& in, BIT2CHAR* symb)
{
	
	//cout << symb->mbit.b1;
	in.push_back(symb->mbit.b1 + '0');
	in.push_back(symb->mbit.b2 + '0');
	in.push_back(symb->mbit.b3 + '0');
	in.push_back(symb->mbit.b4 + '0');
	in.push_back(symb->mbit.b5 + '0');
	in.push_back(symb->mbit.b6 + '0');
	in.push_back(symb->mbit.b7 + '0');
	in.push_back(symb->mbit.b8 + '0');
	

}

void convert_byte_to_str(char * in,char&out)
{
	BIT2CHAR* symb = new BIT2CHAR;

	symb->mbit.b1 = in[0];
	symb->mbit.b2 = in[1];
	symb->mbit.b3 = in[2];
	symb->mbit.b4 = in[3];
	symb->mbit.b5 = in[4];
	symb->mbit.b6 = in[5];
	symb->mbit.b7 = in[6];
	symb->mbit.b8 = in[7];
	out = symb->symb;
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
				return;
			}
			int whereSpaceWas = currentLine.find(' ');
			string codeForSymbol = currentLine.substr(whereSpaceWas + 1, currentLine.size() - 2);
			int symbolInInteger = atoi(currentLine.substr(0, whereSpaceWas).c_str());
			dictForDecoding[codeForSymbol] = (char)symbolInInteger;
			// cout << codeForSymbol << " : " << dictForDecoding[codeForSymbol] << "\n";
		}
	}
}


