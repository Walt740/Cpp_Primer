#pragma once

#include <string>
class Person
{
private : 
	std::string strname;
	std::string straddress;
public:
	std::string getname() const { return strname; }
	std::string getaddress() const { return straddress; }

	/*
	������������Ӧ�ñ�����ɳ�����Ա��������Ϊ���۷����������Ƿ��ص�ַ���ں������ڶ�
	ֻ�Ƕ�ȡ���ݳ�Ա��ֵ�����������κθı�
	*/
};