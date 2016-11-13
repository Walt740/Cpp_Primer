#include <iostream>
#include <list>
#include <vector>

using namespace std;
bool l_v_equal(vector<int>& ivec,list<int>& ilist)
{
    if(ilist.size() != ivec.size() )
        return false;

    auto lb = ilist.cbegin();
    auto le = ilist.cend();
    auto vb = ivec.cbegin();
    for(;lb != le;lb++,vb++)
    {
        if(*lb != *vb)
            return false;
    }
    return true;
}

/*方法一
int main()
{
    vector<int> ivec = {1,2,3,4,5};
    list<int> ilist1 = {1,2,3,4,5};
    list<int> ilist2 = {1,2,3};
    list<int> ilist3 = {1,2,3,4,5,6};

    cout << l_v_equal(ivec,ilist1) <<endl ;
    cout << l_v_equal(ivec,ilist2) <<endl ;
    cout << l_v_equal(ivec,ilist3) <<endl ;
    return 0;
}
*/

//方法二
int main()
{

    vector<int> ivec = {1,2,3,4,5,6};
    list<int> ilist1 = {1,2,3,4,5};
    list<int> ilist2 = {1,2,3};
    list<int> ilist3 = {1,2,3,4,5,6};

    //将list容器中的元素拷贝到vector中
    vector<int> ivec1 = {ilist1.cbegin(),ilist1.cend()};
    vector<int> ivec2 = {ilist2.cbegin(),ilist2.cend()};
    vector<int> ivec3 = {ilist3.cbegin(),ilist3.cend()};

    cout << (ivec == ivec1) <<endl ;
    cout << (ivec == ivec2) <<endl ;
    cout << (ivec == ivec3) <<endl ;

}
