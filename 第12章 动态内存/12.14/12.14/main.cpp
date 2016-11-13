#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;


int* f()
{
	shared_ptr<int> sp(new int(42));
	cout << sp.use_count() << endl;
	cout << "sp的地址是：" << sp << endl;
	return sp.get();
}



struct destination {};  
struct connection {};

connection connect(destination *pd)
{
	cout << "打开连接" << endl;
	return connection(); //返回一个类初始化对象
}


void disconnect(connection c)
{
	cout << "关闭连接" << endl;  
}

void f(destination &d)
{
	cout << "直接管理connect" << endl;
	connection c = connect(&d);
	//忘记调用disconnect 关闭连接
	cout << endl;
}



void end_connection(connection *p)
{
	disconnect(*p);
}


void 
f1(destination &d)
{
	cout << "用shared_ptr管理connect" << endl;
	connection c = connect(&d);

	shared_ptr<connection> p(&c,end_connection);
	//忘记调用disconnect关闭连接
	cout << endl;
}




int main()
{

	//cout << f() <<  *f()<< endl;
	destination d;
	f(d);
	f1(d);


	return 0;
}


