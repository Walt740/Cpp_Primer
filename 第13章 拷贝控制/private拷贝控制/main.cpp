#include <iostream>

using namespace std;

class PrivateCopy
{

    PrivateCopy(const PrivateCopy&){} //�������캯����private
    PrivateCopy& operator=(const PrivateCopy&); //�����������private
public:
    PrivateCopy() = default;
    //~PrivateCopy(); //����δ������������
    ~PrivateCopy(){}

    friend void f1(PrivateCopy a);
    void f2(PrivateCopy b){}
};

void f1(PrivateCopy a)
{

}

int main()
{
    PrivateCopy a;

//��ͨ�û������޷�����
//    PrivateCopy b = a;
//    PrivateCopy c;
//    c = a;

//��Ԫ����

     f1(a);
//��Ա����
    PrivateCopy b;
    a.f2(b);


    return 0;
}
