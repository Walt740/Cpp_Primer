<<<<<<< HEAD
//#include <iostream>
//#include <memory>
//
//
//
//using namespace std;
//
//
//int main()
//{
//    unique_ptr<string> p1(new string("yinhao"));
//    cout << *p1 <<endl ;
//    unique_ptr<string> p2(p1.release());
//    cout << " " << *p2 <<endl;
//    unique_ptr<string> p3(new string("zheng"));
//    cout << *p3 << endl;
//    p2.reset(p3.release());
//    //cout << *p2 << " " << *p3 << endl;
//    cout << p2.release() <<endl;
//
//
//
//    return 0;
//}




#include <iostream>
#include <memory>



using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;

struct connection
{

};
struct destination
{

};


connection connect(destination* pd)
{
	cout << "������" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "�ر�����" << endl;

}

void f(destination &d)
{
	cout << "ֱ�ӹ���connect" << endl;
	connection c = connect(&d);

	cout << endl;
}

void end_connection(connection* p) { disconnect(*p); }


void f1(destination &d)
{
	cout << "ʹ������ָ�����connect" << endl;
	connection c = connect(&d);
	int a = 5;
	unique_ptr<connection,decltype(end_connection)*> p(&c,end_connection);
	//�������⣺
	//
//	shared_ptr<connection> p(&c,[&](connection* p) { disconnect(c); cout << a << endl; });
	//shared_ptr<connection> p(&c,end_connection);
	cout << endl;
}
int main()
{
	destination d;
	f(d);
	f1(d);

    unique_ptr<int> a(new int(100));
    auto b = a;
=======
#include <iostream>
#include <memory>
#include <string>

using std::unique_ptr;
using std::string;
using std::cout;
using std::endl;
int main()
{
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));
    unique_ptr<string> p3(new string("Stegosaurus"));



    cout << *p3 <<endl;
    //unique_ptr<string> p4(p3);//����unique_ptr��֧�ֿ���
    //p3.release();
    //cout << p3 << *p3 <<endl;
    //p3.reset();
    //cout << *p3 <<endl;
    unique_ptr<string> p4(p3.release());
    cout << *p4 <<endl;
    //p4.reset();
    //cout << *p4 <<endl ;
    unique_ptr<string> p3(new string("Trex"));
>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe






<<<<<<< HEAD
	return 0;
=======
    return 0;
>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
}
