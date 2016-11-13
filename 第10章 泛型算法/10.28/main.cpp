#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{

    vector<int> vi = {1,5,5,5,5,7};
    //vector<int> vi{1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    list<int> li1,li2,li3;
    unique_copy(vi.begin(),vi.end(), front_inserter(li1));
    unique_copy(vi.begin(),vi.end(), back_inserter(li2));
    unique_copy(vi.begin(),vi.end(), inserter(li3,li3.begin()));
    for(auto c: li1)
        cout << c <<" ";
    cout << endl;
    for(auto iter = li2.cbegin();iter != li2.cend(); iter++)
        cout << *iter << " ";
    cout << endl ;
    for(auto c : li3)
        cout << c << " ";
    cout << endl;
    return 0;
}
