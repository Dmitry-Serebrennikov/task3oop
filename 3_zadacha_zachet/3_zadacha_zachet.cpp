#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "textfile.h"


int main()
{
	TextFile t1("C:/Users/argen/source/repos/3_zadacha_zachet/3_zadacha_zachet/1.txt", 0);
	TextFile t2("C:/Users/argen/source/repos/3_zadacha_zachet/3_zadacha_zachet/2.txt", 0);
	t2.print();
	t1.print();
	t1.sort(0);
	t1.print();
	t2.sort(0);
	t1.uniq("C:/Users/argen/source/repos/3_zadacha_zachet/3_zadacha_zachet/u.txt", t2);
	return 0;
}
