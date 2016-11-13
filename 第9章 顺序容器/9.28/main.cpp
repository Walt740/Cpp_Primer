#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void func(forward_list<string>& fstr,const string& s1,const string& s2)
{
    auto prev = fstr.before_begin();  //首个元素之前前
    auto curr = fstr.begin(); // 首个元素
    bool inserted = false;    
    while(curr != fstr.end())
    {
        if(*curr == s1)  //找到s1
        {
            curr = fstr.insert_after(curr,s2); //将s2插在s1之后
			inserted = true;
        }
		prev = curr; //前驱迭代器向前推进
		curr++;      //当前迭代器向前推进
    }
	if (!inserted)   
		fstr.insert_after(prev,s2);  //未找到给定字符串，插入尾后
}


int main()
{
	forward_list<string> sflst = {"Hello","!","world","!"};
	func(sflst,"Hello","你好");
	for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

	func(sflst, "!", "?");
	for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

	func(sflst, "Bye", "再见");
	for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

    return 0;
}
