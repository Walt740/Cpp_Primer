#include "String.h"
#include <iostream>


using namespace std;

int main()
{
	//String s("zheng yinhao");
	String s ("zheng yinh");
	cout << s << endl;
	String s1 = s;
	cout << s1  << endl;
	s1 = "hello word";
	cout << s1  << " " << s1.length() << " " <<s1.size()<<endl;

	return 0;
}
