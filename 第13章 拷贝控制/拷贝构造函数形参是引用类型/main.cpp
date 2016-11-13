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
//        cout << "���캯����һ���β�" <<endl ;
//    }
//    Point(const Point &ex) //�������캯��
//    {
//        m_ntest = ex.m_ntest;
//        cout << "�����˿������캯��" <<endl;
//
//    }
//    Point& operator= (const Point &ex)
//    {
//        cout<< "��ֵ������" <<endl;
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
    CExample(int x) : m_nTest(x)      //���������캯��
    {
        cout << "constructor with argument"<<endl;
    }

    // �������캯���������е�const�����ϸ����ģ������÷����Ǳ����
    CExample(const CExample & ex)     //�������캯��
    {
        m_nTest = ex.m_nTest;
        cout << "copy constructor"<<endl;
    }

    CExample& operator = (const CExample &ex)   //��ֵ����(��ֵ���������)
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
