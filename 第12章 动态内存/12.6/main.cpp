//#include <iostream>
//#include <vector>
//#include <memory>
//
//using namespace std;
//
//vector<int>* alloc_vector()
//{
//
//    auto pv(new vector<int>());
//    int i;
//    while(cin >>i)
//        pv->push_back(i);
//    return pv;
//}
//
//
//
//int main()
//{
//    auto p = alloc_vector();
//    for(auto i : *p)
//        cout << i << endl;
//    delete p;
//    return 0;
//}



#include <iostream>
#include <vector>
#include <memory>


using std::vector;
using std::cin;
using std::cout;
using std::endl;
//
//vector<int>* alloc_vector()
//{
//    vector<int> *pvi = new vector<int>();
//    int i;
//    while(cin >> i)
//        (*pvi).push_back(i);
//
//    return pvi;
//}
//
//int main()
//{
//    vector<int>* vi = alloc_vector();
//    for(auto c : *vi )
//        cout << c <<endl;
//    return 0;
//}

vector <int>* alloc_vector()
{
    return new vector<int>();
}

void assign_vector(vector<int>* p)
{
    int i;
    while(cin >> i)
        p->push_back(i);
}

void print_vector(vector<int>* p)
{
    for(auto i : *p)
        cout << i << endl;
}


int main()
{
    auto p = alloc_vector();
    assign_vector(p);
    print_vector(p);
    delete p;
    return 0;
}


