#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "textfile.h"

using namespace std;

TextFile::TextFile()
{
	path = "";
	stream = 0;
};

TextFile::TextFile(string address, bool message)
{
	path = address;
	stream = message;

	if (stream == 0) {
		file = fstream(path, fstream::in);
		string line;
		getline(file, line);
		fields = 1;
		for (int i = 0; i < line.length(); i++) {
			if ((line[i] == '\t') || (line[i] == ' '))
				fields++;
		}
		file.seekg(0, std::ios::beg);
		int value;
		while (!file.eof()) {
			vector<int> row;
			for (int i = 0; i < fields; i++) {
				file >> value;
				row.push_back(value);
			}
			rows.push_back(row);
		}

	}
	else {
		file = fstream(path, fstream::out);
	}

}
void TextFile::copy(string file1, string file2) {

	ifstream in(file1); ofstream out(file2);
	while (!in.eof()) {
		string line;
		in >> line;
		out << line;
	}
};
void TextFile::append(string file1, string file2) {

	ifstream in1(file1);
	ofstream out(file2, ios::app);


	while (!in1.eof()) {
		string line;
		in1 >> line;
		out << line;
	}
};

void TextFile::sort(int column_number) {

	vector <int> tmp; 

	for (int i = 0; i < rows.size()-1; i++) {
		for (int j = 0; j < rows.size() -1 - i; j++) {
			if (rows[j][column_number] > rows[j + 1][column_number]) {
				tmp = rows[j];
				rows[j] = rows[j + 1];
				rows[j + 1] = tmp;
			}
		}
	}


};


void TextFile::print() {
	cout << endl;
	for (int i = 0; i < rows.size(); i++) {
		for (int j = 0; j < fields; j++)
			cout << rows[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}


void TextFile::uniq(string file_path, TextFile& file1) {
	TextFile endfile(file_path, 1);
	endfile.rows = rows;
	for (int i = 0; i < file1.rows.size(); i++)
		endfile.rows.push_back(file1.rows[i]);
	
	endfile.sort(0);
	endfile.fields = fields;
	endfile.print();
	bool equal;
	int k;
	for (int i = 0; i < endfile.rows.size(); i++) {
		k = 1;
		equal = true;
		if (i >= endfile.rows.size())
			break;

		while (equal)
		{
			if (i + k >= endfile.rows.size())
				break;
				
			for (int j = 0; j < fields; j++) {
				
				if (endfile.rows[i][j] != endfile.rows[i + k][j]) {
					equal = false;
					k--;
					break;
				}

			}
			k++;
		}
		for (int j = 0; j < k; j++) {
			endfile.rows.erase(endfile.rows.begin() + i);
		}
	}
	endfile.print();
};