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
严重性	代码	说明	项目	文件	行	禁止显示状态
错误	C2373	“pf”: 重定义；不同的类型修饰符	
11.9	c:\users\walt740\documents\c++ primer\第11章 关联容器\11.9\11.9\main.cpp	33



*/


int main()
{
	map<string, list<int>> word_lineno; //单词到行号的映射
	string line;
	string word;
	int lineno = 0;
	// 函数指针测试
	
	//typedef bool (*Pf)(const string& a, const string& b);// = compareIsbn;
	using pF = bool(*)(const string& a, const string& b);
    pF pf  =  compareIsbn;


	
	while (getline(cin, line)) //获取一行字符串
	{
		lineno++;
		istringstream l_in(line); //该行字符串存入字符串流
		while (l_in >> word)
		{
			trans(word);
			word_lineno[word].push_back(lineno);//添加行号
		}
	}
	for (const auto & w : word_lineno) //打印单词行号
	{
		cout << w.first << "所在行: ";
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
//	//两种赋值给函数指针的方法都可以  
//	printf("%d", func(1, 10));
//	//printf("%d",(*func)(1,10));  
//	//两种调用函数指针的方法都可以  
//	//两种赋值方法和两种调用方法可以任选一种组合  
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