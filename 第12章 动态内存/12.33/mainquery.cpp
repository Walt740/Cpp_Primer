//mainquery.cc
#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin; using std::cout; using std::cerr;
using std::endl;

#include <cstdlib>

#include "TextQuery.h"


void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
	tq.display_map();
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char **argv)
{
//    ifstream infile;
//    if (argc < 2 || !(infile.open(argv[1]), infile)) {
//        cerr << "No input file!" << endl;
//        return EXIT_FAILURE;
//    }
    ifstream in("d:11.txt");  //打开文件
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
    runQueries(in );
    return 0;
}

