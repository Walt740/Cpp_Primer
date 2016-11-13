//#include <iostream>
//
//
//
//using namespace std;
//
//class Point
//{
//private:
//    int m_ntest;
//public :
//    Point(int x) : m_ntest(x)
//    {
//        cout << "构造函数有一个形参" <<endl ;
//    }
//    Point(const Point &ex) //拷贝构造函数
//    {
//        m_ntest = ex.m_ntest;
//        cout << "调用了拷贝构造函数" <<endl;
//
//    }
//    Point& operator= (const Point &ex)
//    {
//        cout<< "赋值操作符" <<endl;
//        m_ntest = ex.m_ntest;
//        return *this;
//    }
//
//    void mytestfunc(Point ex)
//    {
//        //cout << m_ntest <<endl ;
//    }
//};
//
//Point global(10);
//Point foo_bar(Point arg)
//{
//    Point local = arg,*heap = new Point(global);
//    *heap = local;
//    //Point pa[4] = {local,*heap};
//    return *heap;
//}
//
//
//int main()
//{
//    Point arg(10);
//    foo_bar(arg);
//    return 0;
//}

//class A
//{
//private:
//    int value;
//public:
//    A(int n)
//    {
//        value = n;
//    }
//
//    A(A &other)
//    {
//        value = other.value;
//    }
//    void Print()
//    {
//        cout<<value<<endl;
//    }
//};
//
//int main(void)
//{
//    A a(10);
//    A b(20);
//    a = b;
//    a.Print();
//    return 0;
//}
//


#include<iostream>
using namespace std;

class CExample
{
private:
    int m_nTest;

public:
    CExample(int x) : m_nTest(x)      //带参数构造函数
    {
        cout << "constructor with argument"<<endl;
    }

    // 拷贝构造函数，参数中的const不是严格必须的，但引用符号是必须的
    CExample(const CExample & ex)     //拷贝构造函数
    {
        m_nTest = ex.m_nTest;
        cout << "copy constructor"<<endl;
    }

    CExample& operator = (const CExample &ex)   //赋值函数(赋值运算符重载)
    {
        cout << "assignment operator"<<endl;
        m_nTest = ex.m_nTest;
        return *this;
    }

    void myTestFunc(CExample ex)
    {
    }
};

int main(void)
{
    CExample aaa(2);
    CExample bbb(3);
    bbb = aaa;
    CExample ccc(aaa);
    bbb.myTestFunc(aaa);

    return 0;
}
