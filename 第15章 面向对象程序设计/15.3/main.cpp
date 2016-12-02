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
	virtual double net_price(std::size_t n) const { return n * price; }

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
    Bulk_quote(const std::string &,double ,std::size_t,double);
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0; //适用折扣政策的最低购买量
    double discount = 0.0; //以小数表示的折扣额
};

double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt >= min_qty)
        return cnt * (1- discount)* price;
    else
        return cnt * price;
}


double print_total(std::ostream& os, const Quote& item, size_t n);

int main()
{
    Quote quo;
    Bulk_quote bulk;
    quo.

    bulk.bookNo
	return 0;
}


double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}





