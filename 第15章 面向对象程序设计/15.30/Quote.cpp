#include "Quote.h"


void
Quote::debug() const
{
   std:: cout << "bookNo" << bookNo << "price = " << price << std::endl ;
}

//计算并打印销售给定数量的某种书籍所得的费用
double
print_total(std::ostream &os,const Quote &item ,size_t n)
{
    //根据传入item形参的对象类型调用Quote::net_price
    //或者Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<< n <<"total due: " << ret << std::endl;
    return ret;
}


