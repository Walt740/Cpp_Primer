#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> iv= {1,2,3,4,5,6};
    //vector<int> iv;
    cout << "iv.at(0) = " << iv.at(0) <<endl ;
    cout << "iv[0] = " << iv[0] <<endl ;
    cout << "iv.front() = " << iv.front() <<endl ;

    cout << "*iv.begin() = " << *iv.begin() <<endl ;
    return 0;
}
