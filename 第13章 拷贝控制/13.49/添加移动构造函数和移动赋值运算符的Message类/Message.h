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
    //explicit抑制构造函数定义的隐式转换
    explicit Message(const string &str = ""):contents(str) {}
    Message(const Message &msg);
    Message(Message &&msg)  ;
    Message &operator= (const Message &str);
    Message &operator= (Message &&str);
    ~Message();
    void save(Folder &);  //本类用以添加Folder对象，同时在Folder中添加本类（调用addMsg）
    void remove(Folder &); //本类用以移除Folder对象，同时在Folder中移除本类（调用remMsg）
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(Message &); //向Folder类中添加Message,有目的的申明为Private
    void remove_from_Folders(); //移除Folder类的Message
    void addFolder(Folder *f);
    void remFolder(Folder *f);  //目的：移除本类对象的Folder。
    void move_Folders(Message *m);
};

#endif // MESSAGE_H
