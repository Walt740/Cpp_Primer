#include <iostream>
#include ".\include\StrVec.h"


using namespace std;

int main()
{
    StrVec str;
    str.push_back("yinhao");
    str.push_back("zheng");
    cout << str.size() <<" "<< str.capacity() <<endl;
    for(auto iter = str.begin(); iter != str.end(); iter++)
    cout << *iter <<endl;
    str.resize(8,"ok");
    for(auto iter = str.begin(); iter != str.end(); iter++)
    cout << *iter << endl;
    cout << str.size() <<" "<< str.capacity() <<endl;
    str.reserve(10);
    cout << str.size() << " " << str.capacity() <<endl ;
    StrVec vs = {"book","pen","eraser","pencil","bag"};

    for(auto &it :vs)
        cout << it << endl ;

    StrVec vs1(std::move(vs));
    vs = std::move(vs1);
    return 0;
}
