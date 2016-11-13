#include <iostream>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()):
        ps(new string(s)),i(0) {

        cout << " ���캯��" << endl;
        }
    HasPtr(const HasPtr& rhs)
    {
        ps = new string(*rhs.ps);
        i = rhs.i;
        cout << "�������캯��" << endl;
    }
    HasPtr& operator= (const HasPtr &rhs);
private:
    string  *ps;
    int i;

};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto  newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    cout << "��ֵ�����" <<endl ;
    return *this;
}

int main()
{
    HasPtr a("yinhao");
    HasPtr b("");
    HasPtr c = b;
    a  = b;
    return 0;
}
