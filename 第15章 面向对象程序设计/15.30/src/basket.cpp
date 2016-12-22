#include "basket.h"

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;  // ����ʵʱ��������ܼ۸�
    //iterָ��  ISBN��ͬ  ��һ��Ԫ���е�  ��һ��
    //upper_bound����һ�����������õ�����ָ������Ԫ�ص�β��λ��
    for(auto iter = items.cbegin();
             iter != items.cend();
             iter = items.upper_bound(*iter))
             {
                 //��ǰ��Basket��������һ���ùؼ��ֵ�Ԫ��
                 //��ӡ���鼮��Ӧ����Ŀ
                 sum += print_total(os,**iter,items.count(*iter));
             }
    os << "Total Sale: " << sum << endl ;
    return sum;
}







