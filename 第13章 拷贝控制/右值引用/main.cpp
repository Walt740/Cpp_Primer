#include <iostream>
#include <vector>
#include "String.h"
#include <algorithm>

using namespace std;



int main()
{
   String s1("one"),s2("two");  //ʹ�ù��캯��
    cout << s1.c_str() << " "<< s2.c_str() << " "<< endl << endl;
    String s3(s2);  //ʹ�ÿ������캯��
    cout << s1.c_str() << " "<< s2.c_str() << " "<< s3.c_str() << " "<< endl << endl;
    s3 = s1;   //ʹ�ÿ�����ֵ�����
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
