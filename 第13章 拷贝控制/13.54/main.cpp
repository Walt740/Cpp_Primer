#include <iostream>
#include <string>

using std::string;


class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:
    /*
    将一个右值绑定到一个非const的引用，会导致错误，因为如果是非const，则意味着可以通过s对这个右值进行修改，
    对右值进行修改，显然是不合逻辑的（所谓右值，简单直观地就理解，就是只能放在等号右边，既然只能放在等号右边，
    那就是只能读取不能写入），所以错了。而const string &s = string() 将右值绑定到一个const引用，是合理的，
    只能读取，不能修改。
    */
    //HasPtr( string &s = string()): ps(new string(s)),i(0) {}
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {} //构造函数
    HasPtr(HasPtr &rhs) : ps(new string(*rhs.ps)),i(rhs.i) {} //拷贝构造函数
    HasPtr &operator= (const HasPtr& rhs) //赋值运算符
    {
        auto newps = new string(*rhs.ps);
        delete ps;
        ps = newps;
        i = rhs.i;
        return *this;
    }
    HasPtr &operator= (const string &s)
    {
        *ps = s;
        return *this;
    }
    string &operator*()
    {
        return *ps;
    }
    ~HasPtr()
    {
        delete ps;
    }

    void show()
    {
        std::cout << *ps << std::endl;
    }

private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs,HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
    std::cout << "call swap(HasPtr &lhs,HasPtr &rhs)" << std::endl;
}


int main()
{
    HasPtr a ("yinhao");
    HasPtr b ("zheng");
    std::cout<<"a:"<<*a <<std::endl;
    std::cout<<"b:"<<*b <<std::endl;

    swap(a,b);

    std::cout << "a:" <<*a <<std::endl;
    std::cout << "b:" <<*b <<std::endl;

    return 0;
}
