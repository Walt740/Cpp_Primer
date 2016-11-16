#include <iostream>

using namespace std;

class HasPtr
{
public:
    /*
    将一个右值绑定到一个非const的引用，会导致错误，因为如果是非const，则意味着可以通过s对这个右值进行修改，
    对右值进行修改，显然是不合逻辑的（所谓右值，简单直观地就理解，就是只能放在等号右边，既然只能放在等号右边，
    那就是只能读取不能写入），所以错了。而const string &s = string() 将右值绑定到一个const引用，是合理的，
    只能读取，不能修改。
    */
    HasPtr(const string &s = string() ) //一个右值需要绑定到一个const 类型的变量上
                :ps(new string(s)),i(0){}
    HasPtr(const HasPtr &ex):
        ps(new string(*ex.ps)),i(ex.i)
    {

    }
//    HasPtr(const HasPtr &ex)
//    {
//        ps = new string(*ex.ps); //拷贝ps指向的对象，而不是拷贝指针本身
//        i = ex.i;
//    }
private:
    string *ps;
    int i;
};


int main()
{

    return 0;
}
