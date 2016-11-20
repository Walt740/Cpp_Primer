#include "StrVec.h"
#include <iostream>
#include <initializer_list>
#include <algorithm>
using std::cout;
using std::endl;

/*
    和我们在头文件中定义inline函数的原因一样,
    inline成员函数也应该与相应的类定义在同一个头文件中
    此处如果定义成inline函数,编译器则会报错,
    ||=== Build: Debug in 13.39 (compiler: GNU GCC Compiler) ===|
    obj\Debug\main.o||In function `main':|
    C:\Users\Walt740\Documents\GitHub\Cpp_Primer\第13章 拷贝控制\13.39\main.cpp|21|
    undefined reference to `
    StrVec::StrVec(std::initializer_list
                   <std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >)'|
    ||error: ld returned 1 exit status|
    ||=== Build failed: 2 error(s), 0 warning(s) (0 minute(s), 5 second(s)) ===|

*/
StrVec::StrVec(std::initializer_list<std::string> il)
{
    //调用alloc_n_copy分配与列表il中元素数目一样多的空间
    auto newdata = alloc_n_copy(il.begin(),il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}


void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}


std::pair<std::string* ,std::string*>
StrVec::alloc_n_copy(const std::string *b,const std::string *e)
{
    //分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b,e,data)};
}


//void StrVec::free()
//{
//    //不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
//    if(elements)
//    {
//        for(auto p = first_free;p!= elements; )
//            alloc.destroy(--p); //销毁元素
//        alloc.deallocate(elements,cap - elements); //释放空间
//    }
//}

void StrVec::free()
{
    //不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
    if(elements)
    {
//        for(auto p = first_free;p!= elements; )
//            alloc.destroy(--p); //销毁元素
//        for_each(elements,first_free,
//                 [](std::string *s){  alloc.destroy(s++); });
		/*
			封闭函数局部变量不能在 lambda 体中引用，除非其位于捕获列表中
			捕获列表必须= or & ,this ,否则，alloc就是未申明的标识符
		*/
        for_each(elements, first_free, [=](std::string& s) {alloc.destroy(&s); });
        alloc.deallocate(elements,cap - elements); //释放空间
    }
}




StrVec::StrVec(const StrVec &s)
{
    //调用alloc_n_copy分配空间以容纳与s中一样多的元素
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();//dtor
}


StrVec &StrVec:: operator=(const StrVec &rhs)
{
    //调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    //我们将分配当前大小两倍的内存空间
    auto newcapacity = size() ? 2 * size() : 1;
    //分配新内存
    auto newdata = alloc.allocate(newcapacity);
    //将数据从旧内存移动到新内存
    auto dest = newdata; //指向新数组中下一个空闲位置
    auto elem = elements; //指向旧数组中下一个元素
    for(size_t i = 0; i != size(); ++i )
        alloc.construct(dest++,std::move(*elem++));
    free(); //一旦我们移动过完元素就释放旧内存空间
    //更新我们的数据结构，执行新元素
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
    cout << "调用reallocate()" << endl ;
}

void StrVec::reallocate(size_t newcapacity)
{

    //分配新内存
    auto newdata = alloc.allocate(newcapacity);
    //将数据从旧内存移动到新内存
    auto dest = newdata; //指向新数组中下一个空闲位置
    auto elem = elements; //指向旧数组中下一个元素
    for(size_t i = 0; i != size(); ++i )
        alloc.construct(dest++,std::move(*elem++));
    free(); //一旦我们移动过完元素就释放旧内存空间
    //更新我们的数据结构，执行新元素
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;

}
void StrVec::reserve(size_t n)
{
    if(n > capacity())
        reallocate(n);
}

void StrVec::resize(size_t n)//调整对象的大小为n个元素
{
    if(n > size())  //n比元素个数大
    {
        while(size() < n)
            push_back("");
    }
    else if(n < size())
    {
        while(size() > n)
            alloc.destroy(--first_free);
    }
}

void StrVec::resize(size_t n,const std::string &s)//调整对象的大小为n个元素，并初始化新添加的元素为s
{
    if(n > size())
    {
        while(size() < n)
            push_back(s);
    }
}
