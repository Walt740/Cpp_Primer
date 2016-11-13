#include <iostream>
#include <vector>


using namespace std;
/*
int main()
{
    vector<int> vi{0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
        {
            iter = vi.insert(iter,*iter);
            iter += 2;
        }
        else
        {
            iter = vi.erase(iter);
        }
    }
    for(auto iter = vi.cbegin(); iter != vi.end();iter++)
        cout << *iter << " " ;
    cout<<endl;
    return 0;
}
*/

#include <forward_list>
#include <list>


int main()
{
   forward_list<int> ilist{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto prev = ilist.cbefore_begin();
	auto curr = ilist.begin();
	while (curr != ilist.end())
	{
		if (*curr % 2 == 0 )
		{
			curr = ilist.erase_after(prev);
		}
		else
		{
			curr = ilist.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}

	}
	for (auto i : ilist)
		cout << i << ' ';
	cout << endl;
    return 0;
}
