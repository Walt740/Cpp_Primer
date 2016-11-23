#include <iostream>
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

    HasPtr hp("1"),hp2("2");
    //hp = hp2;
    hp2 = std::move(hp2);

    return 0;
}
