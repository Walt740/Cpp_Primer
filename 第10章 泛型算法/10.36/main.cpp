#include <iostream>
#include <list>
#include <algorithm>


using namespace std;

int main()
{
    list<int> lst{1,0,2,1,0,2,0,5,0,5,0,40};
    auto wr = find(lst.crbegin(),lst.crend(),0);
    cout << distance(wr, lst.crend()) <<endl ;
    return 0;
}


//#include <iostream>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	list<int> l = { 1, 2, 0, 4, 5, 6, 7, 0, 9 };
//	auto it = find(l.crbegin(), l.crend(), 0);
//
//	cout << distance(it, l.crend()) << endl;
//	return 0;
//}
