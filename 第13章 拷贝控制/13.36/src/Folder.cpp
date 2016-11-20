#include "Folder.h"
#include "Message.h"
#include <iostream>

using std::cout;
using std::endl;

//�������� ����Folder�Ӷ�Ӧ��Message���Ƴ�
Folder::~Folder()
{
    remove_from_msg();
}

//���һ��msg* ��messages������
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

//����Folder������ӵ�ָ��f��Message��
void Folder::add_to_msg(Folder &f)
{
    for(auto be: f.messages) //��ÿ������f��Message
        be->addFolder(&f);   //���Message���һ��ָ��Folder��ָ��
}

void Folder::remove_from_msg()
{
    for(auto be : messages)
        be->remFolder(this);
}
//���һ��msg*ָ�뵽Folder��messages��
void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}
//��Folder�����Ӧ��msg*�Ƴ���messages����
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
