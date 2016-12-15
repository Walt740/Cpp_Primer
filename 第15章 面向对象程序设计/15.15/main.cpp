#include <iostream>
#include <string>
using namespace std;

//����
class Quote
{
    friend bool operator != (const Quote& lhs, const Quote &rhs);
public:
	Quote() = default;
	Quote(const std::string &b, double p) :
		bookNo(b), price(p)
	{
		cout << "����Ĺ��캯��" << endl;
	}
    Quote(const Quote& q) : bookNo(q.bookNo),price(q.price)
    {
        std::cout << "����Ŀ������캯��"<< std::endl ;
    }
    Quote(Quote &&q) noexcept :bookNo(std::move(q.bookNo)),price(std::move(q.price))
    {
        std:: cout <<"������ƶ����캯��"<< std::endl ;
    }
    Quote &operator= (const Quote& rhs)
    {
        if(*this != rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "������ֵ�����" << std::endl ;
        return *this;
    }
    Quote &operator=(Quote&& rhs) noexcept
    {
        if(*this != rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price  = std::move(rhs.price);
        }
        std:: cout << "�ƶ���ֵ�����" << endl ;
        return *this;
    }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { cout << "���û���" <<endl ; return n * price; }
	//�������ɾ������һ��ָ�����������Ļ���ָ�룬����Ҫ����������
	virtual ~Quote()
	{
	    cout << "�������������" << endl ;
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

//�������
class Disc_quote:public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book,double price,
               std::size_t qty,double disc):
                   Quote(book,price),quantity(qty),discount(disc){
		cout << "�������Ĺ��캯��" << endl;
	}
	~Disc_quote()// = delete;
	{
		cout << "����������������" << endl;
	}//=default;
    virtual double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0; //�ۿ����õĹ�����
    double discount = 0.0; //��ʾ�ۿ۵�С��ֵ
};



//������
class Bulk_quote:public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book,double price,std::size_t qty,double disc):
        Disc_quote(book,price,qty,disc) {
		cout << "������Ĺ��캯��" << endl;
	}
	//�������캯��
	Bulk_quote(const Bulk_quote& bq):Disc_quote(bq)
	{
	    std:: cout << "������Ŀ������캯��" << std::endl;
	}
	// move constructor

    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq))
    {
        std::cout << "��������ƶ����캯��" << endl ;
    }
    Bulk_quote& operator= (const Bulk_quote &rhs)
    {
        Disc_quote:: operator= (rhs);
        std:cout << "������Ŀ�����ֵ�����"  << endl ;
        return *this;
    }

    Bulk_quote& operator= ( Bulk_quote &&rhs)
    {
        Disc_quote:: operator= (std::move(rhs));
        std:cout << "��������ƶ���ֵ�����"  << endl ;
        return *this;
    }


    ~Bulk_quote()
    {
        cout << "���������������"<< endl ;
    }
    //���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
    double net_price(std::size_t cnt) const override
    {
        if(cnt > quantity)
            return cnt * (1-discount)*price;
        else
            return cnt * price;
    }
    //��ϰ15.11
    virtual void debug() override
    {
        Quote::debug();//bookNo������private�����Բ���ֱ�ӷ���bookNo
                    //��ֻ�ܵ��û����debug()��������ʾ
        cout << " min_qty = " << min_qty << " discount = " << discount<< endl;
    }
private:
    std::size_t min_qty = 0; //�����ۿ����ߵ���͹�����
    double discount = 0.0; //��С����ʾ���ۿ۶�
};

//double Bulk_quote::net_price(size_t cnt) const
//{
//    cout << "����������" <<endl ;
//    if(cnt >= min_qty)
//        return cnt * (1- discount)* price;
//    else
//        return cnt * price;
//}


//double print_total(std::ostream& os, const Quote& item, size_t n);
/*
��C++�У�������ʹ�û�������ã���ָ�룩����һ���麯��ʱ��������̬��
���Ǽ���ʹ�û���Quote�Ķ�����øú�����Ҳ��ʹ��������Bulk_quote�Ķ����������
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
    Bulk_quote bulk("C++ Primer",30,20,0.1); //�ۿ�10%
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








