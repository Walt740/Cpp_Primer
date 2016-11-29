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
    friend bool operator !=(const StrVec &lhs,const StrVec &rhs)
    {
        return !(lhs == rhs);
    }
    public:
        StrVec(): //allocator��Ա����Ĭ�ϳ�ʼ�� ��ʽ��Ĭ�ϳ�ʼ��alloc
            elements(nullptr),first_free(nullptr),cap(nullptr){}
        StrVec(std::initializer_list<std::string> il);
        StrVec(const StrVec &); //�������캯��
        StrVec(StrVec&&)noexcept ;//�ƶ����캯��
        StrVec &operator= (const StrVec &); //������ֵ�����
        StrVec &operator= (StrVec &&)noexcept; //�ƶ���ֵ�����
        ~StrVec(); //��������
        void push_back(const std::string &); //����Ԫ��
        size_t size() const {return first_free - elements;}
        size_t capacity() const { return cap - elements;}
        void reserve(size_t n); //Ԥ��һ���ֿռ�
        //�����Ԫ�صĺ�����ʹ��
        void chk_n_alloc()
        {
            if(size() == capacity()) reallocate();
        }
        std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
        void free(); //����Ԫ�ز��ͷ��ڴ�
        void reallocate(); //��ø�����ڴ沢��������Ԫ��
        void reallocate(size_t newcapacity); //���n��Ԫ�ش�С�ڴ�ռ䲢��������Ԫ��
        void resize(size_t n);//��������Ĵ�СΪn��Ԫ��
        void resize(size_t n,const std::string &s);//��������Ĵ�СΪn��Ԫ�أ�������ֵΪs

        std::string *begin() const {return elements;}
        std::string *end() const {return first_free;}

    private:
        std::allocator<std::string>alloc; //����Ԫ��
        std::string *elements; //ָ��������Ԫ�ص�ָ��
        std::string *first_free;//ָ�������һ������Ԫ�ص�ָ��
        std::string *cap; //ָ������β��λ�õ�ָ��

};


/*
    ��������ͷ�ļ��ж���inline������ԭ��һ��,
    inline��Ա����ҲӦ������Ӧ���ඨ����ͬһ��ͷ�ļ���
*/

//inline
//StrVec::StrVec(std::initializer_list<std::string> il)
//{
//    //����alloc_n_copy�������б�il��Ԫ����Ŀһ����Ŀռ�
//    auto newdata = alloc_n_copy(il.begin(),il.end());
//    elements = newdata.first;
//    first_free = cap = newdata.second;
//}
#endif // STRVEC_H
