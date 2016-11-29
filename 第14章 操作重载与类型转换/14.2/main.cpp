#include <iostream>
#include "Sales_data.h"


using namespace std;

int main()
{
    Sales_data data1("hello"),data2("world");
    cin >> data1 >> data2 ;
    cout << data1 + data2 <<endl;
    return 0;
}
