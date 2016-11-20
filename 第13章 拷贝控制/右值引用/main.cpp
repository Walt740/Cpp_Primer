#include <iostream>
#include <vector>
#include "String.h"
#include <algorithm>

using namespace std;



int main()
{
   String s1("one"),s2("two");  //使用构造函数
    cout << s1.c_str() << " "<< s2.c_str() << " "<< endl << endl;
    String s3(s2);  //使用拷贝构造函数
    cout << s1.c_str() << " "<< s2.c_str() << " "<< s3.c_str() << " "<< endl << endl;
    s3 = s1;   //使用拷贝赋值运算符
    cout << s1.c_str() << " " << s2.c_str() << " " << s3.c_str() << endl <<endl;
    s3 = String("Three");
    cout << s1.c_str() << " " << s2.c_str() << " "<< s3.c_str() << endl << endl;

    vector<String> vs;
    vs.push_back(s1);
    vs.push_back(std::move(s2));
    vs.push_back(String("Three"));
    vs.push_back("Four");
    for_each(vs.begin(),vs.end(),[](const String &s){cout << s.c_str() << " ";});
    cout << endl;

    return 0;
}
