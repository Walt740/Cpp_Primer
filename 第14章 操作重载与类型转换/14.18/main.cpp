#include <iostream>
#include "StrBlob.h"
#include "String.h"
#include "StrVec.h"

using namespace std;

int main()
{
    StrBlob s({"yinhao"});
    s.push_back("zheng");
    s.push_back("1");
    s.push_back("2");
    s.push_back("3");
//    for(auto &c :s)
//        cout << c<< endl;

    cout << s[0] <<endl;


    StrBlobPtr ptr(s);
    cout << ptr[0] << endl;
    *(ptr+2) = "okey";
    cout << ptr->size() <<endl;
    cout << (*ptr).size() << endl;


     cout << s[0] <<endl ;

     StrBlobPtr_pointer pointer(&ptr);

     cout << (*pointer)[1] <<endl;
     cout << (*pointer.operator->())[0] << endl ;
     cout << (*pointer)->size() << endl;
    return 0;
}
