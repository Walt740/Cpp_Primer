#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct Sales_data
{
    string isbn;
    Sales_data(string s): isbn(s){}
};

int main()
{
    Sales_data d1("aa"),d2("aaaa"),d3("aaa"),d4("z"),d5("aaaaz");
    vector<Sales_data> v{d1,d2,d3,d4,d5};
    sort(v.begin(),v.end(),[](const Sales_data& a,const Sales_data& b)
         {return a.isbn.size() < b.isbn.size();});
    for(const auto &elem :v)
        cout << elem.isbn << " ";
    cout << endl;
    return 0;
}
