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
        //û�����룡
        cerr << "No data ? " << endl ;
        return -1;
    }
    sort(vs.begin(),vs.end(),compareIsbn);

    auto l = vs.begin();
    while(l != vs.end())
    {
        auto item = *l; //��ͬisbn�Ľ��׼�¼�еĵ�һ��
        //�ں�����¼�в��ҵ�һ��ISBN��item��ͬ��
        auto r = find_if(l + 1,vs.end(),[item](const Sales_data &item1){return item1.isbn() != item.isbn();});
        cout << accumulate(l + 1, r ,item) << endl;
        l = r;
    }
    return 0;
}


