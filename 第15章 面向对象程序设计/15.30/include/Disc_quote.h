#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote(const string &book = "" ,double sales_price = 0.0,size_t qty =0,double disc = 0.0) :
        Quote(book,sales_price),quantity(qty),discount(disc)
    {}
    double net_price(size_t cnt) const = 0;
protected:
    size_t quantity;
    double discount;
};


#endif // DISC_QUOTE_H
