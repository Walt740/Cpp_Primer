#include <iostream>
using namespace std;


//理解类的声明和定义。
//声明的作用是告知程序类的名字合法可用；
//定义的作用是规定类的细节

class Y;
class X
{
    Y y;
};
class Y
{
    X x;
};




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
