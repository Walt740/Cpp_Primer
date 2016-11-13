#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <utility>



using namespace std;

class StrBlob
{
public :
    using size_type = vector<string>::size_type ;
    StrBlob();
    StrBlob(initializer_list<string>il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();} //检测字符串是否为空
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    //元素访问
    string &front();
    string &back();
    //const版本
    const string& front() const;
    const string& back() const;

    string& at(size_type i){ return data->at(i); }
    StrBlob& operator = (StrBlob &Blob);

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

//成员函数的实现

StrBlob::StrBlob():data(make_shared<vector<string>>())
{

}

StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il))
{

}

inline void StrBlob::check(size_t i,const string &msg)const
{
    if(i >= data->size())
        throw out_of_range(msg);
}

inline string &StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}
inline const string &StrBlob::front() const
{
    check(0,"front on empty StrBlob");
    return data->front();
}


inline string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

inline const string & StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0,"pop back on empty StrBlob");
    data->pop_back();
}

inline StrBlob& StrBlob::operator=(StrBlob &Blob)
{
    this->data = Blob.data;
    return *this;
}

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
    }
    cout << b1.at(1) << endl ;

    return 0;
}
