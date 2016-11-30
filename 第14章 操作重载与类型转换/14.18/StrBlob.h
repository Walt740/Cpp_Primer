#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>


using namespace std;
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr; //定义友元类
    friend bool operator==(const StrBlob &lhs,const StrBlob &rhs)
    {
        return lhs.data == rhs.data; //所指向的vector相等
    }
    friend bool operator!=(const StrBlob &lhs,const StrBlob &rhs)
    {
        return !(lhs == rhs);
    }

    friend bool operator< (const StrBlob  &lhs,const StrBlob  &rhs)
    {
        return *lhs.data < *rhs.data;
    }
    friend bool operator<=(const StrBlob  &lhs,const StrBlob  &rhs)
    {
        return *lhs.data <= *rhs.data;
    }
    friend bool operator> (const StrBlob  &lhs,const StrBlob  &rhs)
    {
        return *lhs.data > *rhs.data;
    }
    friend bool operator>=(const StrBlob  &lhs,const StrBlob  &rhs)
    {
        return *lhs.data >= *rhs.data;
    }
public:
	using size_type = vector<string>::size_type;
   // StrBlob();
	StrBlob() :data(std::make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

    StrBlobPtr begin(); //{return StrBlobPtr(*this);}
	StrBlobPtr end();// {auto ret = StrBlobPtr(*this,data->size());return ret;}

	size_type size() const
	{
		return data->size();
	}

	bool empty() const
	{
		return data->empty();
	}

	void push_back(const string& s) const
	{
		data->push_back(s);
	}

	void pop_back() const
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const string& front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	const string& back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	std::string &operator[] (std::size_t n)
	{
	    return data[n];
	}
	const std::string& operator[] (std::size_t n) const
	{
	    return data[n];
	}




private:
	void check(size_type i, const string& msg) const
	{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}

private:
	std::shared_ptr<vector<string>> data;
};




class StrBlobPtr
{
      friend bool eq(const StrBlobPtr&,const StrBlobPtr&);
      friend bool operator== (const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
          if(l == r)
            //两个指针都为空，或指向相同的vector且curr指向相同元素时，相等，否则不等
            return (!r || lhs.curr == rhs.curr);
          else
            return false;
      }
      friend bool operator!=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          return !(lhs == rhs);
      }
      //两个StrBlobPtr的比较，本质上是比较两个指向vector内元素的指针（迭代器），
      //因此，首先要求两个StrBlobPtr指向相同的vector，否则则没有可比性，然后比较指向的位置
      friend bool operator< (const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
          if(l == r)
            if(!r)
                return false; //两个指针都为空，认为是相等
            else
                return ( lhs.curr < rhs.curr);//指向相同vector，比较指针位置
          else
            return false; // 指向不同的vector时，不能比较
      }
      friend bool operator<=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
          if(l==r)
            //都为空，或指向相同vector且前者位置更靠前
            return (!r || lhs.curr <= rhs.curr);
          else
            return false; //指向不同vector时，不能比较
      }
      friend bool operator> (const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
          if(l == r)
            if(!r)
                return false;
            else
                return (lhs.curr > rhs.curr);
           else
            return false;
      }
      friend bool operator>=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
          if(l == r)
            return (!r || lhs.curr >= rhs.curr);
          else
            return false;
      }
      friend StrBlobPtr operator+(int n)
      {
          StrBlobPtr ret = *this;
          ret.curr  += n;
          return ret;
      }
      friend StrBlobPtr operator-(int n)
      {
          StrBlobPtr ret = *this;
          ret.curr  -= n;
          return ret;
      }
  public:
      StrBlobPtr():curr(0) {}
      StrBlobPtr(StrBlob& a,size_t sz = 0) : wptr(a.data),curr(sz) {}
      string& deref() const;
      StrBlobPtr& incr();
      std::string& operator[] (std::size_t n) {return (*wptr.lock())[n];}
      const std::string& operator[] (std::size_t n) const {return (*wptr.lock())[n];}
      //14.27
      //前缀
      StrBlobPtr& operator++();
      StrBlobPtr& operator--();
      //后缀
      StrBlobPtr operator++(int);
      StrBlobPtr operator--(int);

  private:
      shared_ptr<vector<string>> check(size_t,const string&)const;
      weak_ptr<vector<string>> wptr;
      size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i,const string & msg)const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

inline string& StrBlobPtr::deref()const
{
    auto  p = check(curr,"dereference past end");
    return (*p)[curr];
}


inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return  *this;
}

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this,data->size());
    return ret;
}

inline bool eq(const StrBlobPtr& lhs,const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

inline neq(const StrBlobPtr & lhs,const StrBlobPtr &rhs)
{
    return !eq(lhs,rhs);
}


//前缀
StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr&  StrBlobPtr::operator--()
{
    --curr;
    check(-1,"decrement past begin of StrBlobPtr");
    return *this;
}
//后缀
StrBlobPtr  StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++(*this);
    return ret;
}
StrBlobPtr  StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --(*this);
    return ret;
}
