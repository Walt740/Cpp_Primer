#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(string &s = string() ): ps(new string(s)),,i(0) {} //���캯��
    HasPtr(HasPtr &rhs) : ps(new string(*rhs.ps),i(rhs.i)) {} //�������캯��
    HasPtr& operator= (const HasPtr& rhs) //��ֵ�����
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
