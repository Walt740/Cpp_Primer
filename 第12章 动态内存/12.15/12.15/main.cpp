#include <iostream>
#include <memory>



using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;


struct connection
{

};
struct destination
{

};


connection connect(destination* pd)
{
	cout << "打开连接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭连接" << endl;

}

void f(destination &d)
{
	cout << "直接管理connect" << endl;
	connection c = connect(&d);
	
	cout << endl;
}

void end_connection(connection* p) { disconnect(*p); }


void f1(destination &d)
{
	cout << "使用智能指针管理connect" << endl;
	connection c = connect(&d);
	int a = 5;
	//这里的理解：
	//
	shared_ptr<connection> p(&c,[&](connection* p) { disconnect(c); cout << a << endl; });
	//shared_ptr<connection> p(&c,end_connection);
	cout << endl;
}
int main()
{
	destination d;
	f(d);
	f1(d);


	



	return 0;
}
