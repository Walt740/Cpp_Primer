#include <iostream>
#include <numeric>
#include <vector>

using namespace std;



//int main()
//{
//    vector<int> vi{0,1,2,3,4,5,6,7,8,9};
//    //fill(vi.begin(),vi.end(),0);
//
//    fill(vi.begin(),vi.begin()+vi.size()/2,10);
//    for(auto c :vi )
//    cout << c <<endl;
//
//    return 0;
//
//}



int main()
{
    vector<int> vec{0,1,2,3,4,5};
    //fill(vec.begin(),vec.end(),0);
    //fill_n(vec.begin(),vec.size(),0);
    fill_n(vec.begin(),10,0);
    for(auto iter = vec.cbegin();iter != vec.cend();iter++)
        cout << *iter <<endl;
}
