#include <iostream>
#include <forward_list>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter%2)
        {
            iter = vi.insert(iter,*iter);
            iter += 2;
        }
        else
        {
            iter = vi.erase(iter);
        }
    }
    for(auto i : vi)
        cout << i << " ";
    cout <<endl;
    return 0;
}



/**/

/*
int main()
{
    forward_list<int> li = {0,1,2,3,4,5,6,7,8,9};
    auto prev = li.before_begin();
    auto curr = li.begin();
    cout << *li.begin() << endl;
    while(curr != li.end())
    {
        if(*curr%2)  //为奇数
        {
            //1,1,2,3,4,5,6,7,
            prev = li.insert_after(prev,*curr);
            prev++;
            curr++;

//              插入到当前结点之后
//                curr = li.insert_after(curr,*curr);
//                prev = curr;
//                curr++;

        }
        else
        {    // 1,1,2,3
            curr = li.erase_after(prev);
        }
    }

    for(auto i : li)
        cout << i << " ";
    cout <<endl;
    return 0;
}
*/

/*
int main()
{
    list<int> ilist = {0,1,2,3,4,5,6,7,8,9};
    auto iter = ilist.begin();
    while(iter != ilist.end())
    {
        if(*iter%2)
        {
            iter = ilist.insert(iter,*iter);
            iter++;
            iter++;
        }
        else
        {
            iter = ilist.erase(iter);
        }
    }
    for(auto i : ilist)
        cout << i << " ";
    cout <<endl;
    return 0;
}


*/
