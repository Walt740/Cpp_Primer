#include <iostream>

using namespace std;


class Myclass
{
public:
    int operator()(int a,int b,int c)
    {
        if(a)
            return b;
        else
            return c;
    }
private:
   // int a,
};


int main()
{
    Myclass my;
    cout << my(1,2,3) << endl;
    return 0;
}
