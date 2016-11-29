#include <iostream>
#include "Book.h"

using namespace std;

int main()
{
    Book bk1,bk2 ;
    cout <<"请输入书的信息" <<endl;
    cin >> bk1 >> bk2;

    if(bk1 == bk2)
    {
        cout << bk1 << endl;
        cout << bk2 << endl;
    }
    else if(bk1 != bk2)
    {
        cout << bk2 <<endl;
        cout << bk1 << endl;
    }


    return 0;
}
