//#include <iostream>
//#include <memory>
//
//using namespace std;
//
//void process(shared_ptr<int> ptr)
//{
//    cout << ptr.use_count() <<endl;
//}
//
//
//
//int main()
//{
//	//shared_ptr<int> p(new int(42));
//	//process(p);
//	//cout << p.use_count() << endl;
//
//	//int *x(new int(1024)); //��ָͨ�벻��ת��Ϊ����ָ��
//
//	////process(x);
//
//
//	//process(shared_ptr<int>(x));  //����֮���ڴ汻�ͷ�
//	//int j = *x;
//	//cout << x << endl;
//
//
//		shared_ptr<int> p(new int(42));
//		cout << p.use_count() << endl;
//		int *ad = p.get(); //
//		{
//			cout << ad << endl;
//			//����������shared_ptrָ����ͬ���ڴ�
//			shared_ptr<int>(ad);
//			cout << p.use_count() << endl;
//			//cout << shared_ptr<int>(q).use_count() << endl;
//		}
//		int foo = *p;
//		auto new_ptr = p;
//		cout << new_ptr << " " << p << endl;
//		cout << p.use_count() << endl;
//		cout << *p << endl;
//		cout << foo << endl;
//		
//		
//		*new_ptr = 60;
//		cout << *p << endl;
//
//		int *app = new int(70);
//		int *opp = app;
//		cout << *app << app <<endl;
//		cout << *opp << opp << endl;
//		delete app;
//		cout << *opp << endl;
//
//
//	
//
//
//
//	return 0;
//}



#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout; using std::endl;
void process(shared_ptr<int> p )
{
	cout << p.use_count() << endl;
}

////////////////////////////////////////////
/*
int main()
{
	shared_ptr<int> p(new int(42));
	cout << p << " " << p.use_count() << endl;
	int *q = p.get();
	{    
		
		cout << "q�ĵ�ַ" << q << endl;
		shared_ptr<int>(q);
		//delete q;
 	}
	//process(shared_ptr<int>(q));
	cout << p.use_count() << endl;

	return 0;
}

*/


////////////////////////////////////////////////////
using std::make_shared;

int main()
{
	auto  p = new int();
	auto sp = make_shared<int>();
	process(sp);
	process(make_shared<int>());
	//process(p);
	//process(shared_ptr<int>(p));
	cout << *p << endl; //Ұָ��

	auto op = make_shared<int>();
	auto o = op.get();
	delete o;
	//cout << *op << endl;

	{
		int app = 10;
	}


	return 0;

}


