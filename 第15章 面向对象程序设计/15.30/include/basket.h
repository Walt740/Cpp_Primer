#ifndef BASKET_H
#define BASKET_H

#include <memory>
#include "Quote.h"
#include <set>
#include "Bulk_quote.h"

class Basket
{
public:
    //Basketʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
    void add_item(const std::shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }
    //�������캯��
    void add_item(const Quote& sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    //�ƶ����캯��
    void add_item(Quote&& sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    //��ӡÿ������ܼۺ͹���������������ܼ�
    double total_receipt(std::ostream&) const;
private:
    //�ú������ڱȽ�shared_ptr��multiset��Ա���õ���
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    //multiset���������ۣ�����compare��Ա����
    std::multiset<std::shared_ptr<Quote>,decltype(compare)*>
                                    items{compare};
};

#endif // BASKET_H
