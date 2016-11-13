#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::string;
using namespace std::placeholders;
using namespace std;

bool check_size(const string& s,int i)
{
    return i > s.size();
}


int main()
{
    vector<int >vi{1,2,3,4,5,6,7,8,9};
    string  s = {"zhneg"};
    auto wc = find_if(vi.begin(),vi.end(),bind(check_size,s,_1));
    cout << *wc <<endl ;
    return 0;
}
