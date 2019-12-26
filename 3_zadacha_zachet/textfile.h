#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class TextFile
{
	fstream file;
	string path;
	int stream;


public:
	TextFile();
	int fields;
	vector <vector<int>> rows;
	TextFile(string address, bool message);
	void copy(string file1, string file2);
	void append(string file1, string file2);
	void sort(int column_number);
	void uniq(string file_path, TextFile& file1);
	void print();

};
