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
	//infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);
	//与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while (true)
	{
		cout << "enter word to look for ,or q to quit: ";
		string s;
		//若遇到文件尾或用户输入了‘q’ 时循环终止
		if (!(cin >> s) || s == "q") break;
		//指向查询并打印结果
		print(cout,tq.query(s)) << endl ;
	}
}


int main()
{
	ifstream file("../file.txt");
	if (!file)
	{
		cerr << "未找到输入文件 " << endl;
		return -1;
	}
	runQueries(file);
    return 0;
}




//

