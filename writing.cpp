#include "writing.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void writing_to_file(char* filein, char* fileout)
{
	fstream fr(filein);
	string line;
	getline(fr, line);
	cout << line;
}
