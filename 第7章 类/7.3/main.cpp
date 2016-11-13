#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
	string strname;
	string straddress;
public:
	string getname() const { return strname; }
	string getaddress() const { return straddress; }

	/*
	上述两个函数应该被定义成常量成员函数，因为不论返回姓名还是返回地址，在函数体内都
	只是读取数据成员的值，而不会做任何改变
	*/
};
int main()
{
	Person nini;
	cout << "请输入姓名和地址....." << endl;
	cin >> nini.getname >> nini.getaddress;
	cout << nini.getaddress() << " " << nini.getname() << endl;
	return 0;
}