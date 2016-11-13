#include <iostream>
#include <vector>

using namespace std;

//bool Find(vector<int>::iterator beg,vector<int>::iterator end,int i)
//{
//    while(beg != end)
//    {
//        beg++;
//        if(*beg == i)
//            return 1;
//    }
//    return 0;
//}


vector<int >::iterator
Find(vector<int>::iterator beg,vector<int>::iterator end,int i)
{
    while(beg != end)
    {
        beg++;
        if(*beg == i)
            return beg;
    }
    return end;
}


int main()
{
    vector<int> ilist = {1,2,3,4,5,6,7};
    cout << Find(ilist.begin(),ilist.end(),7) - ilist.begin()<<endl ;
    cout << Find(ilist.begin(),ilist.end(),4)- ilist.begin() <<endl ;
    cout << "Hello world!" << endl;
    return 0;
}
