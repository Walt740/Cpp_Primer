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
        ps = new string(*ex.ps); //����psָ��Ķ��󣬶����ǿ���ָ�뱾��
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
