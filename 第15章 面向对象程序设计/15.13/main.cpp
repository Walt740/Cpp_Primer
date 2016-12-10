#include <iostream>

using namespace std;

class base
{
public:
    base() = default;
    base(string name) : basename(name) {}
    string name(){return basename;}
    virtual void print(ostream &os){ os << basename;}
private:
    string basename;
};

class derived:public base
{
public:
    derived()= default;
    derived(int a) : i(a){}
    void print(ostream &os) override
    {
        base::print(os);os << " " << i;
    }
private:
    int i;
};



int main()
{
    base b("yinhao");
    derived d(10);
    cout << b.name() << endl;
    b.print( cout );
    d.print(cout);
    return 0;
}
