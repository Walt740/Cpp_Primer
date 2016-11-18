#include "Message.h"
#include "Folder.h"

//析构函数
Message::~Message()
{
    remove_from_Folders();//dtor
}
//将message对象所对应的Folder*（文件夹指针）添加到成员：folders集合中
void Message::addFolder(Folder *f)
{
    folders.insert(f);
}
//将message对象对应的Folder*移除出folders集合
void Message::remFolder(Folder *f)
{
    folders.erase(f);
}
//添加一个Folder* 到folders集合中
void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}
//将一个Folder* 从folders集合中移除
void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}
//将本message对象添加到指向msg的Folder中
void Message::add_to_Folders(Message &msg)
{
    for(auto be : msg.folders) //对每个包含msg的Folder
        be->addMsg(&msg); //向该Folder添加一个指向本Message的指针
}
//从对应的Folder中移除本Message
void Message::remove_from_Folders()
{
    for(auto be: folders)
        be->remMsg(this);
}
//拷贝构造函数
Message::Message(const Message &msg):contents(msg.contents),folders(msg.folders)
{
    add_to_Folders(*this);
}

//拷贝赋值运算符
Message& Message::operator=(const Message &msg)
{
    remove_from_Folders(); //从对应的Folder中移除本Message
    folders = msg.folders;
    contents = msg.contents;
    add_to_Folders(*this);
    return *this;
}


void swap(Message &lmsg,Message &rmsg)
{

    lmsg.remove_from_Folders();//从对应的Folder中移除本Message
    rmsg.remove_from_Folders();//从对应的Folder中移除本Message
    swap(lmsg.contents,rmsg.contents);
    swap(lmsg.folders,rmsg.folders);
    lmsg.add_to_Folders(lmsg);
    rmsg.add_to_Folders(rmsg);
}

