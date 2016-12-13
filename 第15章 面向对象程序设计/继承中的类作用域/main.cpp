#include <iostream>
#include <string>
using namespace std;



/*
//����
class Quote
{
public:
	Quote() = default;
	Quote(const std::string &b, double p) :
		bookNo(b), price(p)
	{}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { cout << "���û���" <<endl ; return n * price; }

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
    std::size_t quantity = 0; //�ۿ����õĹ�����
    double discount = 0.0; //��ʾ�ۿ۵�С��ֵ
};
//������
class Bulk_quote:public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book,double price,std::size_t qty,double disc):
        Disc_quote(book,price,qty,disc) {}
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

//��C++�У�������ʹ�û�������ã���ָ�룩����һ���麯��ʱ��������̬��
//���Ǽ���ʹ�û���Quote�Ķ�����øú�����Ҳ��ʹ��������Bulk_quote�Ķ����������

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
    Bulk_quote *bulkP = &bulk; //��̬�����붯̬����һ��
    Quote *itemP = &bulk; //��̬�����붯̬���Ͳ�һ��
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
    int get_mem() {return  Base::mem;} //����Derived::mem
protected:
    int mem; //���ػ����е�mem
};

int main()
{
    Derived d(42);
    cout << d.get_mem() << endl;
    return 0;
}



