#include <iostream>
#include <list>
#include <deque>


using namespace std;

int main()
{
    list<int> ilist = {1,2,3,4,5,6,7,8,9,10};
    deque<int> odd_d,even_d;

    list<int>::const_iterator iter = ilist.begin();
    for(;iter != ilist.cend(); iter++)
        if(*iter % 2 == 0)
            even_d.push_back(*iter);
        else
            odd_d.push_back(*iter);
    cout << "奇数值有：" ;
    for(auto iter1 = odd_d.cbegin(); iter1 != odd_d.cend();iter1++)
        cout << *iter1 << " ";
    cout << endl;

    cout << "偶数值有：" ;
    for(auto iter2 = even_d.cbegin(); iter2 != even_d.cend();iter2++)
        cout << *iter2 << " ";
    cout << endl;

    return 0;
}
