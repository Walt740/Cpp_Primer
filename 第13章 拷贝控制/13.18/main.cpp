#include <iostream>

using namespace std;

class Employee
{
private:
    static int sn;
public:
    Employee() { mysn = sn++;
        cout << "Ĭ�Ϲ��캯��" <<endl;
    }
    Employee(const string &s){ name = s; mysn = sn++; cout << "���캯��" <<endl; }
    Employee(Employee &rhs)
    {
        cout << "�������캯��" <<endl;
        name = rhs.name;
        mysn = sn++;
    }
    Employee& operator= (const Employee &rhs)
    {
        cout << "���������" <<endl;
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
    Employee a("��");
    Employee b = a, c;
    c = b;
    f(a),f(b),f(c);
    return 0;
}

