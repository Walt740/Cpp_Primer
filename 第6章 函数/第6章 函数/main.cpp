#include <iostream>
#include <vector>
using namespace std;


//int fact( int val)
//{
//    int ret  = 1;
//    while(val > 1)
//    {
//        ret *= val--;
//    }
//    return ret;
//}
//�ݹ�
//int fact(int val)
//{
//    int ret = 1;
//    if(val == 0 || val == 1)
//        ret = 1;
//    else
//         ret  = val * fact(val- 1);
//
//    return ret;
//}


//int fact(int n){

//    int result;
//    if(n==0 || n==1){
//        result = 1;
//    }else{
//        result = fact(n-1) * n;  // �ݹ����
//    }
//    return result;
//}


//int main()
//{
//
//    int num ;
//    cout << "������һ������" << endl;
//    cin >> num;
//    int j = fact(num);
//    cout <<"����ǣ�"<< j << endl;
//    return 0;
//}


//unsigned myabs(int num)
//{
//    if(num < 0)
//        return -num;
//    else
//        return num;
//}
//
//int main()
//{
//    int num ;
//    cout << "������һ������" << endl;
//    cin >> num;
//    cout << abs(num) <<endl ;
//    return 0;
//
//}



//int main()
//{
//    int i = 10;
//    const int a = i ;
//    int b = a ;
//    cout << a << endl;
//
//    int *z ;
//    const  int *j = z; //��ȷ �ǳ�����ʼ�� �ײ�const
////    int *k = j; //�ײ�const��ʼ�� �ǳ��� ����
//  //  int const *x =
//    int * const ok = z;
//    int * no  = ok ;
//    return 0;
//}


//int main(int argc,char *argv[])
//{
//    string str;
//    for(int i = 0;i!= argc;++i)
//        str += argv[i];
//    cout << str <<endl;
//    return 0;
//}


//bool str_subrange(const string &str1,const string &str2)
//{
//    if(str1.size() == str2.size())
//        return str1 == str2;
//    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
//    for(decltype(size) i = 0;i != size; ++i)
//    {
//        if(str1[i] != str2[i] )
//            return true;
//    }
//    return 8 ;
//}
//
//
//
//int main(int argc,char **argv)
//{
//
//
//        cout << "return " << str_subrange("yinhao","yinhao.zheng") <<endl ;
//    while(int i < 5)
//    {
//        i--;
//    }
//
//    do
//    {
//        y--;
//    }while(int y<5);
////    for(int i = 0; i!=argc;++i)
////    {
////        cout << "argc[" << i << "]:" << argv[i] << endl;
////    }
//    return 0;
//}

//double myADD(double val1,double val2)
//{
//    double result = val1 + val2;
//    static unsigned iCnt = 0;
//    ++iCnt;
//    cout << "�ú����Ѿ�ִ���� "<< iCnt << "��" << endl;
//    return result ;
//}
//
//int main ()
//{
//
//    double num1 ,num2;
//    cout << "������������ " ;
//    while(cin >> num1 >> num2)
//    {
//        cout << num1 << "��" << num2 << "����ͽ���� ��"
//        << myADD(num1,num2) << endl;
//    }
//    return 0;
//}


//void mySWAP(int *p,int *q)
//{
//    int tmp = *p;
//    *p = *q;
//    *q = tmp;
//}
//
//int main()
//{
//    int a = 5,b = 10;
//    int *r = &a,*s = &b;
//    cout << "����ǰ��a = " << a << ",b=" << b << endl;
//    mySWAP(r,s);
//    cout << "������a = " << a << ",b=" << b << endl ;
//    return 0;
//}


//void reset(int &i)
//{
//    i = 0;
//}
//int main()
//{
//    int num = 10;
//    cout << "����ǰ��num = " << num <<endl ;
//    reset(num);
//    cout << "���ú�num = " << num <<endl ;
//}
//void mySWAP(int &p,int &q)
//{
//    int tmp = p;
//    p = q;
//    q = tmp;
//}
//
//int main()
//{
//    int a = 5,b = 10;
//    //int *r = &a,*s = &b;
//    cout << "����ǰ��a = " << a << ",b=" << b << endl;
//    mySWAP(a,b);
//    cout << "������a = " << a << ",b=" << b << endl ;
//    return 0;
//}
//

//int  myabs(int &a)
//{
//    if(a < 0)
//        a = -a;
//    return a;
//}
//
//int main()
//{
//    int num = -10;
//    cout << myabs(num) << endl ;
//    return 0;
//}


//#include <string>
//
//bool HasUpper(const string & str)
//{
//    for(auto c: str)
//        if(isupper(c))
//            return true;
//    return false;
//}
//
//void ChangeToLower(string& str)
//{
//    for(auto &c : str)
//        c = tolower(c);
//}
//
//int main()
//{
//    cout << "������һ���ַ�����"<<endl;
//    string str;
//    cin >> str;
//    if(HasUpper(str))
//    {
//        ChangeToLower(str);
//        cout << "ת������ַ�����:" << str << endl ;
//    }
//    else
//        cout << "���ַ���������д�ַ�������ת��" <<endl;
//    return 0;
//}
//
//


//void print1(const int *p)
//{
//    cout << *p << endl;
//}
//
//void print2(const int *p,const int sz)
//{
//    int i= 0;
//    while(i != sz)
//    {
//        cout << *p++ << endl;
//        ++i;
//    }
//}
//
//void print3(const int *b,const int *e)
//{
//    for(auto q = b; q!= e; ++q)
//    {
//        cout << *q <<endl;
//    }
//}
//
//int main()
//{
//    int i = 0, j[2] = {0,1};
////    print1(&i);
////    print1(j);
////    print2(&i,1);
////    print2(j,sizeof(j)/sizeof(*j));
//    auto b = begin(j);
//    auto e = end(j);
//    print3(b,e);
//    return 0;
//}




//int iCount(initializer_list<int> il)
//{
//    int count = 0;
//    //����il��ÿһ��Ԫ��
//    for(auto val : il)
//        count += val;
//    return count ;
//}
//
//int main()
//{
//    //ʹ���б��ʼ���ķ�ʽ����initalizer_list<int>����
//    //Ȼ�������Ϊʵ�δ��ݸ�����iCount
//    cout << "1,6,9�ĺ��ǣ�" << iCount({1,6,9}) <<endl;
//    cout << "4,5,9,18�ĺ��ǣ�" << iCount({4,5,9,18}) <<endl;
//    return 0;
//}


//void foo(int a,...)
//{
//
//   cout << a <<endl ;
//}
//
//int main()
//{
//
// foo();
//}

//#include <vector>
//#define NDEBUG
//void print(vector<int> vInt,unsigned index)
//{
//    unsigned sz = vInt.size();
//	#ifndef NDEBUG
//	cout << "vector����Ĵ�С�ǣ�" << sz << endl;
//	#endif
//
//    if(!vInt.empty() && index <sz)
//    {
//        cout <<vInt[index] <<endl;
//        print(vInt,index+1);
//    }
//}
//
//int main()
//{
//    vector<int>v = {1,2,3,4,5,6,7};
//    print(v,0);
//    return 0;
//}


//int factorial(int val)
//{
//    if(val > 1)
//    {
//        if(val > 1)
//            return factorial(val-1) * val;
//    }
//}
//
//int main()
//{
//    cout <<factorial(7) <<endl;
//}


//#include "inline.h"
//constexpr int new_sz(int a)
//{
//    return 42;
//}
//constexpr size_t scale(size_t cnt)
//{
//    return new_sz(cnt) * cnt;
//}
//
//int main()
//{
////    int i;
////    cin >> i;
////    scale(i);
////    cout <<i << endl ;
//    int b = 2;
//    int a[scale(2)];
//    return 0;
//}


//void f()
//{
//	cout << "�ú����������" << endl;
//}
//
//void f(int)
//{
//	cout << "�ú�����һ����������" << endl;
//}
//
//void f(int, int)
//{
//	cout << "�ú������������Ͳ���" << endl;
//}
//void f(double a, double b = 3.14)
//{
//	cout << "�ú���������˫���ȸ����Ͳ���" << endl;
//}
//
//int main()
//{
//	f(2.56,42);
//	f(42);
//	f(42,0);
//	f(42,3.14);
//	f(2.56, 3.14);
//	f("yinhao");
//	return 0;
//}
//
//
//int calc(char*,char *);
//int calc(char* const ,char* const);



//bool lengthCompare(const string &, const string &)
//{
//	cout << "���Ժ���ָ��" << endl;
//	return 1;
//}
//
//
//bool (&pf)(const string& ,const string &);
//
//
//
//
//int main()
//{
//
//	pf = lengthCompare;
//	//pf = &lengthCompare;
//	//(pf)("yinhao","zheng");
//	//pf("ok","no");
//
//	return 0;
//}
//
////
////void ff(int *);
////void ff(unsigned int);
////void(*pf)(int *) = ff;
////void (*pf2) 


//auto f(int) -> int(*) (int *,int *);
//int (*f(int))(int *, int *);
//
//int(*f(int))(int *, int *)
//{
//	return nullptr;
//}






//int ccc(int a,int b)
//{
//	cout << a + b << endl;
//	return 0;
//}
//
//
////vector<int(*)(int, int) > vF;
//vector<decltype(ccc) *>vF;
//
//int main()
//{
//	int(*pF)(int, int);
//	pF = ccc;
//	pF(4,8);
//	vF.push_back(ccc);
//	vF[0](4,8);
//
//	
//	return 0;
//}



int fun1(int a, int b)
{
	return a + b;
}

int fun2(int a, int b)
{
	return a - b;
}

int fun3(int a, int b)
{
	return a * b;
}

int fun4(int a, int b)
{
	return a / b;
}

void Compute(int a,int b,int (*p)(int ,int))
{
	cout << p(a,b) << endl;
}

int main()
{
	int i = 5, j = 10;
	decltype(fun1) *p1 = fun1, *p2 = fun2, *p3 = fun3, *p4 = fun4;
	vector<decltype(fun1)*> vF = {p1,p2,p3,p4};
	for (auto p : vF)
		//cout << p(i, j) << endl;
		Compute(i,j,p);
	
	return 0;
}