#include <iostream>

using namespace std;

class NoDtor
{
   NoDtor(const NoDtor &rhs){}
   NoDtor& operator= (const NoDtor &rhs){}

public:
    friend void f(NoDtor a) ;

    void f2(NoDtor b){}
public:
    NoDtor() = default;
    ~NoDtor(){}//= delete;  //���ǲ�������NoDtor���͵Ķ���

private:
   //���һ������������ɾ���Ļ����ǲ��ɷ��ʵģ����磬��private�ģ�������ĺϳ���������������Ϊɾ����
    //~NoDtor(){}
    //���п������캯���ǲ��ɷ��ʵģ������ĺϳɹ��캯��������Ϊɾ����
//    NoDtor(const NoDtor &rhs)
//    {
//
//    }
private:
    int num ;
   // const int month; //������comst��Ա��������Ĭ�Ϲ��캯��������Ϊɾ����
    //int &rnum; //���������ó�Ա��������Ĭ�Ϲ��캯��������Ϊɾ����
};


void f(NoDtor a)
{

}

int main()
{

     NoDtor a ; //����:NoDtor������������ɾ����
    //NoDtor *p = new NoDtor(); // ��ȷ�������ǲ���delete p
    //delete p; //����NoDtor������������ɾ����
    NoDtor b = a;
//    f(a);
    a.f2(b);
    return 0;
}
