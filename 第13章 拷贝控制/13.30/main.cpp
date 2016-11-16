#include <iostream>
#include <string>

using std::string;


class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:
    //HasPtr(const string &s = string()): ps(new string(s)),i(0) {}
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
