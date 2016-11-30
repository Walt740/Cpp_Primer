//#include "StrVec.h"
#include "../include/StrVec.h"
#include <iostream>
#include <initializer_list>
#include <algorithm>
using std::cout;
using std::endl;

/*
    ��������ͷ�ļ��ж���inline������ԭ��һ��,
    inline��Ա����ҲӦ������Ӧ���ඨ����ͬһ��ͷ�ļ���
    �˴���������inline����,��������ᱨ��,
    ||=== Build: Debug in 13.39 (compiler: GNU GCC Compiler) ===|
    obj\Debug\main.o||In function `main':|
    C:\Users\Walt740\Documents\GitHub\Cpp_Primer\��13�� ��������\13.39\main.cpp|21|
    undefined reference to `
    StrVec::Strec(std::initializer_list
                   <std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >)'|
    ||error: ld returned 1 exit status|
    ||=== Build failed: 2 error(s), 0 warning(s) (0 minute(s), 5 second(s)) ===|

*/
StrVec::StrVec(std::initializer_list<std::string> il)
{
    //����alloc_n_copy�������б�il��Ԫ����Ŀһ����Ŀռ�
    auto newdata = alloc_n_copy(il.begin(),il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(std::initializer_list<string>il)
{
    auto data = alloc_n_copy(il.begin(),il.end());
    free();  //���ٶ����е�Ԫ�ز��ͷ��ڴ�ռ�
    elements = data.first;   //�������ݳ�Աʹ��ָ���¿ռ�
    first_free = cap = data.second;
    return *this;
}
void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}


std::pair<std::string* ,std::string*>
StrVec::alloc_n_copy(const std::string *b,const std::string *e)
{
    //����ռ䱣�������Χ�е�Ԫ��
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b,e,data)};
}





//void StrVec::free()
//{
//    //���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ0������ʲôҲ����
//    if(elements)
//    {
//        for(auto p = first_free;p!= elements; )
//            alloc.destroy(--p); //����Ԫ��
//        alloc.deallocate(elements,cap - elements); //�ͷſռ�
//    }
//}

void StrVec::free()
{
    //���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ0������ʲôҲ����
    if(elements)
    {
//        for(auto p = first_free;p!= elements; )
//            alloc.destroy(--p); //����Ԫ��
//        for_each(elements,first_free,
//                 [](std::string *s){  alloc.destroy(s++); });
		/*
			��պ����ֲ����������� lambda �������ã�������λ�ڲ����б���
			�����б����= or & ,this ,����alloc����δ�����ı�ʶ��
		*/
        for_each(elements, first_free, [&](std::string& s) {alloc.destroy(&s); });
        alloc.deallocate(elements,cap - elements); //�ͷſռ�
    }
}


StrVec::StrVec(const StrVec &s)
{
    //����alloc_n_copy����ռ���������s��һ�����Ԫ��
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}


StrVec::StrVec(StrVec &&s) noexcept//�ƶ����캯��
    :elements(s.elements),first_free(s.first_free),cap(s.cap)
{
    //��s����������״̬���������������������ǰ�ȫ��
    s.elements = s.first_free = s.cap = nullptr;
    cout <<"�ƶ����캯��" << endl;
}


StrVec::~StrVec()
{
    free();//dtor
}


StrVec &StrVec::operator=(const StrVec &rhs)
{
    //����alloc_n_copy�����ڴ棬��С��rhs��Ԫ��ռ�ÿռ�һ����
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}


StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    //ֱ�Ӽ���Ը�ֵ
    if(this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        //��rhs���ڿ�����״̬
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    cout << "�ƶ���ֵ�����" <<endl;
    return *this;
}

void StrVec::reallocate()
{
    //���ǽ����䵱ǰ��С�������ڴ�ռ�
    auto newcapacity = size() ? 2 * size() : 1;
    //�������ڴ�
    auto newdata = alloc.allocate(newcapacity);
    //�����ݴӾ��ڴ��ƶ������ڴ�
//    auto dest = newdata; //ָ������������һ������λ��
//    auto elem = elements; //ָ�����������һ��Ԫ��
//    for(size_t i = 0; i != size(); ++i )
//        alloc.construct(dest++,std::move(*elem++));

    auto dest = uninitialized_copy(std::make_move_iterator(begin()),
                                   std::make_move_iterator(end()),
                                   newdata);



    free(); //һ�������ƶ�����Ԫ�ؾ��ͷž��ڴ�ռ�
    //�������ǵ����ݽṹ��ִ����Ԫ��
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
    cout << "����reallocate()" << endl ;
}

void StrVec::reallocate(size_t newcapacity)
{

    //�������ڴ�
    auto newdata = alloc.allocate(newcapacity);
    //�����ݴӾ��ڴ��ƶ������ڴ�
    auto dest = newdata; //ָ������������һ������λ��
    auto elem = elements; //ָ�����������һ��Ԫ��
    for(size_t i = 0; i != size(); ++i )
        alloc.construct(dest++,std::move(*elem++));
    free(); //һ�������ƶ�����Ԫ�ؾ��ͷž��ڴ�ռ�
    //�������ǵ����ݽṹ��ִ����Ԫ��
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;

}
void StrVec::reserve(size_t n)
{
    if(n > capacity())
        reallocate(n);
}

void StrVec::resize(size_t n)//��������Ĵ�СΪn��Ԫ��
{
    if(n > size())  //n��Ԫ�ظ�����
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

void StrVec::resize(size_t n,const std::string &s)//��������Ĵ�СΪn��Ԫ�أ�����ʼ������ӵ�Ԫ��Ϊs
{
    if(n > size())
    {
        while(size() < n)
            push_back(s);
    }
}
bool operator==(const StrVec &lhs ,const StrVec &rhs)
{
    if(lhs.size() != rhs.size())
    {
        return false;
    }
    //��������StrVec�е�ÿһ��Ԫ�أ����������򷵻�ʧ��
    for(auto itr1 = lhs.begin(),itr2 = rhs.begin();itr1 != lsh.end() && itr2 != rhs.end(); itr1++,itr2++)
    {
        if(*itr1 != *itr2)
        {
            return false;
        }
    }
    return true;
}
bool operator !=(const StrVec &lhs,const StrVec &rhs)
{
    return !(lhs == rhs);
}


//����StrVec�ıȽϣ���Ҫ�ֹ���д��������Ƚ�String
bool operator< (const StrVec &lhs,const StrVec &rhs)
{
    for(auto p1 = lhs.begin(),p2 = rhs.begin();p1 != lhs.end()&& p2 != rhs.end(); p1++,p2++)

        if(*p1 < *p2)   //֮ǰ��string����ȣ���ǰ��string��С
            return true;
        else if(*p1 > *p2) //֮ǰ��string����ȣ���ǰ��string����
            return false;
//        else
//            continue;
        //lhs������string����rhs�е�string��ȣ��Ҹ��̻�һ����
    //p1����first_free,p2û�е�first
    if(p1 == lhs.end() && p2 != rhs.end())
        return true;
    return false;

}
bool operator<=(const StrVec &lhs,const StrVec &rhs)
{
    for(auto p1 = lhs.begin(),p2 = rhs.begin();p1 != lhs.end()&& p2 != rhs.end(); p1++,p2++)
        if(*p1 < *p2)   //֮ǰ��string����ȣ���ǰ��string��С
            return true;
        else if(*p1 > *p2) //֮ǰ��string����ȣ���ǰ��string����
            return false;
//        else
//            continue;
        //lhs������string����rhs�е�string��ȣ��Ҹ��̻�һ����
    if(p1 == lhs.end())
        return true;
    return false;
}
bool operator> (const StrVec &lhs,const StrVec &rhs)
{
    for(auto p1 = lhs.begin(),p2 = rhs.begin();p1 != lhs.end()&& p2 != rhs.end(); p1++,p2++)
    {
        if(*p1 < *p2)   //֮ǰ��string����ȣ���ǰ��string��С
            return false;
        else if(*p1 > *p2) //֮ǰ��string����ȣ���ǰ��string����
            return true;
//        else
//            continue;
    }
        //rhs������string����lhs�е�string��ȣ��Ҹ���
    //p1����first_free,p2û�е�first
    if(p1 != lhs.end() && p2 == rhs.end())
        return true;
    return false;
}
bool operator>=(const StrVec &lhs,const StrVec &rhs)
{
    for(auto p1 = lhs.begin(),p2 = rhs.begin();p1 != lhs.end()&& p2 != rhs.end(); p1++,p2++)
    {
        if(*p1 < *p2)   //֮ǰ��string����ȣ���ǰ��string��С
            return false;
        else if(*p1 > *p2) //֮ǰ��string����ȣ���ǰ��string����
            return true;
//        else
//            continue;
    }
        //rhs������string����lhs�е�string��ȣ��Ҹ��̻�һ����
    //p1����first_free,p2û�е�first
    if( p2 == rhs.end())
        return true;
    return false;
}

