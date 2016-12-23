#ifndef BASKET_H
#define BASKET_H


#include "Quote.h"
#include <set>
#include "Bulk_quote.h"
#include <memory>


class Basket
{
public:
    //Basket使用合成的默认构造函数和拷贝控制成员
    void add_item(const std::shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }
    //拷贝构造函数
    void add_item(const Quote& sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    //移动构造函数
    void add_item(Quote&& sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    //打印每本书的总价和购物篮中所有书的总价
    double total_receipt(std::ostream&) const;
private:
    //该函数用于比较shared_ptr，multiset成员会用到它
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    //multiset保存多个报价，按照compare成员排序
    std::multiset<std::shared_ptr<Quote>,decltype(compare)*>
                                    items{compare};
};

#endif // BASKET_H


