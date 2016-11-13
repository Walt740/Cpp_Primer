#include <iostream>
#include "Sales_data.h"
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<Sales_data> vs;
    istream_iterator<Sales_data> in_iter(cin);
    istream_iterator<Sales_data> eof;

    while(in_iter != eof)
        vs.push_back(*in_iter++);
    if(vs.empty())
    {
        //没有输入！
        cerr << "No data ? " << endl ;
        return -1;
    }
    sort(vs.begin(),vs.end(),compareIsbn);

    auto l = vs.begin();
    while(l != vs.end())
    {
        auto item = *l; //相同isbn的交易记录中的第一个
        //在后续记录中查找第一个ISBN与item不同者
        auto r = find_if(l + 1,vs.end(),[item](const Sales_data &item1){return item1.isbn() != item.isbn();});
        cout << accumulate(l + 1, r ,item) << endl;
        l = r;
    }
    return 0;
}


