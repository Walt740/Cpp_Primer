#include "basket.h"

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;  // 保存实时计算出的总价格
    //iter指向  ISBN相同  的一批元素中的  第一个
    //upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
    for(auto iter = items.cbegin();
             iter != items.cend();
             iter = items.upper_bound(*iter))
             {
                 //当前的Basket中至少有一个该关键字的元素
                 //打印该书籍对应的项目
                 sum += print_total(os,**iter,items.count(*iter));
             }
    os << "Total Sale: " << sum << endl ;
    return sum;
}







