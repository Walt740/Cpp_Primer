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
//	������������Ӧ�ñ�����ɳ�����Ա��������Ϊ���۷����������Ƿ��ص�ַ���ں������ڶ�
//	ֻ�Ƕ�ȡ���ݳ�Ա��ֵ�����������κθı�
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