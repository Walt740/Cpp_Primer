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
    Derived_from_Protected dd3;
    Derived_from_Private dd2;
    d1.pub_mem();
    Base *p = &d1; //��ȷ
    p = &d2;
    p = &d3;
    p = &dd1; //��ȷ
    p = &dd2;
    p = &dd3;

    //d2.pub_mem();
    return  0;
}
