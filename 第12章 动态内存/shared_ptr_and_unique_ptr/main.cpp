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
//    cout << p1.get() << endl;  //����p�б����ָ��
//    shared_ptr<int> p2 = make_shared<int>();  //int�������ֵ��ʼ��
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
    cout << q.unique() << endl;  //��Ϊq���й�����������ָ��
    cout << p.unique() <<endl ;


    cout << q.use_count()<<" "<< p.use_count() << endl;


    q = make_shared<int>(12);
    cout << q.use_count() <<endl;

    auto r = make_shared<int>(42);
    r = q; //��r��ֵ������ָ����һ����ַ
        //����qָ��Ķ�������ü���
        //�ݼ�rԭ��ָ��Ķ�������ü���
        //rԭ��ָ��Ķ�����û�������ߣ����Զ��ͷŶ���

    cout << r.use_count() << " "<< q.use_count() <<endl;


    vector<string> v1; //�յ�vector
    {
        vector<string> v2 = {"a","an","the"};
        v1 = v2;
    } // v2�����٣����е�Ԫ��Ҳ������
    //v1������Ԫ�أ���ԭ��v2�е�Ԫ�صĿ���



    return 0;
}
