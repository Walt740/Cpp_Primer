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
     }//����������q�����٣���ָ����ڴ汻�ͷ�

     int foo = *p;

     cout << foo << " "<< p.get() <<endl ;
     *p = 43;

     cout << *p <<" "<< p.unique() << endl ;



     return 0;
}
