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







class Bulk_quote: public Quote
{
    friend ostream &operator << (ostream& os,Bulk_quote &bq);
public:
    Bulk_quote(const string &book= "",double sales_price =0.0,size_t qty = 0,double disc= 0.0):
        Quote(book,sales_price),min_qty(qty),discount(disc)
    {
        cout << "Bulk_quote constructor is runnning " << endl ;
    }
    Bulk_quote(const Bulk_quote&  bq) : Quote(bq)
    {
        cout << "Bulk_quote copy constructor is running" << endl ;
        min_qty = bq.min_qty;
        discount = bq.discount;
    }
    Bulk_quote(Bulk_quote &&bq) : Quote(std::move(bq))
    {
        cout << "Bulk_quote move constructor is running" << endl ;
        min_qty = std::move(bq.min_qty);
        discount = std::move(bq.discount);
    }
    Bulk_quote &operator=(const Bulk_quote& rhs)
    {
        cout << "Bulk_quote copy =()" <<endl;
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        return *this;
    }
    Bulk_quote &operator=(const Bulk_quote&& rhs)
    {
        cout << "Bulk_quote move =()" <<endl;
        Quote::operator=(std::move(rhs));
        min_qty = std::move(rhs.min_qty);
        discount = std::move(rhs.discount);
        return *this;
    }
    double net_price(size_t cnt) const
    {
        if(cnt > min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
    ~Bulk_quote()
    {
        cout << "Bulk_quote destructor is running " << endl;
    }
private:
    size_t min_qty;
    double discount;
};

ostream &operator << (ostream &os,Bulk_quote &bq)
{
    os << "\tUsing operator << (ostream &,Bulk_quote &)" << endl;
    return os;
}


int main()
{
    Quote base("C++ Primer",128.0);
    Quote base1("Python");
    base1 = std::move(base);
//    Bulk_quote bulk("Core Python Programming",89,5,0.19);
//    Bulk_quote bulk1(bulk);
//    cout << base <<endl;
//    cout << bulk <<endl;
    cout << base1 << endl;
    return 0;
}
