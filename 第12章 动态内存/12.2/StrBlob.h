#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <initializer_list>


using std::vector;using std::string;


class StrBlob
{
  public:
      typedef vector<string>::size_type size_type;
      StrBlob():data(std::make_shared<vector<string>>()){} //默认构造函数
      StrBlob(std::initializer_list<string>il):data(std::make_shared<vector<string>>(il)){}
      size_type size() const {return data->size();}
      bool empty() const {return data->empty();}
      //添加和删除元素
      void push_back(const string& t){data->push_back(t);}
      void pop_back();
      //元素访问
      string& front();
      string& back();
      const  string& front() const;
      const  string& back() const;


  private:
    std::shared_ptr<vector<string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_t i,const string& msg) const;
};

void StrBlob::check(size_type i,const std::string &msg)const
{
    if(i>= data->size())
        throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
    //如果vector为空，check会抛出一个异常
    check(0,"front on empty StrBlob");
    return data->front();
}

 string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

const  string& StrBlob::front() const
{
    //如果vector为空，check会抛出一个异常
    check(0,"front on empty StrBlob");
    return data->front();
}
const  string& StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}



