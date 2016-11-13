#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void func(forward_list<string>& fstr,const string& s1,const string& s2)
{
    auto prev = fstr.before_begin();  //�׸�Ԫ��֮ǰǰ
    auto curr = fstr.begin(); // �׸�Ԫ��
    bool inserted = false;    
    while(curr != fstr.end())
    {
        if(*curr == s1)  //�ҵ�s1
        {
            curr = fstr.insert_after(curr,s2); //��s2����s1֮��
			inserted = true;
        }
		prev = curr; //ǰ����������ǰ�ƽ�
		curr++;      //��ǰ��������ǰ�ƽ�
    }
	if (!inserted)   
		fstr.insert_after(prev,s2);  //δ�ҵ������ַ���������β��
}


int main()
{
	forward_list<string> sflst = {"Hello","!","world","!"};
	func(sflst,"Hello","���");
	for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

	func(sflst, "!", "?");
	for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

	func(sflst, "Bye", "�ټ�");
	for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

    return 0;
}
