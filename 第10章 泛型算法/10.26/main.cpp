#include <iostream>
#include <iterator>

#include <list>


using namespace std;




int main()
{
    list<int> lst = {1,2,3,4};
    list<int> lst2,lst3;

    copy(lst.begin(),lst.end(),front_inserter(lst2));
    copy(lst.cbegin(),lst.cend(),inserter(lst3,lst3.begin()));

    for(auto &c : lst2)
        cout << c <<endl ;
    for(auto &c : lst3)
        cout << c << endl;
    return 0;
}
