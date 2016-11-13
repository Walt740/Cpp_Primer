#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>




using namespace std;


string& trans(string& s)
{
	for (int p = 0; p < s.size(); p++)
		s[p] = tolower(s[p]);
	s.erase(find_if(s.begin(), s.end(), ispunct), s.end());
	return s;
}
bool compareIsbn(const string& a, const string &b);

bool compareIsbn(const string& a, const string &b)
{
	return a.size() < b.size();
}




/*
������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬
����	C2373	��pf��: �ض��壻��ͬ���������η�	
11.9	c:\users\walt740\documents\c++ primer\��11�� ��������\11.9\11.9\main.cpp	33



*/


int main()
{
	map<string, list<int>> word_lineno; //���ʵ��кŵ�ӳ��
	string line;
	string word;
	int lineno = 0;
	// ����ָ�����
	
	//typedef bool (*Pf)(const string& a, const string& b);// = compareIsbn;
	using pF = bool(*)(const string& a, const string& b);
    pF pf  =  compareIsbn;


	
	while (getline(cin, line)) //��ȡһ���ַ���
	{
		lineno++;
		istringstream l_in(line); //�����ַ��������ַ�����
		while (l_in >> word)
		{
			trans(word);
			word_lineno[word].push_back(lineno);//����к�
		}
	}
	for (const auto & w : word_lineno) //��ӡ�����к�
	{
		cout << w.first << "������: ";
		for (const auto &i : w.second)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}


//
//#include <string.h>  
//#include <stdio.h>  
//typedef int* PINNT;
//#define PP int*  
//
//int funcA(int a, int b);
//int funcB(int* a, int *b);
//int  main(int argc, char *argv[])
//{
//	int(*func)(int, int);
//	//func = &funcA;  
//	func = funcA;
//	//���ָ�ֵ������ָ��ķ���������  
//	printf("%d", func(1, 10));
//	//printf("%d",(*func)(1,10));  
//	//���ֵ��ú���ָ��ķ���������  
//	//���ָ�ֵ���������ֵ��÷���������ѡһ�����  
//
//}
//
//int funcA(int a, int b)
//{
//	return a + b;
//}
//
//int funcB(int* a, int *b)
//{
//	(*a) = (*a) + (*b);
//	return 1;
//}