#include <iostream>
#include "Sales_data.h"



using namespace std;

int main()
{
//    Sales_data data1 = "C++ Primer 5th";
//    cout << data1 <<endl;
//    Sales_data data2;
//    cin >> data2;
//    cout << data2 << endl;

    Sales_data data1("C" ,40 ,20 ,30);
    Sales_data data2("C" ,20 ,20 ,30);
    Sales_data data3("C" ,30 ,20 ,30);
    Sales_data data4("C" ,40 ,20 ,30);
    data1+=data2;
    data1+=data3;
    data1-=data4;
    cout << data1 << endl;

    return 0;
}
