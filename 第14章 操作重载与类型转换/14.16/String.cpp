#include "String.h"
#include <iostream>
#include <initializer_list>
#include <algorithm>

using std::cout;
using std::endl;

String::String(const char *s)
{
	const char *s1 = s;
	while (*s1++)
	{
		;
	}
	range_initializer(s,s1);
	cout << "构造函数" << endl;
}
String::String(const String &rhs)
{
	range_initializer(rhs.elements, rhs.end);
	cout << "拷贝构造函数" << endl;
}

String &String::operator=(const String& rhs)
{
	auto newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
	cout << "拷贝赋值运算符" << endl;
	return *this;
}

std::ostream &operator<< (std::ostream &os,const String &s)
{
    os << s.elements ;
    return os;
}


bool operator== (const String &lhs,const String &rhs)
{
     return strcmp(lhs.elements,rhs.elements);
}
bool operator!= (const String &lhs,const String &rhs)
{
    return !(lhs == rhs);
}



String::~String()
{
	free();
}


void String::free()
{
	if (elements)
	{
		std::for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
		alloc.deallocate(elements,end - elements);
	}
}

void String::range_initializer(const char *first,const char *last)
{
	auto newstr = alloc_n_copy(first,last);
	elements = newstr.first;
	end = newstr.second;
}


std::pair<char *,char *>
String::alloc_n_copy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return {str,std::uninitialized_copy(b,e,str)};
}

