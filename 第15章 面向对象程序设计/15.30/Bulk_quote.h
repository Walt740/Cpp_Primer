#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "basket.h"
#include "Disc_quote.h"


class Bulk_quote: public Disc_quote
{
    //friend std::ostream &operator << (std::ostream& os,Bulk_quote &bq);
public:
//    Bulk_quote(const string &book= "",double sales_price =0.0,size_t qty = 0,double disc= 0.0):
//        Quote(book,sales_price),min_qty(qty),discount(disc)
//    {
//        cout << "Bulk_quote constructor is runnning " << endl ;
//    }
//    Bulk_quote(const Bulk_quote&  bq) : Quote(bq)
//    {
//        cout << "Bulk_quote copy constructor is running" << endl ;
//        min_qty = bq.min_qty;
//        discount = bq.discount;
//    }
//    Bulk_quote(Bulk_quote &&bq) : Quote(std::move(bq))
//    {
//        cout << "Bulk_quote move constructor is running" << endl ;
//        min_qty = std::move(bq.min_qty);
//        discount = std::move(bq.discount);
//    }
//    Bulk_quote &operator=(const Bulk_quote& rhs)
//    {
//        cout << "Bulk_quote copy =()" <<endl;
//        Quote::operator=(rhs);
//        min_qty = rhs.min_qty;
//        discount = rhs.discount;
//        return *this;
//    }
//    Bulk_quote &operator=(const Bulk_quote&& rhs)
//    {
//        cout << "Bulk_quote move =()" <<endl;
//        Quote::operator=(std::move(rhs));
//        min_qty = std::move(rhs.min_qty);
//        discount = std::move(rhs.discount);
//        return *this;
//    }
    using Disc_quote::Disc_quote;
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}

    void debug() const override;
    double net_price(size_t cnt) const;

    ~Bulk_quote()
    {
        std::cout << "Bulk_quote destructor is running " << std::endl;
    }
};

//std::ostream &operator << (std::ostream &os,Bulk_quote &bq)
//{
//    os << "\tUsing operator << (ostream &,Bulk_quote &)" << std::endl;
//    return os;
//}




#endif // BULK_QUOTE_H



