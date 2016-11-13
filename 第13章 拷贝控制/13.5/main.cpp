#include <iostream>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()):ps(new string(s),i(0)){}
    HasPtr(const HasPtr &ex):
        ps(new string(*ex.ps)),i(ex.i)
    {

    }
    HasPtr(const HasPtr &ex)
    {
        ps = new string(*ex.ps); //拷贝ps指向的对象，而不是拷贝指针本身
        i = ex.i;
    }
private:
    string *ps;
    int i;
};


int main()
{

    return 0;
}
