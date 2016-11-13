#include <string>
#include <iostream>
//#include "Person.h"
using namespace std;

class Person
{

  /*  friend	std::istream& read(std::istream& is,Person& man);
    friend	std::ostream& print(std::ostream& os,const Person& man);*/

private:
	string strname;
	string straddress;
public:
	string getname() const { return strname; }
	string getaddress() const { return straddress; }
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
};



int main()
{
	Person nini;
	cout << "请输入姓名和地址....." << endl;
	cout << (nini.read(cin, nini) ?  1  : 0) <<endl ;
	nini.print(cout,nini);
	return 0;
}
