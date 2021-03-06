#ifndef String_H
#define String_H

#include <memory>
#include <iostream>


class String
{
    friend std::ostream &operator << (std::ostream &os,const String &s) ;
public:
	//构造函数
	String() : String("") {} //委托构造函数
    String(const char *);
	//拷贝构造函数
	String(const String&);
	//析构函数
	~String();
	//拷贝赋值运算符
	String &operator=(const String&);
	const char *c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements + 1; }

private:
	std::pair<char*, char*> alloc_n_copy(const char* ,const char*);
	void range_initializer(const char *first,const char *last);
	void free();
private:
	std::allocator<char> alloc; //分配元素
	char *elements;
	char *end;


};

#endif // String_H
