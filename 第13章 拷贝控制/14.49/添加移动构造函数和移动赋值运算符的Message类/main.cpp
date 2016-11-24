#include <iostream>
#include <set>
#include "Folder.h"
#include "Message.h"



int main()
{
    Message m1("xingxiuyan"),m2("lindaiyu"),m3("xuebaochai");
    Folder f1, f2, f3, f4, f5;
    m1.save(f1); //消息1保存在文件夹1中
    m1.save(f2); //消息1保存在文件夹2中

    m2.save(f1);
    m2.save(f2);
    f1.print_debug();
    f2.print_debug();


    swap(m1,m2);
    f1.print_debug();
    f2.print_debug();

    f2.remove(m2);
    f2.print_debug();
    return 0;
}


