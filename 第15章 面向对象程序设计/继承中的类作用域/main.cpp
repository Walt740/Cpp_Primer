#include <iostream>
#include <string>
using namespace std;



/*
//基类
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
    virtual void debug()
    {
        cout << " bookNo = " << bookNo << " price = "<< price << endl;
    }
private:
	std::string bookNo;

protected:
	double  price = 0.0;

};

class Disc_quote:public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book,double price,
               std::size_t qty,double disc):
                   Quote(book,price),quantity(qty),discount(disc){}
    std::pair<size_t,double> discount_policy() const
    {
        return {quantity,discount};
    }
    virtual double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0; //折扣适用的购买量
    double discount = 0.0; //表示折扣的小数值
};
//派生类
class Bulk_quote:public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book,double price,std::size_t qty,double disc):
        Disc_quote(book,price,qty,disc) {}
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(std::size_t cnt) const override
    {
        if(cnt > quantity)
            return cnt * (1-discount)*price;
        else
            return cnt * price;
    }
    //练习15.11
    virtual void debug() override
    {
        Quote::debug();//bookNo变量是private，所以不能直接访问bookNo
                    //智只能调用基类的debug()函数来显示
        cout << " min_qty = " << min_qty << " discount = " << discount<< endl;
    }
private:
    std::size_t min_qty = 0; //适用折扣政策的最低购买量
    double discount = 0.0; //以小数表示的折扣额
};

//double Bulk_quote::net_price(size_t cnt) const
//{
//    cout << "调用派生类" <<endl ;
//    if(cnt >= min_qty)
//        return cnt * (1- discount)* price;
//    else
//        return cnt * price;
//}


//double print_total(std::ostream& os, const Quote& item, size_t n);

//在C++中，当我们使用基类的引用（或指针）调用一个虚函数时将发生动态绑定
//我们既能使用基类Quote的对象调用该函数，也能使用派生类Bulk_quote的对象调用它；

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}


class Limited_quote:public Disc_quote
{
public:
    Limited_quote(const std::string &book,double price,std::size_t qty,double disc):
        Disc_quote(book,price,qty,disc) {}

    double net_price(size_t cnt) const override
    {
        if(cnt <= quantity)
            return cnt * (1 - discount ) *price;
        else
            return quantity*(1 - discount)*price + (cnt - quantity)* price;
    }
};




int main()
{
    Bulk_quote bulk;
    Bulk_quote *bulkP = &bulk; //静态类型与动态类型一致
    Quote *itemP = &bulk; //静态类型与动态类型不一致
    bulkP->discount_policy();
    itemP->discount_policy();
	return 0;
}

*/


struct Base
{
    Base():mem(0){}
protected:
    int mem;

};

struct Derived: public Base
{
    Derived(int i):mem(i){ }
    int get_mem() {return  Base::mem;} //返回Derived::mem
protected:
    int mem; //隐藏基类中的mem
};

int main()
{
    Derived d(42);
    cout << d.get_mem() << endl;
    return 0;
}



