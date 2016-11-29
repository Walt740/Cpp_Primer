
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::to_string;
using std::string;
using std::vector;
using std::cout;
using std::endl;



class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:


    HasPtr(const string &s = string()): ps(new string(s)), i(0) {cout << "构造函数" <<endl; } //构造函数
    HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)),i(rhs.i) {cout << "拷贝构造函数" <<endl;} //拷贝构造函数
    HasPtr(HasPtr &&p)noexcept :ps(p.ps),i(p.i){p.ps = 0;}
    //拷贝并交换
    HasPtr& operator=(HasPtr rhs)
    {
        swap(*this,rhs);
        return *this;
    }
    HasPtr& operator=(HasPtr &&rhs) noexcept
    {
        cout << "移动赋值" <<endl;
        if(this != &rhs)
        {
            delete ps;
            ps = rhs.ps;
            rhs.ps = nullptr;
            rhs.i = 0;
        }
        return *this;
    }
//    HasPtr &operator= (const HasPtr& rhs) //赋值运算符
//    {
//        auto newps = new string(*rhs.ps);
//        delete ps;
//        ps = newps;
//        i = rhs.i;
//        return *this;
//    }
    HasPtr &operator= (const string &s) //赋予新的string

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

        cout << "解引用" <<endl;
        return *ps;
    }

    bool operator<(const HasPtr &) const;
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

<<<<<<< HEAD
bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

/*

||=== Build: Debug in 13.54 (compiler: GNU GCC Compiler) ===|
C:\Users\Walt740\Documents\GitHub\Cpp_Primer\第13章 拷贝控制\13.54\main.cpp||In function 'int main(int, char**)':|
C:\Users\Walt740\Documents\GitHub\Cpp_Primer\第13章 拷贝控制\13.54\main.cpp|95|error: ambiguous overload for 'operator=' (operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>::type {aka HasPtr}')|
C:\Users\Walt740\Documents\GitHub\Cpp_Primer\第13章 拷贝控制\13.54\main.cpp|23|note: candidate: HasPtr& HasPtr::operator=(HasPtr)|
C:\Users\Walt740\Documents\GitHub\Cpp_Primer\第13章 拷贝控制\13.54\main.cpp|28|note: candidate: HasPtr& HasPtr::operator=(HasPtr&&)|
||=== Build failed: 1 error(s), 0 warning(s) (0 minute(s), 1 second(s)) ===|

*/

int main(int argc,char *argv[])
{


int main()
{
    HasPtr a ("yinhao");
    HasPtr b ("zheng");
    std::cout<<"a:"<<*a <<std::endl;
    std::cout<<"b:"<<*b <<std::endl;

    swap(a,b);

    std::cout << "a:" <<*a <<std::endl;
    std::cout << "b:" <<*b <<std::endl;
>>>>>>> 1171ac304c619691f88413ac4e1e63e8befb616a

    return 0;
}
