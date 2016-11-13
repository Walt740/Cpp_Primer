#include <iostream>
#include <memory>
#include <vector>



using namespace std;

int main()
{
     shared_ptr<int > p(new int(42));
     cout << p <<endl ;
     int *q = p.get();
     {
         cout << shared_ptr<int> (q) <<endl ;
     }//程序块结束，q被销毁，它指向的内存被释放

     int foo = *p;

     cout << foo << " "<< p.get() <<endl ;
     *p = 43;

     cout << *p <<" "<< p.unique() << endl ;



     return 0;
}
