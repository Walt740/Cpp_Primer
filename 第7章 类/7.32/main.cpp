#include <iostream>
//#include "Screen.h"
using namespace std;


/*
void f();

struct X{
    friend void f(){}
    X() {f();}
    void g();
    void h();
};


void X::g(){ return f();}
void X::h(){ return f();}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

*/
class Window_mgr
{
public :
    void clear();
};

class Screen
{
  friend void Window_mgr::clear();
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0 ;
    string contents ;
public:
    Screen() = default;
    Screen(unsigned ht,unsigned wd,char c)
            : height(ht),width(wd),contents(ht * wd, c){}

};
void Window_mgr::clear()
{
    Screen myscreen(10,20,'X');
    cout << "清理之前的myScreen的内容是："<<endl ;
    cout << myscreen.contents << endl ;
    myscreen.contents = " ";
    cout << "清理之后的myscreen的内容是:" <<endl;
    cout << myscreen.contents <<endl ;
}









int main()
{
    Window_mgr w;
    w.clear();

    return 0;
}


