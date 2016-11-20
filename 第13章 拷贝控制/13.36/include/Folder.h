#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <set>

using namespace std;

class Message;
class Folder
{
    friend class Message;
    friend void swap(Message &, Message &);
	friend void swap(Folder &, Folder &);
public:
    Folder() = default;
    Folder(const Folder &f);
    Folder &operator= (const Folder &f);
    ~Folder();
    void save(Message &msg);
    void remove(Message &msg);
    void print_debug();
private:
    set<Message*> messages;
    void add_to_msg(Folder &f);
    void remove_from_msg();
    void addMsg(Message *msg);
    void remMsg(Message *msg);
};

#endif // FOLDER_H
