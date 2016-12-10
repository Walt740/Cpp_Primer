#include <iostream>

using namespace std;

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
struct Pub_Derv:  public Base
{
    //��ȷ�� ����������������protected��Ա
    int f() {return prot_mem;}
    //����private��Ա������������˵�ǲ��ɷ��ʵ�
    //char g() {return priv_mem;}
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Pub_Derv" << endl;
    }
};

struct Priv_Derv: private Base
{
    //private ��Ӱ��������ķ���Ȩ��
    int f1() const {return prot_mem;}
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Priv_Derv" << endl;
    }
};

struct Prot_Derv: protected Base
{
    //private ��Ӱ��������ķ���Ȩ��
    int f2() const {return prot_mem;}
    void memfcn(Base &b)
    {
        b = *this;
       cout << "Prot_Derv" << endl;
    }
};


struct Derived_from_Public:public Pub_Derv
{
    int use_base() {return prot_mem;}
    void memfcn(Base &b)
    {
        b = *this;
       cout << "Derived_from_Public" << endl;
    }
};

struct Derived_from_Private: public Priv_Derv
{
    //using Base::prot_mem;
    //int use_base() {return prot_mem;}
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_from_Private" << endl;
    }
};

struct Derived_from_Protected: protected Prot_Derv
{
    int use_base() { return prot_mem;}
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_from_Protected" << endl;
    }
};

/*

    ֻ�е������๫�еļ̳л���ʱ���û��������ʹ�������������
    ��ת����Ҳ����˵�����������̳л���ķ�ʽ���ܱ����Ļ���
    ˽�еģ����û����벻��ʹ�ø�ת����


*/

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
//   Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base base;
    Base *p = new Base;
    p = &d1; //��ȷ
 //   p = &d2;
 //   p = &d3;
    p = &dd1; //��ȷ
 //   p = &dd2;
 //   p = &dd3;

    d1.memfcn(base);
    d2.memfcn(base);
    d3.memfcn(base);
    dd1.memfcn(base);
 //   dd2.memfcn(base);
    dd3.memfcn(base);
    return  0;
}
