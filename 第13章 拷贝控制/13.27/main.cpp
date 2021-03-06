#include <iostream>

using namespace std;

class HasPtr
{
public:
    //构造函数分配新的string和新的计数器，将计数器置为1
    HasPtr(const string &s = string()):
        ps(new string(s)),i(0),use(new size_t(1)) {}
    //拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr &p) : ps(p.ps),i(p.i),use(p.use){++*use;}
    HasPtr& operator= (const HasPtr&);
    HasPtr& operator= (const string&); //赋予新的string
    string &operator*(); //定义解引用运算符
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use; //用来记录有多少个对象共享*ps的成员
};

 HasPtr:: ~HasPtr()
 {
     if(--*use == 0) //如果引用计数变为0
     {
         delete ps;  //释放string内存
         delete use; //释放计数器内存
     }
 }

 HasPtr& HasPtr::operator=(const HasPtr &rhs)
 {
     ++*rhs.use; //递增右侧运算对象的引用计数
     if(--*use == 0)
     {
         delete ps;
         delete use;
     }
     ps = rhs.ps;   //将数据从rhs拷贝到本对象
     i = rhs.i;
     use = rhs.use;
     return *this;  //返回本对象
 }

 HasPtr &HasPtr::operator= (const string &rhs)
 {
     *ps = rhs;
     return *this;
 }


 string &HasPtr::operator *()
 {
     return *ps;
 }


int main()
{
    HasPtr h("hi mom！");
    HasPtr h2 = h; // 未分配新的string，h2和h指向相同的string
    h = "hi dad !";
    h = h2;
    h2 = "hi mom!";
    cout << "h:" << *h <<endl;
    cout << "h2:" << *h2 <<endl;
    return 0;
}
