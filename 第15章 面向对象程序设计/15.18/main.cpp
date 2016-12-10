#include <iostream>

using namespace std;

class Base
{

public:
    void pub_mem(){} //public成员
protected:
    int prot_mem;   //protected成员
private:
    char priv_mem; //private成员
};
//公有继承
struct Pub_Derv:  public Base
{
    //正确： 派生类能正常访问protected成员
    int f() {return prot_mem;}
    //错误：private成员对于派生类来说是不可访问的
    //char g() {return priv_mem;}
};

struct Priv_Derv: private Base
{
    //private 不影响派生类的访问权限
    int f1() const {return prot_mem;}
};

struct Prot_Derv: protected Base
{
    //private 不影响派生类的访问权限
    int f2() const {return prot_mem;}
};


struct Derived_from_Public:public Pub_Derv
{
    int use_base() {return prot_mem;}
};

struct Derived_from_Private: public Priv_Derv
{
    //using Base::prot_mem;
    //int use_base() {return prot_mem;}

};

struct Derived_from_Protected: public Prot_Derv
{
    int use_base() { return prot_mem;}
};

/*

    只有当派生类公有的继承基类时，用户代码才能使用派生类向基类
    的转换；也就是说，如果派生类继承基类的方式是受保护的或者
    私有的，则用户代码不能使用该转换。


*/

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Protected dd3;
    Derived_from_Private dd2;
    d1.pub_mem();
    Base *p = &d1; //正确
    p = &d2;
    p = &d3;
    p = &dd1; //正确
    p = &dd2;
    p = &dd3;

    //d2.pub_mem();
    return  0;
}
