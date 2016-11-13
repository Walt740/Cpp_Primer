#include <iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

//练习8.6：重写7.11节的书店程序，从一个文件中读取交易记录。
//将文件名作为一个参数传递给main

//方法： 先在8.6.exe所在目录中新建一个Sales_data.txt，然后写入数据
//		 然后在cmd中 8.6.exe所在的目录下 输入8.6.exe Sales_data.txt
//		 即可看见数据


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cerr << "请给出文件名" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
	Sales_data total;
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;

	}
	else
	{
		cerr << "没有数据" << endl;
	}
	return 0;

}