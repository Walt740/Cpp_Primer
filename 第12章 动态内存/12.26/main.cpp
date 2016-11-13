#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
/*
    allocator<string> alloc;
    auto const p = alloc.allocate(100);
    auto q = p;

//    alloc.construct(q++);
//    cout << *q <<endl;
//    cout << *p <<endl ;
    alloc.construct(q++,10,'c');
    cout << q << p << (int)(q-p)<<endl;

    //cout << *q <<endl;
    alloc.construct(q++,"hi");
    cout << *--q<<endl;
    return 0;
*/

	allocator<string> alloca;
	auto const p = alloca.allocate(100);
	string s;
	string *q = p;
	while (cin >> s && q != p + 100)
		alloca.construct(q++,s);
	const size_t size = q - p;
	for (size_t i = 0; i != size; i++)
		cout << p[i] << endl;
	while (q != p)
		alloca.destroy(--q);
	alloca.deallocate(p,100);
	return 0;

}
