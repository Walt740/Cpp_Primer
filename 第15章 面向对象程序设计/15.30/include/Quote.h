#ifndef QUOTE_H
#define QUOTE_H


#include <iostream>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book= "",double sales_price = 0.0) :
        bookNo(book),price(sales_price)
        {
            cout << "Quote constructor is running" << endl ;
        }
    Quote(const Quote& e) : bookNo(e.bookNo),price(e.price)
    {
        cout << "Quote copy constructor is running" << endl ;
    }
    Quote(Quote&& e)  noexcept : bookNo(std::move(e.bookNo)),price(std::move(e.price))
    {
        cout << "Quote move constructor is running" << endl ;
    }
    Quote& operator=(const Quote& rhs)
    {
        cout << "Quote copy =()" << endl ;
        if (*this != rhs)
		{
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		return *this;
    }
    Quote& operator=(Quote&& rhs)
    {
        cout << "Quote move =()" << endl ;
        if (*this != rhs)
		{
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		return *this;
    }

    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() &&{return new Quote(std::move(*this));}

    std::string isbn() const
    {
        return  bookNo;
    }
    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }
    virtual void debug()
    {
        cout << "bookNo" << bookNo << "price = " << price << endl ;
    }
    virtual ~Quote()
    {
        cout << "Quote destructor is running" << endl;
    }
    friend ostream &operator<< (ostream &,Quote&);
    friend bool operator!=(const Quote& lhs,const Quote &rhs);
private:
    std::string bookNo;
protected:
    double price = 0.0;
};


ostream &operator<< (ostream &os, Quote& e)
{
    os << "\tUsing operator << (ostream &, Quote&);" << endl;
    return os;
}

bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
	return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}

#endif // QUOTE_H
