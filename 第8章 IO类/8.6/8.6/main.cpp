#include <iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

//��ϰ8.6����д7.11�ڵ������򣬴�һ���ļ��ж�ȡ���׼�¼��
//���ļ�����Ϊһ���������ݸ�main

//������ ����8.6.exe����Ŀ¼���½�һ��Sales_data.txt��Ȼ��д������
//		 Ȼ����cmd�� 8.6.exe���ڵ�Ŀ¼�� ����8.6.exe Sales_data.txt
//		 ���ɿ�������


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cerr << "������ļ���" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "�޷��������ļ�" << endl;
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
		cerr << "û������" << endl;
	}
	return 0;

}