#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <set>

using namespace std;

void add_family(map< string, vector<pair<string,string>> > &families, const string &family)
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

/*

C:\Users\Walt740\Documents\C++ Primer\��11�� ��������\11.23\main.cpp|27|
error: no matching function for call to
'std::multimap<std::__cxx11::basic_string<char>,
std::vector<std::pair<std::__cxx11::basic_string<char>,
std::__cxx11::basic_string<char> > > >::insert(<brace-enclosed initializer list>)'|


*/


void add_child(map<string, vector< pair<string,string> > >& families,
               const string &family, const string &child,const string& birthday)
{
	 //families[family].push_back({ child,birthday});


}

bool compareIsbn(const string& a, const string& b)
{
	return a.size() < b.size();
}

int main()
{
	map<string, vector<pair<string,string>>> families;

	//vector<int> v;
	//v[0] = 1;
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
//
//
//
////#include <map>
////#include <string>
////#include <iostream>
////
////using std::string;
////using std::multimap;
////using std::cin;
////using std::endl;
////
////int main()
////{
////	multimap<string, string> families;
////	for (string lname, cname; cin >> cname >> lname; families.emplace(lname, cname));
////	for (auto const& family : families)
////		std::cout << family.second << " " << family.first << endl;
////}



//
//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//
//
//
//using namespace std;
//
//
//
//void add_child(multimap<string, string>& families, const string &family, const string &child)
//{
//	families.insert({ family,child });
//}
//
//
//int main()
//{
//	multimap<string, string> families;
//	//add_family(families, "��");
//	add_child(families, "��", "ǿ");
//	add_child(families, "��", "��");
//	add_child(families, "��", "��");
//	add_child(families, "��", "ǿ");
//	add_child(families, "��", "��");
//	add_child(families, "��", "��");
//
//
//	for (auto f : families)
//	{
//		cout << f.first << "�ҵĺ��ӣ� " << f.second;
//			
//		cout << endl;
//	}
//	return 0;
//}