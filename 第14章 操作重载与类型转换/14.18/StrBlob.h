#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <exception>


using namespace std;
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr; //������Ԫ��
    friend bool operator==(const StrBlob &lhs,const StrBlob &rhs)
    {
        return lhs.data == rhs.data; //��ָ���vector���
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
            //����ָ�붼Ϊ�գ���ָ����ͬ��vector��currָ����ͬԪ��ʱ����ȣ����򲻵�
            return (!r || lhs.curr == rhs.curr);
          else
            return false;
      }
      friend bool operator!=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          return !(lhs == rhs);
      }
      //����StrBlobPtr�ıȽϣ��������ǱȽ�����ָ��vector��Ԫ�ص�ָ�루����������
      //��ˣ�����Ҫ������StrBlobPtrָ����ͬ��vector��������û�пɱ��ԣ�Ȼ��Ƚ�ָ���λ��
      friend bool operator< (const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
          if(l == r)
            if(!r)
                return false; //����ָ�붼Ϊ�գ���Ϊ�����
            else
                return ( lhs.curr < rhs.curr);//ָ����ͬvector���Ƚ�ָ��λ��
          else
            return false; // ָ��ͬ��vectorʱ�����ܱȽ�
      }
      friend bool operator<=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
      {
          auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
          if(l==r)
            //��Ϊ�գ���ָ����ͬvector��ǰ��λ�ø���ǰ
            return (!r || lhs.curr <= rhs.curr);
          else
            return false; //ָ��ͬvectorʱ�����ܱȽ�
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
      //ǰ׺
      StrBlobPtr& operator++();
      StrBlobPtr& operator--();
      //��׺
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


//ǰ׺
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
//��׺
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
