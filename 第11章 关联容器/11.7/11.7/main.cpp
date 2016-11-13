#include <iostream>
#include <map>
#include <string>
#include <vector>



using namespace std;

void add_family(map<string,vector<string> > &families,const string &family)
{
	/*if (families.find(family) == families.end())
		families[family] = vector<string>();*/
	/*
		当该家庭已存在是，此语句只是获取其vector，不会导致vector有任何变化；
		若该家庭不存在，标准库map的实现机制是在容器中为该关键字创建一个对象，进行默认初始化，
		即构造一个空的vector。与if版本的效果完全一致。
	*/	
	
	families[family];
}

void add_child(map<string,vector<string>>& families, const string &family,const string &child)
{
	families[family].push_back(child);
}


int main()
{
	map<string, vector<string>> families;
    add_family(families, "张");
	add_child(families, "张","强" );
	add_child(families,"张","刚");
	add_child(families,"王","五");
	add_family(families,"王");
	add_family(families, "孙");

	for (auto f : families)
	{
		cout << f.first << "家的孩子：";
		for (auto c : f.second)
			cout << c << " ";
		cout << endl;
	}
	return 0;
}