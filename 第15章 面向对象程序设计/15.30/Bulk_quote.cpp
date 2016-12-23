#include "bulk_quote.h"


double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt > quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

void Bulk_quote::debug() const
{
    std::cout //<< "data members of this class:\n"
              << "min_qty= " << quantity << " "
              << "discount= " << this->discount<< " \n";
}


