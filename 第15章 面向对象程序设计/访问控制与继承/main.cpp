#include <iostream>

using namespace std;

// 受保护的的成员
/*
class Base
{
    friend  class Pal;
public:
    int ab;
protected :
    int prot_mem; // Protected成员
};

class Sneaky: public Base
{
    friend void clobber(Sneaky&); //能访问Sneaky::prot_mem
    friend void clobber(Base&); // 不能访问Base::prot_mem
    int j; //j默认是private
};

void clobber(Sneaky &s)
{
    s.j = s.prot_mem = 0;
}

//void clobber(Base &b)
//{
//    b.prot_mem = 0;
//}

class Pal
{
public:
    int f(Base b){return b.prot_mem;}
//    int f2(Sneaky s) {return s.j;}
    int f3(Sneaky s){return s.prot_mem;} //正确:Pal是Base的友元
};

//友元不能继承
class D2: public Pal{

public:
    int mem(Base b)
    {
        return b.prot_mem;
    }

};

int main()
{
    Base b;
    //b.prot_mem = 0;

    b.ab = 0;

    return 0;
}
/*-----------------------------------------------------*/

/*----------------------------------------------------*/
//公有、私有和受保护的继承
/*
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
struct Pub_Derv:  public Base{
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

//struct Derived_from_Private: public Priv_Derv
//{
//    int use_base() {return prot_mem;}
//};

struct Derived_from_Protected: public Prot_Derv
{
    int use_base() { return prot_mem;}
};



int main()
{
//    Pub_Derv d1;
//    Priv_Derv d2;
//    d1.pub_mem();


//    d2.pub_mem();
    return  0;
}



//派生类向基类转换的可访问性

*/



class Base
{
public:
    std::size_t size() const {return n;}
protected:
    std::size_t n;
};

class Derived:private Base
{

public:
    using Base::size;
protected:
    using Base::n;

};

int main()
{

    return 0;
}
