#include "String.h"
#include <iostream>


using namespace std;

int main()
{
	//String s("zheng yinhao");
	String s = "zheng yinhao";
	cout << s.c_str() << endl;
	String s1 = s;
	cout << s1.c_str() << endl;
	s1 = "hello word";
	cout << s1.c_str() << " " << s1.length() << " " <<s1.size()<<endl;



}
