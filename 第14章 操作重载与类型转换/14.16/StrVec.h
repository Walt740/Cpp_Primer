#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <utility>
#include <memory>
#include <initializer_list>


class StrVec
{
    friend bool operator==(const StrVec &lhs ,const StrVec &rhs)
    {
        if(lhs.size() != rhs.size())
        {
            return false;
        }
        //遍历两个StrVec中的每一个元素，如果不相等则返回失败
        for(auto itr1 = lhs.begin(),itr2 = rhs.begin();itr1 != lsh.end() && itr2 != rhs.end(); itr1++,itr2++)
        {
            if(*itr1 != *itr2)
            {
                return false;
            }
        }
        return true;
    }
    friend bool operator !=(const StrVec &lhs,const StrVec &rhs)
    {
        return !(lhs == rhs);
    }
    public:
        StrVec(): //allocator成员进行默认初始化 隐式地默认初始化alloc
            elements(nullptr),first_free(nullptr),cap(nullptr){}
        StrVec(std::initializer_list<std::string> il);
        StrVec(const StrVec &); //拷贝构造函数
        StrVec(StrVec&&)noexcept ;//移动构造函数
        StrVec &operator= (const StrVec &); //拷贝赋值运算符
        StrVec &operator= (StrVec &&)noexcept; //移动赋值运算符
        ~StrVec(); //析构函数
        void push_back(const std::string &); //拷贝元素
        size_t size() const {return first_free - elements;}
        size_t capacity() const { return cap - elements;}
        void reserve(size_t n); //预留一部分空间
        //被添加元素的函数所使用
        void chk_n_alloc()
        {
            if(size() == capacity()) reallocate();
        }
        std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
        void free(); //销毁元素并释放内存
        void reallocate(); //获得更多的内存并拷贝已有元素
        void reallocate(size_t newcapacity); //获得n个元素大小内存空间并拷贝已有元素
        void resize(size_t n);//调整对象的大小为n个元素
        void resize(size_t n,const std::string &s);//调整对象的大小为n个元素，并赋初值为s

        std::string *begin() const {return elements;}
        std::string *end() const {return first_free;}

    private:
        std::allocator<std::string>alloc; //分配元素
        std::string *elements; //指向数组首元素的指针
        std::string *first_free;//指向数组第一个空闲元素的指针
        std::string *cap; //指向数组尾后位置的指针

};


/*
    和我们在头文件中定义inline函数的原因一样,
    inline成员函数也应该与相应的类定义在同一个头文件中
*/

//inline
//StrVec::StrVec(std::initializer_list<std::string> il)
//{
//    //调用alloc_n_copy分配与列表il中元素数目一样多的空间
//    auto newdata = alloc_n_copy(il.begin(),il.end());
//    elements = newdata.first;
//    first_free = cap = newdata.second;
//}
#endif // STRVEC_H
