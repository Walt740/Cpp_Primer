#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(string &s = string() ): ps(new string(s)),,i(0) {} //构造函数
    HasPtr(HasPtr &rhs) : ps(new string(*rhs.ps),i(rhs.i)) {} //拷贝构造函数
    HasPtr& operator= (const HasPtr& rhs) //赋值运算符
    {
        auto newps = new string(*rhs.ps);
        delete ps;
        ps = newps;
        i = rhs.i;
        return *this;
    }

private:
    //~HasPtr(){}



    string *ps;
    int i;
};


int main()
{




    return 0;
}
