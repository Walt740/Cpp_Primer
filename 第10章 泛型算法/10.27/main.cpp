
//unique_copy

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
    list<int> li;
    unique_copy(vi.begin(),vi.end(), front_inserter(li));
//    unique_copy(vi.begin(),vi.end(), back_inserter(li));
//    unique_copy(vi.begin(),vi.end(), inserter(li,li.begin()));
    for(auto c: li)
        cout << c <<" ";
    cout << endl;


    return 0;
}
