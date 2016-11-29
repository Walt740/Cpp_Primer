#ifndef String_H
#define String_H

#include <memory>
#include <iostream>


class String
{
    friend std::ostream& operator<< (std::ostream&,const String&);
public:
	//���캯��
	String() : String("") {} //ί�й��캯��
    String(const char *);
	//�������캯��
	String(const String&);
	//��������
	~String();
	//������ֵ�����
	String &operator=(const String&);
	const char *c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements + 1; }

private:
	std::pair<char*, char*> alloc_n_copy(const char* ,const char*);
	void range_initializer(const char *first,const char *last);
	void free();
private:
	std::allocator<char> alloc; //����Ԫ��
	char *elements;
	char *end;


};

#endif // String_H
