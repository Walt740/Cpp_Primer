#include "Folder.h"
#include "Message.h"
#include <iostream>

using std::cout;
using std::endl;

//析构函数 将本Folder从对应的Message中移除
Folder::~Folder()
{
    remove_from_msg();
}

 Folder::Folder(Folder &&f)
 {
     move_Messages(&f);
 }

Folder &Folder::operator=(Folder &&f)
{
    if(this != &f)
    {
        remove_from_msg();
        move_Messages(&f);
    }
    std::cout << "移动赋值运算符" << std::endl;
    return *this;

}

void Folder::move_Messages(Folder *f)
{
    auto msgs = std::move(f->messages);
    for(auto m : msgs)
    {
        m->remFolder(f);
        m->addFolder(this);
    }
    f->messages.clear();
}

//添加一个msg* 到messages集合中
void Folder::save(Message &msg)
{
    messages.insert(&msg);
    msg.addFolder(this);
}

void Folder::remove(Message &msg)
{
    messages.erase(&msg);
    msg.remFolder(this);
}

//将本Folder对象添加到指向f的Message中
void Folder::add_to_msg(Folder &f)
{
    for(auto be: f.messages) //对每个包含f的Message
        be->addFolder(&f);   //向该Message添加一个指向本Folder的指针
}

void Folder::remove_from_msg()
{
    for(auto be : messages)
        be->remFolder(this);
}
//添加一个msg*指针到Folder的messages中
void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}
//将Folder对象对应的msg*移除出messages集合
void Folder::remMsg(Message *msg)
{
    messages.erase(msg);
}

void Folder::print_debug()
{
	for (auto m : messages)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}

Folder& Folder::operator=(const Folder &f)
{
    remove_from_msg();
    messages = f.messages;
    add_to_msg(*this);
    return *this;
}

void swap(Folder &lf,Folder &rf)
{
    lf.remove_from_msg();
    rf.remove_from_msg();
    swap(lf.messages,rf.messages);
    lf.add_to_msg(lf);
    rf.add_to_msg(rf);
}
