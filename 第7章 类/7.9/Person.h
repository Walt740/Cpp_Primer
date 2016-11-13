#pragma once


//class Person
//{
//private : 
//	std::string strname;
//	std::string straddress;
//public:
//	std::string getname() const { return strname; }
//	std::string getaddress() const { return straddress; }
//
//	/*
//	上述两个函数应该被定义成常量成员函数，因为不论返回姓名还是返回地址，在函数体内都
//	只是读取数据成员的值，而不会做任何改变
//	*/
//};
#include <string>
using namespace std;

class Person
{

	friend	std::istream& read(std::istream& is, Person& man);
	friend	std::ostream& print(std::ostream& os, const Person& man);

private:
	string strname;
	string straddress;
public:
	string getname() const { return strname; }
	string getaddress() const { return straddress; }
};

std::istream& read(std::istream& is, Person& man)
{
	is >> man.strname >> man.straddress;
	return is;
}
std::ostream& print(std::ostream& os, const Person& man)
{
	os << man.getname() << " " << man.getaddress();
	return os;
}