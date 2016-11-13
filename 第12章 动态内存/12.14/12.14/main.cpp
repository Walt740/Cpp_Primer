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
	cout << "sp�ĵ�ַ�ǣ�" << sp << endl;
	return sp.get();
}



struct destination {};  
struct connection {};

connection connect(destination *pd)
{
	cout << "������" << endl;
	return connection(); //����һ�����ʼ������
}


void disconnect(connection c)
{
	cout << "�ر�����" << endl;  
}

void f(destination &d)
{
	cout << "ֱ�ӹ���connect" << endl;
	connection c = connect(&d);
	//���ǵ���disconnect �ر�����
	cout << endl;
}



void end_connection(connection *p)
{
	disconnect(*p);
}


void 
f1(destination &d)
{
	cout << "��shared_ptr����connect" << endl;
	connection c = connect(&d);

	shared_ptr<connection> p(&c,end_connection);
	//���ǵ���disconnect�ر�����
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


