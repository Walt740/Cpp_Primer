#include <iostream>

using namespace std;

class PrivateCopy
{

    PrivateCopy(const PrivateCopy&){} //拷贝构造函数是private
    PrivateCopy& operator=(const PrivateCopy&); //拷贝运算符是private
public:
    PrivateCopy() = default;
    //~PrivateCopy(); //报错，未定义析构函数
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

//普通用户代码无法访问
//    PrivateCopy b = a;
//    PrivateCopy c;
//    c = a;

//友元函数

     f1(a);
//成员函数
    PrivateCopy b;
    a.f2(b);


    return 0;
}
