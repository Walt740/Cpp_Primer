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
	������������Ӧ�ñ�����ɳ�����Ա��������Ϊ���۷����������Ƿ��ص�ַ���ں������ڶ�
	ֻ�Ƕ�ȡ���ݳ�Ա��ֵ�����������κθı�
	*/
};
int main()
{
	Person nini;
	cout << "�����������͵�ַ....." << endl;
	cin >> nini.getname >> nini.getaddress;
	cout << nini.getaddress() << " " << nini.getname() << endl;
	return 0;
}