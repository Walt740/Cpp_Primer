#ifndef _SCREEN_H
#define _SCREEN_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Window_mgr;


void Window_mgr::clear(ScreenIndex i)
{
    //s是一个Screen的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    //将那个选定的Screen重置为空白
    s.contents = string(s.height * s.width, ' ');
}

class Screen
{
public:
    //Window_mgr的成员可以访问Screen类的私有部分
    //friend class Window_mgr;
    friend void Window_mgr::clear(ScreenIndex i);
public :
    //自定义类型在类中的别名
    typedef string::size_type pos;
    //using pos = string::size_type;
    Screen() = default; // 因为Screen有另一个构造函数。
                        //所以本函数是必需的
    Screen(pos ht,pos wd,char c) : height(ht),width(wd),
            contents(ht * wd ,c){}
    Screen(pos ht,pos wd):height(ht),width(wd),
            contents(ht * wd ,' '){}
    char get() const
    {
        return contents[cursor];
    }
//    inline char set(pos ht,pos wd) const; //显式内联
//    Screen &move(pos r,pos c);            //能在之后被设为内联

public :
    Screen& move(unsigned r, unsigned c)
    {
        cursor = r * width + c;
        return *this;
    }

    Screen&set(char ch)
    {
        contents[cursor] = ch ;
        return *this;
    }
    Screen& set(unsigned r, unsigned c , char ch)
    {
        contents[r *width + c] = ch ;
        return *this;
    }
    Screen& display(ostream& cout)
    {
        cout << contents;
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0,width = 0;
    string contents;

};

class Window_mgr
{
public :
    //窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    //按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);
private:
    std:: vector<Screen> screens{Screen(24,80,' ')};
};



#endif // _SCREEN_H
