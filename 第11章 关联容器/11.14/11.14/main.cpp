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
	���ü�ͥ�Ѵ����ǣ������ֻ�ǻ�ȡ��vector�����ᵼ��vector���κα仯��
	���ü�ͥ�����ڣ���׼��map��ʵ�ֻ�������������Ϊ�ùؼ��ִ���һ�����󣬽���Ĭ�ϳ�ʼ����
	������һ���յ�vector����if�汾��Ч����ȫһ�¡�
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
	add_family(families, "��");
	add_child(families, "��", "ǿ","1990-4-3");
	add_child(families, "��", "��", "1990-4-3");
	add_child(families, "��", "��", "1990-4-3");
	add_family(families, "��");
	add_family(families, "��");

	for (auto f : families)
	{
		cout << f.first << "�ҵĺ��ӣ�";
		for (auto c : f.second)
			cout << c.first << "������ " << c.second << ")," ;
		cout << endl;
	}

	typedef bool(*pf)(const string &a,const string&b);

	multiset<string, pf>bookstore(compareIsbn);


	multiset<string, pf>::iterator it = bookstore.begin();

	return 0;
}