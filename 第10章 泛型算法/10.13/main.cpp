#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


inline bool predicate(const string &s)
{
    return s.size() <= 5;
}

int main()
{
    auto v = vector<string>{"a","aaa","aaaa","aaaaa","aaaaaa","aaaaaaaa"};
    auto pivot = partition(v.begin(),v.end(),predicate);
    for(auto it = v.cbegin();it != pivot;it++)
       cout << *it <<endl;
    return 0;
}
