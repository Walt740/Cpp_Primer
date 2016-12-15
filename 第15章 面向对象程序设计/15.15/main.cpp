#include <iostream>
#include <string>
using namespace std;

//基类
class Quote
{
    friend bool operator != (const Quote& lhs, const Quote &rhs);
public:
	Quote() = default;
	Quote(const std::string &b, double p) :
		bookNo(b), price(p)
	{
		cout << "基类的构造函数" << endl;
	}
    Quote(const Quote& q) : bookNo(q.bookNo),price(q.price)
    {
        std::cout << "基类的拷贝构造函数"<< std::endl ;
    }
    Quote(Quote &&q) noexcept :bookNo(std::move(q.bookNo)),price(std::move(q.price))
    {
        std:: cout <<"基类的移动构造函数"<< std::endl ;
    }
    Quote &operator= (const Quote& rhs)
    {
        if(*this != rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "拷贝赋值运算符" << std::endl ;
        return *this;
    }
    Quote &operator=(Quote&& rhs) noexcept
    {
        if(*this != rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price  = std::move(rhs.price);
        }
        std:: cout << "移动赋值运算符" << endl ;
        return *this;
    }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { cout << "调用基类" <<endl ; return n * price; }
	//如果我们删除的是一个指向派生类对象的基类指针，则需要虚析构函数
	virtual ~Quote()
	{
	    cout << "基类的析构函数" << endl ;
	}// = default;
    virtual void debug()
    {
        cout << " bookNo = " << bookNo << " price = "<< price << endl;
    }
private:
	std::string bookNo;

protected:
	double  price = 0.0;

};

bool operator != (const Quote& lhs, const Quote &rhs)
{
    return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}

//抽象基类
class Disc_quote:public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book,double price,
               std::size_t qty,double disc):
                   Quote(book,price),quantity(qty),discount(disc){
		cout << "抽象基类的构造函数" << endl;
	}
	~Disc_quote()// = delete;
	{
		cout << "抽象基类的析构函数" << endl;
	}//=default;
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
        Disc_quote(book,price,qty,disc) {
		cout << "派生类的构造函数" << endl;
	}
	//拷贝构造函数
	Bulk_quote(const Bulk_quote& bq):Disc_quote(bq)
	{
	    std:: cout << "派生类的拷贝构造函数" << std::endl;
	}
	// move constructor

    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq))
    {
        std::cout << "派生类的移动构造函数" << endl ;
    }
    Bulk_quote& operator= (const Bulk_quote &rhs)
    {
        Disc_quote:: operator= (rhs);
        std:cout << "派生类的拷贝赋值运算符"  << endl ;
        return *this;
    }

    Bulk_quote& operator= ( Bulk_quote &&rhs)
    {
        Disc_quote:: operator= (std::move(rhs));
        std:cout << "派生类的移动赋值运算符"  << endl ;
        return *this;
    }


    ~Bulk_quote()
    {
        cout << "派生类的析构函数"<< endl ;
    }
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
/*
在C++中，当我们使用基类的引用（或指针）调用一个虚函数时将发生动态绑定
我们既能使用基类Quote的对象调用该函数，也能使用派生类Bulk_quote的对象调用它；
*/
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
/*
    Quote quo("C++ Primer",30);
    Bulk_quote bulk("C++ Primer",30,20,0.1); //折扣10%
    Limited_quote lq("C++ Primer",30,20,0.1);


    print_total(cout,quo,20);
    print_total(cout,bulk,10);
    print_total(cout,lq,100);
    quo.debug();
    bulk.debug();
*/
    Quote *itemP = new  Quote;
    delete itemP;
    itemP = new Bulk_quote("yinhao",10,1,20);

    delete itemP;


	getchar();
	return 0;
}








