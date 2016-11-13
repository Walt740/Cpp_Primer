#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
    vector<int > c1 ,c2 = {1,2,3,4};
    c1 = c2;
    //c1 = {1,2,3};
    //cout << c1.size() <<endl ;
    array<int,10> a1 = {0,1,2,3,4,5,6,7,8,9};
    array<int,10> a2 = {10};

    cout << a1.size() <<endl;
    cout << a2.size() <<endl;
    cout << a2[3] <<endl;
//    a1 = a2;
//    a2 = {10,10};

    //swap(a1,a2);
    a1.swap(a2);
    cout << a1[0] <<endl;

    c1.assign({1,2,3,4});
    cout << c1[0] <<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
