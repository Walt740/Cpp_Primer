#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <set>

using namespace std;

void add_family(map<string, vector<pair<string,string>>> &families, const string &family)
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

void add_child(map<string, vector< pair<string,string> > >& families, const string &family, const string &child,const string& birthday)
{
	families[family].push_back({ child,birthday});
}

bool compareIsbn(const string& a, const string& b)
{
	return a.size() < b.size();
}

int main()
{
	map<string, vector<pair<string,string>>> families;
	add_family(families, "张");
	add_child(families, "张", "强","1990-4-3");
	add_child(families, "张", "刚", "1990-4-3");
	add_child(families, "王", "五", "1990-4-3");
	add_family(families, "王");
	add_family(families, "孙");

	for (auto f : families)
	{
		cout << f.first << "家的孩子：";
		for (auto c : f.second)
			cout << c.first << "（生日 " << c.second << ")," ;
		cout << endl;
	}

	typedef bool(*pf)(const string &a,const string&b);

	multiset<string, pf>bookstore(compareIsbn);


	multiset<string, pf>::iterator it = bookstore.begin();

	return 0;
}