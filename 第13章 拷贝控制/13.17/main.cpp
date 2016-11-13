#include <iostream>

using namespace std;

class numbered
{
private:
    static int seq; // 静态成员在类外初始化

public:
    numbered():msysn(0){ seq++; cout << "默认构造函数"<<endl; }
    numbered(numbered &n)
    {
        cout << "拷贝构造函数" << endl;
        msysn = seq++;
    }
	numbered& operator= (const numbered &rhs)
	{
		msysn = seq++;
		return *this;
	}
    int msysn ;
};


int numbered::seq = 0;


void f(numbered s)
{
    cout << s.msysn <<endl;
}
void f1(numbered &s)
{
    cout << s.msysn <<endl;
}

int main()
{
    numbered a, b = a,c = b;
   //f(a);f(b);f(c);

   // cout << a.msysn << endl;
   // f1(a);
   // f1(b);
   // f1(c);

	numbered d;
	d = a; 
	cout << d.msysn << endl;
	d = b;
	cout << d.msysn << endl;

    return 0;
}
