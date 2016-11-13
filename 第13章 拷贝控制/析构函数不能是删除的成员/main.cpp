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
    ~NoDtor(){}//= delete;  //我们不能销毁NoDtor类型的对象

private:
   //如果一个析构函数是删除的或者是不可访问的（例如，是private的），则类的合成析构函数被定义为删除的
    //~NoDtor(){}
    //类中拷贝构造函数是不可访问的，则该类的合成构造函数被定义为删除的
//    NoDtor(const NoDtor &rhs)
//    {
//
//    }
private:
    int num ;
   // const int month; //类中有comst成员，则该类的默认构造函数被定义为删除的
    //int &rnum; //类中有引用成员，则该类的默认构造函数被定义为删除的
};


void f(NoDtor a)
{

}

int main()
{

     NoDtor a ; //错误:NoDtor的析构函数是删除的
    //NoDtor *p = new NoDtor(); // 正确：但我们不能delete p
    //delete p; //错误：NoDtor的析构函数是删除的
    NoDtor b = a;
//    f(a);
    a.f2(b);
    return 0;
}
