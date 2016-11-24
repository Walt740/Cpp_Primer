#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

using namespace std;

class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);
	friend void swap(Folder &, Folder &);

public:
    //explicit���ƹ��캯���������ʽת��
    explicit Message(const string &str = ""):contents(str) {}
    Message(const Message &msg);
    Message(Message &&msg)  ;
    Message &operator= (const Message &str);
    Message &operator= (Message &&str);
    ~Message();
    void save(Folder &);  //�����������Folder����ͬʱ��Folder����ӱ��ࣨ����addMsg��
    void remove(Folder &); //���������Ƴ�Folder����ͬʱ��Folder���Ƴ����ࣨ����remMsg��
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(Message &); //��Folder�������Message,��Ŀ�ĵ�����ΪPrivate
    void remove_from_Folders(); //�Ƴ�Folder���Message
    void addFolder(Folder *f);
    void remFolder(Folder *f);  //Ŀ�ģ��Ƴ���������Folder��
    void move_Folders(Message *m);
};

#endif // MESSAGE_H
