#include <iostream>

using namespace std;
 //  typedef string :: size_type pos;
class Screen
{
public :
 //   typedef string :: size_type pos;
    void dummy_fun(pos height)
    {
        cursor = width * height;
    }
private:
    pos cursor = 0;
    pos height = 0 ,width = 0;
   typedef string :: size_type pos;
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
