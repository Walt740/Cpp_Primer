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
    /*
    将一个右值绑定到一个非const的引用，会导致错误，因为如果是非const，则意味着可以通过s对这个右值进行修改，
    对右值进行修改，显然是不合逻辑的（所谓右值，简单直观地就理解，就是只能放在等号右边，既然只能放在等号右边，
    那就是只能读取不能写入），所以错了。而const string &s = string() 将右值绑定到一个const引用，是合理的，
    只能读取，不能修改。
    */
    //HasPtr( string &s = string()): ps(new string(s)),i(0) {} //vs2015 竟然编译通过 gcc编译不通过
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {cout << "构造函数" <<endl; } //构造函数
	//HasPtr( HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) { cout << "拷贝构造函数" << endl; } //vs2015 竟然编译通过 gcc编译不通过																			  //vs2015 竟然编译通过 gcc编译不通过
    HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)),i(rhs.i) {cout << "拷贝构造函数" <<endl;} //拷贝构造函数
    HasPtr &operator= (const HasPtr& rhs) //赋值运算符
    {
        auto newps = new string(*rhs.ps);
        delete ps;
        ps = newps;
        i = rhs.i;
        return *this;
    }
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



int main(int argc,char *argv[])
{
    vector<HasPtr>vh;

/*
    HasPtr a("yinhao");
    HasPtr b("zheng");

    vh.push_back(a);
    vh.push_back(b);
*/

    int n = atoi(argv[1]);
    int n = 3;
    /*std::cin >> n;*/
    for(int i = 0;i < n; i++)
       vh.push_back(to_string(n - i));
    cout << "--------------------------------------------------" << endl;
    for(auto p : vh)
        cout << *p << " ";
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    sort(vh.begin(),vh.end());
    cout << "--------------------------------------------------" << endl;
    for(auto p : vh)
        cout << *p << " ";
    cout << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}
