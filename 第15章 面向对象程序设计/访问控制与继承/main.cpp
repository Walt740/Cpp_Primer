#include <iostream>

using namespace std;

// �ܱ����ĵĳ�Ա
/*
class Base
{
    friend  class Pal;
public:
    int ab;
protected :
    int prot_mem; // Protected��Ա
};

class Sneaky: public Base
{
    friend void clobber(Sneaky&); //�ܷ���Sneaky::prot_mem
    friend void clobber(Base&); // ���ܷ���Base::prot_mem
    int j; //jĬ����private
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
    int f3(Sneaky s){return s.prot_mem;} //��ȷ:Pal��Base����Ԫ
};

//��Ԫ���ܼ̳�
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
//���С�˽�к��ܱ����ļ̳�
/*
class Base
{

public:
    void pub_mem(){} //public��Ա
protected:
    int prot_mem;   //protected��Ա
private:
    char priv_mem; //private��Ա
};
//���м̳�
struct Pub_Derv:  public Base{
    //��ȷ�� ����������������protected��Ա
    int f() {return prot_mem;}
    //����private��Ա������������˵�ǲ��ɷ��ʵ�
    //char g() {return priv_mem;}
};

struct Priv_Derv: private Base
{
    //private ��Ӱ��������ķ���Ȩ��
    int f1() const {return prot_mem;}
};

struct Prot_Derv: protected Base
{
    //private ��Ӱ��������ķ���Ȩ��
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



//�����������ת���Ŀɷ�����

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
