//#include <iostream>
//#include<memory>
//#include <vector>
//#include <string>
//
//
//using namespace std;
//
//
//
//
//
//int main()
//{
// //   int *pi = new int;
// //   string *ps = new string;
////    string *ps = new string(10,'9');
////    cout << *ps << endl ;
////    delete ps;
////
////    vector<int > *pv  = new vector<int> {0,1,2,3,4,5,6,7,8,9};
////    for(auto c : *pv)
////        cout << c << endl ;
////    delete pv ;
////
////    int *pil = new int() ;
////
////    cout << *pil <<endl;
////
////    delete pil;
////
////    auto p1 = new auto(obj);
////
////    int a , b ,c ;
////    auto p2  = new auto{a};
////    delete p2;
////
////    const int  *pci = new const int(1);
////    cout << *pci << endl;
////
////
////
////    delete pci;
////
////    int* p3 = new (nothrow) int;// 如果分配失败，new返回一个空指针
////    cout << endl;
////
////    shared_ptr<int> _aa = make_shared<int>(100);
////
////    cout << *_aa <<endl ;
////
////
////    int *p(new int(42));
////    auto q = p;
////    delete p;
////    p = nullptr;
////
////    cout << q <<" "<< p<< endl;
//
//    shared_ptr<int> p(new int(42));
//    int *q = p.get();
//    {
//        shared_ptr<int> (q);
//
//    }
//
//    int foo = *p;
//    cout << foo <<endl;
//    return 0;
//}
//
//



#include <iostream>
using namespace std;

struct Data
{
	int a;
	Data():a(123){}
}*space;



void tes()
{
	Data tmp;
	tmp.a = 20;
	space = &tmp;
	//tes()结束， tmp被销毁， 即执行默认析构函数 tmp.~Data();
}

int main()
{
	tes();
	cout << space->a << endl;
}
