#include "Quote.h"


void
Quote::debug() const
{
   std:: cout << "bookNo" << bookNo << "price = " << price << std::endl ;
}

//���㲢��ӡ���۸���������ĳ���鼮���õķ���
double
print_total(std::ostream &os,const Quote &item ,size_t n)
{
    //���ݴ���item�βεĶ������͵���Quote::net_price
    //����Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<< n <<"total due: " << ret << std::endl;
    return ret;
}


