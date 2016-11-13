#ifndef _SCREEN_H
#define _SCREEN_H

#include <iostream>
using namespace std;

class Screen
{
public :
    //�Զ������������еı���
    typedef string::size_type pos;
    //using pos = string::size_type;
    Screen() = default; // ��ΪScreen����һ�����캯����
                        //���Ա������Ǳ����
    Screen(pos ht,pos wd,char c) : height(ht),width(wd),
            contents(ht * wd ,c){}
    Screen(pos ht,pos wd):height(ht),width(wd),
            contents(ht * wd ,' '){}
    char get() const
    {
        return contents[cursor];
    }
//    inline char set(pos ht,pos wd) const; //��ʽ����
//    Screen &move(pos r,pos c);            //����֮����Ϊ����


public :
    Screen move(unsigned r, unsigned c)
    {
        cursor = r * width + c;
        return *this;
    }

    Screen set(char ch)
    {
        contents[cursor] = ch ;
        return *this;
    }
    Screen set(unsigned r, unsigned c , char ch)
    {
        contents[r *width + c] = ch ;
        return *this;
    }
    Screen display(ostream& cout)
    {
        cout << contents;
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0,width = 0;
    string contents;

};




#endif // _SCREEN_H
