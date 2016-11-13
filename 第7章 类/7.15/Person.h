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
public: 
	//���캯��
	Person() = default;
	Person(const string &name, const string &address) 
	{
		strname = name ;
		straddress = address;
	}
	explicit Person(std::istream& is)
	{
		is >> *this;
	}
	friend	std::istream& read(std::istream& is, Person& man);
	friend	std::ostream& print(std::ostream& os, const Person& man);
	friend  std::istream& operator >> (std::istream & is, Person& man);
	friend  std::ostream& operator << (std::ostream &os,const Person& man);
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

std::istream& operator >> ( std::istream& is ,Person & man)
{
	//is >> man.strname >> man.straddress;
	is >> man.strname >> man.straddress;
	return  is;
} 

std::ostream& operator << (std::ostream &os, const Person& man)
{
	//os << man.strname <<  man.straddress;
	os << man.getname() << " " << man.getaddress();
	return os;
}