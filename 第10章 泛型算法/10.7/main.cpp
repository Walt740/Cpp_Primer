#include <iostream>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

//int main()
//{
//
//    vector<int> vec;
//    auto it = back_inserter(vec);
//    *it = 42;
//    for(auto &c : vec)
//        cout << c << endl;
//    return 0;
//}


//int main()
//{
//    int a1[] = {0,1,2,3,4,5,6,7,8,9};
//    int a2[sizeof(a1)/sizeof(*a1)];
//    //retָ�򿽱���a2��βԪ��֮���λ��
//    auto ret = copy(begin(a1),end(a1),a2);
//
//    cout << ret <<endl;
//    for(int* iter = begin(a2);iter != end(a2);iter++)
//        cout << *iter << endl;
//}


//int main()
//{
//    vector<int>vec(10); //Ϊ��
//    list<int>lst;
//    int i;
//    while(cin >> i )
//        lst.push_back(i);
//    copy(lst.begin(),lst.end(),vec.begin());
//    cout << vec[0] << endl;
//}


int main()
{
    vector<int> vec(10); //Ϊ��
//vec.reserve(10); //
    fill_n(vec.begin(),vec.size(),0);

    for(auto &c : vec)
        cout << c << endl;
    return 0;
}
