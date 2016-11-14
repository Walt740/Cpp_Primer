#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef vector<string> :: size_type size_type;
    StrBlob(); //Ĭ�Ϲ��캯��
    StrBlob(initializer_list<string> il);
    StrBlob(vector<string>*p);
    StrBlob(StrBlob& s);  //�������캯��

    StrBlob& operator= (StrBlob &rhs); //��ֵ������

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    //��Ӻ�ɾ��Ԫ��
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    //Ԫ�ط���
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    //�ṩ��StrBlobPtr�Ľӿ�
    StrBlobPtr begin(); //����StrBlobPtr����ܶ�������������
    StrBlobPtr end();
    //cosnt �汾
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
private:
    shared_ptr<vector<string>> data;
    void check(size_type i,const string &msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()){}
inline StrBlob::StrBlob(initializer_list<string>il) :
    data(make_shared<vector<string>> (il)){}
inline StrBlob::StrBlob(StrBlob &s):data(make_shared<vector<string>> (*s.data)){}
inline StrBlob& StrBlob::operator= (StrBlob &rhs)
{
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}
inline void StrBlob::check(size_type i,const string &msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}
inline string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}

//const �汾front
inline const string& StrBlob::front() const
{
    check(0,"front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}
//const �汾back
inline const string& StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
}


inline void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}


class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&,const StrBlobPtr&);
public:
    StrBlobPtr():curr(0) {}
    StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz) {}
    StrBlobPtr(const StrBlob &a,size_t sz = 0 ):wptr(a.data),curr(sz){}
    string& deref() const;
    string& deref(int off) const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();
private:
    shared_ptr<vector<string>> check(size_t,const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline shared_ptr<vector<string>>
StrBlobPtr::check(size_t i,const string &msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr,"derefence past end");
    return (*p)[curr];
}

inline string& StrBlobPtr::deref(int off)const
{
    auto p = check(curr + off,"derefence past end");
    return (*p)[curr + off];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
    --curr;
    check(0,"decrement past begin of StrBlobPtr");
    return *this;
}


inline StrBlobPtr StrBlob::begin()
{
     return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this ,data->size());
    return ret;
}

inline StrBlobPtr StrBlob::end()const
{
    auto ret = StrBlobPtr(*this,data->size());
    return ret;
}

inline StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

inline bool eq(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

inline bool neq(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return !eq(lhs,rhs);
}

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
        cout << "b2��СΪ" << b2.size() << endl;
        cout << "b2��βԪ��Ϊ" << b2.front() << "  " << b2.back() <<endl;
    }
    cout << "b1 ��СΪ " << b1.size() <<endl;
    cout << "b1��βԪ��Ϊ" << b1.front() << " " << b1.back() <<endl;

    StrBlob b3 = b1;
    b3.push_back("next");
    cout << "b3�Ĵ�СΪ" << b3.size() <<endl;
    cout << "b3��βԪ��Ϊ" << b3.front() << " " << b3.back() << endl ;

    cout << "b1ȫ��Ԫ�أ� " << endl;
    for(auto it = b1.begin();neq(it,b1.end());it.incr())
    {
        cout << it.deref() << endl;
    }

    return 0;
}
