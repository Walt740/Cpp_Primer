#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>


using namespace std;
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;

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

	void push_back(string &&s)
	{
	    data->push_back(std::move(s));
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
  public:
      StrBlobPtr():curr(0) {}
      StrBlobPtr(StrBlob& a,size_t sz = 0) : wptr(a.data),curr(sz) {}
      string& deref() const;
      StrBlobPtr& incr();
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


