#include <iostream>

using namespace std;


int func(int m,int n)
{
    if(m%n == 0)
        return n;
    else
        return func(n,m%n);
}


int main()
{
    cout << func(2012,2102) <<endl;
//    int i = 5;
//    auto f = [i]() mutable ->bool {
//        if(i > 0 )
//        {    --i;
//            return false;
//        }
//        else{
//            //i = 0;
//            return true ;
//        }
//    };
//    int j = 5;
//    while( j >= 0 )
//    {
//        cout << f() << " ";
//        --j;
//    }
//    //cout<< "complete" <<endl ;
//    return 0;
}
