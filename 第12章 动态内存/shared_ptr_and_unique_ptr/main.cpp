#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main()
{
//    string str;
//    shared_ptr<string>p1 = make_shared<string>(str);
//    if(p1 && p1->empty())
//        *p1 =  "hi";
//    cout  << *p1 << endl;
//    cout << p1.get() << endl;  //返回p中保存的指针
//    shared_ptr<int> p2 = make_shared<int>();  //int对象进行值初始化
//    cout << *p2 << endl;
//    int a = 1;
//    shared_ptr<int> p3 = make_shared<int>(a);
//    cout << *p3<< endl;
//    auto p6 = make_shared<vector<string>>();
//    cout << p6.unique() << endl;
//    shared_ptr<string> p4(p1) ;  //
//    cout << p4.unique() <<endl ;
//    cout <<p4.use_count()<<endl;
//    cout << p1.use_count() <<endl;

    auto p = make_shared<int>(42);
    cout << p.unique() << "  " ;
    cout << p.use_count() <<endl;
    auto q(p);
    cout << q.unique() << endl;  //因为q已有共享对象的智能指针
    cout << p.unique() <<endl ;


    cout << q.use_count()<<" "<< p.use_count() << endl;


    q = make_shared<int>(12);
    cout << q.use_count() <<endl;

    auto r = make_shared<int>(42);
    r = q; //给r赋值，令它指向另一个地址
        //递增q指向的对象的引用计数
        //递减r原来指向的对象的引用计数
        //r原来指向的对象已没有引用者，会自动释放对象

    cout << r.use_count() << " "<< q.use_count() <<endl;


    vector<string> v1; //空的vector
    {
        vector<string> v2 = {"a","an","the"};
        v1 = v2;
    } // v2被销毁，其中的元素也被销毁
    //v1有三个元素，是原来v2中的元素的拷贝



    return 0;
}
