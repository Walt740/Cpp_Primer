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
	上述两个函数应该被定义成常量成员函数，因为不论返回姓名还是返回地址，在函数体内都
	只是读取数据成员的值，而不会做任何改变
	*/
};