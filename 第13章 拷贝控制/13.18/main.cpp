#include <iostream>

using namespace std;

class Employee
{
private:
    static int sn;
public:
    Employee() { mysn = sn++;
        cout << "默认构造函数" <<endl;
    }
    Employee(const string &s){ name = s; mysn = sn++; cout << "构造函数" <<endl; }
    Employee(Employee &rhs)
    {
        cout << "拷贝构造函数" <<endl;
        name = rhs.name;
        mysn = sn++;
    }
    Employee& operator= (const Employee &rhs)
    {
        cout << "拷贝运算符" <<endl;
        name = r
        hs.name;
        mysn = rhs.sn++;
        return *this;
    }
    const string &get_name() {return name;}
    int get_mysn() {return mysn;}
private:
    string name;
    int mysn;
};

int Employee::sn = 0;

void f(Employee &s)
{
    cout << s.get_name() << ":" << s.get_mysn() <<endl;
}

int main()
{
    Employee a("赵");
    Employee b = a, c;
    c = b;
    f(a),f(b),f(c);
    return 0;
}

