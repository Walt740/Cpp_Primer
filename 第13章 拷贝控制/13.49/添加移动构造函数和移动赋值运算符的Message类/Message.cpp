#include "Message.h"
#include "Folder.h"
#include <iostream>
//��������
Message::~Message()
{
    remove_from_Folders();//dtor
}
//��message��������Ӧ��Folder*���ļ���ָ�룩��ӵ���Ա��folders������
void Message::addFolder(Folder *f)
{
    folders.insert(f);
}
//��message�����Ӧ��Folder*�Ƴ���folders����
void Message::remFolder(Folder *f)
{
    folders.erase(f);
}
//���һ��Folder* ��folders������
void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}
//��һ��Folder* ��folders�������Ƴ�
void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}
//����message������ӵ�ָ��msg��Folder��
void Message::add_to_Folders(Message &msg)
{
    for(auto be : msg.folders) //��ÿ������msg��Folder
        be->addMsg(&msg); //���Folder���һ��ָ��Message��ָ��
}
//�Ӷ�Ӧ��Folder���Ƴ���Message
void Message::remove_from_Folders()
{
    for(auto be: folders)
        be->remMsg(this);
}
//�������캯��
Message::Message(const Message &msg):contents(msg.contents),folders(msg.folders)
{
    add_to_Folders(*this);
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for(auto f: folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}


Message::Message(Message &&msg):contents(std::move(msg.contents))
{
    move_Folders(&msg);
}


//������ֵ�����
Message& Message::operator=(const Message &msg)
{
    remove_from_Folders(); //�Ӷ�Ӧ��Folder���Ƴ���Message
    folders = msg.folders;
    contents = msg.contents;
    add_to_Folders(*this);
    return *this;
}

Message& Message::operator=(Message &&msg)
{
    if(this != &msg)
    {
        remove_from_Folders();
        contents = std::move(msg.contents);
        move_Folders(&msg);
    }
    std::cout << "�ƶ���ֵ�����" <<std::endl;
    return *this;
}


void swap(Message &lmsg,Message &rmsg)
{

    lmsg.remove_from_Folders();//�Ӷ�Ӧ��Folder���Ƴ���Message
    rmsg.remove_from_Folders();//�Ӷ�Ӧ��Folder���Ƴ���Message
    swap(lmsg.contents,rmsg.contents);
    swap(lmsg.folders,rmsg.folders);
    lmsg.add_to_Folders(lmsg);
    rmsg.add_to_Folders(rmsg);
}

