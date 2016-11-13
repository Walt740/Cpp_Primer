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

    //必须显式调用Nodedefault的带参构造函数初始化nd
    C(int i = 0):nd(i){}
};


int main()
{
    vector<Nodefault> vec(10,1);
    Nodefault nd(1);
    vector<C> vc(10);
    C c; //使用了类型C的默认构造函数
    cout << c.nd.val << endl;
    return 0;
}
