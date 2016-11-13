#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;




void elimdups(vector<string>&vec){
    sort(vec.begin(),vec.end());
    auto new_end = unique(vec.begin(),vec.end());
    vec.erase(new_end,vec.end());
}

void biggies(vector<string>&vec,size_t sz)
{
    elimdups(vec);
//    stable_sort(vec.begin(),vec.end(),[](string const&lhs,string const &rhs)
//    {
//        return lhs.size() < rhs.size();
//    });
    auto wc = partition(vec.begin(),vec.end(),[sz](string const& s)
                      {
                          return s.size() <= sz;
                      });
    for_each(wc,vec.end(),[](const string& s){cout << s << " ";});
    cout << endl;
}




int main()
{
    auto v = vector<string>{"a","aaa","aaaa","aaaaa","aaaaaa","aaaaaaaa"};
//    auto pivot = partition(v.begin(),v.end(),predicate);
//    for(auto it = v.cbegin();it != pivot;it++)
//       cout << *it <<endl;

    biggies(v,4);

    return 0;
}
