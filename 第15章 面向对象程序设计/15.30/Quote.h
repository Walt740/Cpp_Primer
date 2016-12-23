#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote
{
    friend bool operator!=(const Quote& lhs,const Quote &rhs);
public:
    //默认构造函数
    Quote() = default;
    //构造函数
    Quote(const std::string &book= "",double sales_price = 0.0) :
        bookNo(book),price(sales_price)
    {
            std::cout << "Quote constructor is running" << std::endl ;
    }
    //拷贝构造函数
    Quote(const Quote& e) : bookNo(e.bookNo),price(e.price)
    {
        std::cout << "Quote copy constructor is running" << std::endl ;
    }
    //移动构造函数
    Quote(Quote&& e)  noexcept : bookNo(std::move(e.bookNo)),price(std::move(e.price))
    {
        std::cout << "Quote move constructor is running" << std::endl ;
    }
    //拷贝赋值
    Quote& operator=(const Quote& rhs)
    {
        std::cout << "Quote copy =()" << std::endl ;
        if (*this != rhs)
		{
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		return *this;
    }
    //移动赋值
    Quote& operator=(Quote&& rhs)
    {
        std::cout << "Quote move =()" << std::endl ;
        if (*this != rhs)
		{
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		return *this;
    }
    //克隆自身
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() &&{return new Quote(std::move(*this));}

    std::string isbn() const{  return  bookNo;}
    virtual double net_price(std::size_t n) const { return n * price;}
    virtual void debug() const;
    virtual ~Quote()
    {
        std::cout << "Quote destructor is running" << std::endl;
    }
    //friend ostream &operator<< (ostream &,Quote&);

private:
    std::string bookNo;
protected:
    double price = 0.0;
};


//ostream &operator<< (ostream &os, Quote& e)
//{
//    os << "\tUsing operator << (ostream &, Quote&);" << endl;
//    return os;
//}

bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
	return lhs.bookNo != rhs.bookNo
                      &&
           lhs.price != rhs.price;
}

//非成员
double print_total(std::ostream &os,const Quote &item, size_t n );

#endif // QUOTE_H








