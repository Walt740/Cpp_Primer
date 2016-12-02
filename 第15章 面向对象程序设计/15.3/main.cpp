#include <iostream>
#include <string>
using namespace std;


class Quote
{
public:
	Quote() = default;
	Quote(const std::string &b, double p) :
		bookNo(b), price(p)
	{}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { cout << "调用基类" <<endl ; return n * price; }

	virtual ~Quote() = default;

private:
	std::string bookNo;

protected:
	double  price = 0.0;

};


class Bulk_quote:public Quote  //Bulk_quote继承自Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book,double p,std::size_t qty,double disc):
        Quote(book,p),min_qty(qty),discount( disc) {}
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    virtual double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0; //适用折扣政策的最低购买量
    double discount = 0.0; //以小数表示的折扣额
};

double Bulk_quote::net_price(size_t cnt) const
{
    cout << "调用派生类" <<endl ;
    if(cnt >= min_qty)
        return cnt * (1- discount)* price;
    else
        return cnt * price;
}


double print_total(std::ostream& os, const Quote& item, size_t n);
double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}


class Limited_quote:public Bulk_quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string &book,double p,std::size_t qty,double disc):
                      Bulk_quote(book,p,qty,disc),min_qty(qty),discount( disc) {}
    double net_price(size_t cnt) const override
    {
        cout <<"Limited_quote "<<endl;
        if(cnt <= min_qty)
            return cnt * (1 - discount)*price;
        else
            return min_qty*(1-discount)*price + (cnt - min_qty)*price;
    }
private:
    size_t min_qty;
    double discount;
};

//class Limited_quote:public  Quote
//{
//public:
//    Limited_quote() = default;
//    Limited_quote(const std::string &book,double p,std::size_t qty,double disc):
//        Quote(book,p),min_qty(qty),discount( disc) {}
//    double net_price(size_t cnt) const override
//    {
//        if(cnt <= min_qty)
//            return cnt * (1 - discount)*price;
//        else
//            return min_qty*(1-discount)*price + (cnt - min_qty)*price;
//    }
//private:
//    size_t min_qty;
//    double discount;
//};

int main()
{
    Quote quo("C++ Primer",30);
    Bulk_quote bulk("C++ Primer",30,20,0.1); //折扣10%
    Limited_quote liq("C++ Primer",30,20,0.1); //折扣10%
    print_total(cout,quo,20);
    print_total(cout,bulk,10);
    print_total(cout,liq,30);
	return 0;
}








