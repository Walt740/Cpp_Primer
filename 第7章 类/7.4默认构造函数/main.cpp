#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Nodefault
{
public:
    Nodefault(int i)
    {
        val = i;
    }
    int val;
};

class C
{
public:
    Nodefault nd;

    //������ʽ����Nodedefault�Ĵ��ι��캯����ʼ��nd
    C(int i = 0):nd(i){}
};


int main()
{
    vector<Nodefault> vec(10,1);
    Nodefault nd(1);
    vector<C> vc(10);
    C c; //ʹ��������C��Ĭ�Ϲ��캯��
    cout << c.nd.val << endl;
    return 0;
}
