//#include <iostream>
//
//using namespace std;
//
//
////int fact( int val)
////{
////    int ret  = 1;
////    while(val > 1)
////    {
////        ret *= val--;
////    }
////    return ret;
////}
////递归
////int fact(int val)
////{
////    int ret = 1;
////    if(val == 0 || val == 1)
////        ret = 1;
////    else
////         ret  = val * fact(val- 1);
////
////    return ret;
////}
//
//
////int fact(int n){
//
////    int result;
////    if(n==0 || n==1){
////        result = 1;
////    }else{
////        result = fact(n-1) * n;  // 递归调用
////    }
////    return result;
////}
//
//
////int main()
////{
////
////    int num ;
////    cout << "请输入一个整数" << endl;
////    cin >> num;
////    int j = fact(num);
////    cout <<"结果是："<< j << endl;
////    return 0;
////}
//
//
////unsigned myabs(int num)
////{
////    if(num < 0)
////        return -num;
////    else
////        return num;
////}
////
////int main()
////{
////    int num ;
////    cout << "请输入一个整数" << endl;
////    cin >> num;
////    cout << abs(num) <<endl ;
////    return 0;
////
////}
//
//
//
////int main()
////{
////    int i = 10;
////    const int a = i ;
////    int b = a ;
////    cout << a << endl;
////
////    int *z ;
////    const  int *j = z; //正确 非常量初始化 底层const
//////    int *k = j; //底层const初始化 非常量 错误
////  //  int const *x =
////    int * const ok = z;
////    int * no  = ok ;
////    return 0;
////}
//
//
////int main(int argc,char *argv[])
////{
////    string str;
////    for(int i = 0;i!= argc;++i)
////        str += argv[i];
////    cout << str <<endl;
////    return 0;
////}
//
//
////bool str_subrange(const string &str1,const string &str2)
////{
////    if(str1.size() == str2.size())
////        return str1 == str2;
////    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
////    for(decltype(size) i = 0;i != size; ++i)
////    {
////        if(str1[i] != str2[i] )
////            return true;
////    }
////    return 8 ;
////}
////
////
////
////int main(int argc,char **argv)
////{
////
////
////        cout << "return " << str_subrange("yinhao","yinhao.zheng") <<endl ;
////    while(int i < 5)
////    {
////        i--;
////    }
////
////    do
////    {
////        y--;
////    }while(int y<5);
//////    for(int i = 0; i!=argc;++i)
//////    {
//////        cout << "argc[" << i << "]:" << argv[i] << endl;
//////    }
////    return 0;
////}
//
////double myADD(double val1,double val2)
////{
////    double result = val1 + val2;
////    static unsigned iCnt = 0;
////    ++iCnt;
////    cout << "该函数已经执行了 "<< iCnt << "次" << endl;
////    return result ;
////}
////
////int main ()
////{
////
////    double num1 ,num2;
////    cout << "请输入两个数 " ;
////    while(cin >> num1 >> num2)
////    {
////        cout << num1 << "与" << num2 << "的求和结果是 ："
////        << myADD(num1,num2) << endl;
////    }
////    return 0;
////}
//
//
////void mySWAP(int *p,int *q)
////{
////    int tmp = *p;
////    *p = *q;
////    *q = tmp;
////}
////
////int main()
////{
////    int a = 5,b = 10;
////    int *r = &a,*s = &b;
////    cout << "交换前：a = " << a << ",b=" << b << endl;
////    mySWAP(r,s);
////    cout << "交换后：a = " << a << ",b=" << b << endl ;
////    return 0;
////}
//
//
////void reset(int &i)
////{
////    i = 0;
////}
////int main()
////{
////    int num = 10;
////    cout << "重置前：num = " << num <<endl ;
////    reset(num);
////    cout << "重置后：num = " << num <<endl ;
////}
////void mySWAP(int &p,int &q)
////{
////    int tmp = p;
////    p = q;
////    q = tmp;
////}
////
////int main()
////{
////    int a = 5,b = 10;
////    //int *r = &a,*s = &b;
////    cout << "交换前：a = " << a << ",b=" << b << endl;
////    mySWAP(a,b);
////    cout << "交换后：a = " << a << ",b=" << b << endl ;
////    return 0;
////}
////
//
////int  myabs(int &a)
////{
////    if(a < 0)
////        a = -a;
////    return a;
////}
////
////int main()
////{
////    int num = -10;
////    cout << myabs(num) << endl ;
////    return 0;
////}
//
//
////#include <string>
////
////bool HasUpper(const string & str)
////{
////    for(auto c: str)
////        if(isupper(c))
////            return true;
////    return false;
////}
////
////void ChangeToLower(string& str)
////{
////    for(auto &c : str)
////        c = tolower(c);
////}
////
////int main()
////{
////    cout << "请输入一个字符串："<<endl;
////    string str;
////    cin >> str;
////    if(HasUpper(str))
////    {
////        ChangeToLower(str);
////        cout << "转换后的字符串是:" << str << endl ;
////    }
////    else
////        cout << "该字符串不含大写字符，无须转换" <<endl;
////    return 0;
////}
////
////
//
//
////void print1(const int *p)
////{
////    cout << *p << endl;
////}
////
////void print2(const int *p,const int sz)
////{
////    int i= 0;
////    while(i != sz)
////    {
////        cout << *p++ << endl;
////        ++i;
////    }
////}
////
////void print3(const int *b,const int *e)
////{
////    for(auto q = b; q!= e; ++q)
////    {
////        cout << *q <<endl;
////    }
////}
////
////int main()
////{
////    int i = 0, j[2] = {0,1};
//////    print1(&i);
//////    print1(j);
//////    print2(&i,1);
//////    print2(j,sizeof(j)/sizeof(*j));
////    auto b = begin(j);
////    auto e = end(j);
////    print3(b,e);
////    return 0;
////}
//
//
//
//
////int iCount(initializer_list<int> il)
////{
////    int count = 0;
////    //遍历il的每一个元素
////    for(auto val : il)
////        count += val;
////    return count ;
////}
////
////int main()
////{
////    //使用列表初始化的方式构建initalizer_list<int>对象
////    //然后把它作为实参传递给函数iCount
////    cout << "1,6,9的和是：" << iCount({1,6,9}) <<endl;
////    cout << "4,5,9,18的和是：" << iCount({4,5,9,18}) <<endl;
////    return 0;
////}
//
//
////void foo(int a,...)
////{
////
////   cout << a <<endl ;
////}
////
////int main()
////{
////
//// foo();
////}
//
////#include <vector>
////void print(vector<int> vInt,unsigned index)
////{
////    unsigned sz = vInt.size();
////    if(!vInt.empty() && index <sz)
////    {
////        cout <<vInt[index] <<endl;
////        print(vInt,index+1);
////    }
////}
////
////int main()
////{
////    vector<int>v = {1,2,3,4,5,6,7};
////    print(v,0);
////    return 0;
////}
//
//
////int factorial(int val)
////{
////    if(val > 1)
////    {
////        if(val > 1)
////            return factorial(val-1) * val;
////    }
////}
////
////int main()
////{
////    cout <<factorial(7) <<endl;
////}
//
//
//
////constexpr int new_sz()
////{
////    return 42;
////}
////constexpr size_t scale(size_t cnt)
////{
////    return new_sz() * cnt;
////}
////
////int main()
////{
//////    int i;
//////    cin >> i;
//////    scale(i);
//////    cout <<i << endl ;
////    int b = 2;
////    int a[scale(b)];
////    return 0;
////}
//
//
//
//

#include <iostream>
using namespace std;
//void f()
//{
//	cout << "该函数无须参数" << endl;
//}
//
//void f(int)
//{
//	cout << "该函数有一个整数参数" << endl;
//}
//
//void f(int, int)
//{
//	cout << "该函数有两个整型参数" << endl;
//}
//void f(double a, double b = 3.14)
//{
//	cout << "该函数有两个双精度浮点型参数" << endl;
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

#include <vector>
int ccc(int a,int b)
{
	cout << a + b << endl;
}
int(*pF)(int, int);
//vector<int(*pF)(int, int) > vF;
//vector<decltype(ccc)>vF;

int main()
{

	pF = ccc;
	pF(4,8);
	return 0;
}
