#include <string>
#include <iostream>
#include "Person.h"
using namespace std;

//class Person
//{
//
//	/*  friend	std::istream& read(std::istream& is,Person& man);
//	friend	std::ostream& print(std::ostream& os,const Person& man);*/
//
//private:
//	string strname;
//	string straddress;
//public:
//	string getname() const { return strname; }
//	string getaddress() const { return straddress; }
//	std::istream& read(std::istream& is, Person& man)
//	{
//		is >> man.strname >> man.straddress;
//		return is;
//	}
//	std::ostream& print(std::ostream& os, const Person& man)
//	{
//		os << man.getname() << " " << man.getaddress();
//		return os;
//	}
//};

#include <vector>

int main()
{

	cout << "�����������͵�ַ��Ϣ" << endl;
	Person man(cin);
    vector<int> vi(1);
	cout << man << endl;
	return 0;
}
