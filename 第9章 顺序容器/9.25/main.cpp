#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
//    auto it = lst.begin();
//    while(it != lst.end())
//        if(*it % 2)
//            it = lst.erase(it);
//        else
//            ++it;
//    for(auto it : lst)
//        cout << it << " ";
//    cout << endl;

    //¿ªÊ¼É¾³ıÔªËØ
    auto elem1 = lst.begin();
    auto elem2 = lst.end() ;
    //lst.clear();
    elem1 = lst.erase(elem1,elem2);
    for(auto it : lst)
        cout << it << " ";
    cout << endl ;



    return 0;
}
