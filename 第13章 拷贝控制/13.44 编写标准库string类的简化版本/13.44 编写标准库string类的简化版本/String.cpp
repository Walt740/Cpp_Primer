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
	cout << "���캯��" << endl;
}
String::String(const String &rhs)
{
	range_initializer(rhs.elements, rhs.end);
	cout << "�������캯��" << endl;
}

String &String::operator=(const String& rhs)
{
	auto newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
	cout << "������ֵ�����" << endl;
	return *this;
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

