#include <iostream>
#include <memory>
<<<<<<< HEAD
#include "StrBlob.h"


using namespace std;

=======
#include <vector>

using namespace std;

//class StrBlobPtr
//{
//public:
//    StrBlobPtr():curr(0) {}
//    StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
//    string& deref() const;
//    StrBlobPtr& incr();
//private:
//    shared_ptr<vector<string>> check(size_t,const string&)const;
//    weak_ptr<vector<string>> wptr;
//    size_t curr;
//
//};

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
	string& deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	StrBlobPtr& incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}

private:
	std::shared_ptr<vector<string>> check(size_t i, const string &msg) const
	{
		auto ret = wptr.lock();
		if (!ret) throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size()) throw std::out_of_range(msg);
		return ret;
	}
	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};



shared_ptr<vector<string>>
StrBlobPtr::check(size_t i,const string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr,"dereference past end");
    return (*p)[curr]; //(*p)是对象所指向的vector
}


StrBlobPtr& StrBlobPtr::incr()
{
    //如果curr已经指向容器的尾后位置，就不能递增它
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}



class StrBlob
{
public:
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;

	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob() : data(std::make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const string& s) { data->push_back(s); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	std::string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const std::string& front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const std::string& back() const
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

>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe


int main()
{
<<<<<<< HEAD
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() <<endl;
    }
//    cout <<b1.size() <<endl;
//    cout << b1.front() <<" "<<b1.back()<<endl;
//
//    const StrBlob b3 = b1;
//    cout << b3.front()<<" " << b3.back() <<endl;

    for(auto it = b1.begin();neq(it,b1.end());it.incr())
        cout << it.deref() <<endl;
=======
    shared_ptr<int> p = make_shared<int>(42);
    weak_ptr<int> wp(p);
    weak_ptr<int> qw = p ;
    qw = wp ;
    cout << p.use_count() <<endl;
    cout << qw.use_count() <<endl;
    if(shared_ptr<int> np = wp.lock())
    {
        cout << *np <<endl ;
        cout << np.use_count() << endl;
        cout << p.use_count() <<endl;
    }
    cout << p.use_count() <<endl;
>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
    return 0;
}
