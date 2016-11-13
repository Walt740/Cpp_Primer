#include <iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

int main(int argc,char *argv[])
{
	if (argc != 3)
	{
		cerr << "��������롢����ļ���" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}
	ofstream out(argv[2],ofstream::app);
	if (!out)
	{
		cerr << "�޷�������ļ�" << endl;
		return -1;
	}
	Sales_data total;
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(out,total);
				total = trans;
			}
		}
		print(out, total) << endl;
		
	}
	else
	{
		cerr << "û������" << endl;
	}
	return 0;
}



