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
	//infile��һ��ifstream��ָ������Ҫ������ļ�
	TextQuery tq(infile);
	//���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
	while (true)
	{
		cout << "enter word to look for ,or q to quit: ";
		string s;
		//�������ļ�β���û������ˡ�q�� ʱѭ����ֹ
		if (!(cin >> s) || s == "q") break;
		//ָ���ѯ����ӡ���
		print(cout,tq.query(s)) << endl ;
	}
}


int main()
{
	ifstream file("../file.txt");
	if (!file)
	{
		cerr << "δ�ҵ������ļ� " << endl;
		return -1;
	}
	runQueries(file);
    return 0;
}




//

