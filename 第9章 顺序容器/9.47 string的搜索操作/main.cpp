#include <iostream>
#include <string>

using namespace std;

//int main()
//{
////    string name("AnnaBelle");
////    auto pos1 = name.find("0nna");
////    cout << pos1 << endl;
//
//    string number("0123456789"),name("r2d2");
//    //����������ַ������κ�һ���ַ�ƥ���λ��
//    auto pos = name.find_first_of(number);
//    cout << pos << endl;
//    //������һ�����ڲ����е��ַ�
//    string dept("012");
//    //auto pos1 = dept.find_first_not_of(number);
//    auto pos1 = dept.find(number);
//    cout << pos1 << endl;
//    const char* ch = "zhynj.yinhao";
//    string name1("abcdefgabc");
//    auto posi = name1.find_last_of("dds");
//    cout << posi <<endl ;
//
//    cout << name1.find_first_not_of("abc")<<endl;
//    cout << name1.find_last_not_of("abc")<<endl;
//
//    cout << name1.find_first_of(ch,0,5);
//
//
//    return 0;
//}

/*
string��Ĳ��Һ�����
int find(char c, int pos = 0) const;//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
int find(const char *s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
int find(const char *s, int pos, int n) const;//��pos��ʼ�����ַ���s��ǰn���ַ��ڵ�ǰ���е�λ��
int find(const string &s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
//���ҳɹ�ʱ��������λ�ã�ʧ�ܷ���string::npos��ֵ
int rfind(char c, int pos = npos) const;//��pos��ʼ�Ӻ���ǰ�����ַ�c�ڵ�ǰ���е�λ��
int rfind(const char *s, int pos = npos) const;
int rfind(const char *s, int pos, int n = npos) const;
int rfind(const string &s,int pos = npos) const;
//��pos��ʼ�Ӻ���ǰ�����ַ���s��ǰn���ַ���ɵ��ַ����ڵ�ǰ���е�λ�ã��ɹ���������λ�ã�ʧ��ʱ����string::npos��ֵ
int find_first_of(char c, int pos = 0) const;//��pos��ʼ�����ַ�c��һ�γ��ֵ�λ��
int find_first_of(const char *s, int pos = 0) const;
int find_first_of(const char *s, int pos, int n) const;
int find_first_of(const string &s,int pos = 0) const;
//��pos��ʼ���ҵ�ǰ���е�һ����s��ǰn���ַ���ɵ���������ַ���λ�á�����ʧ�ܷ���string::npos
int find_first_not_of(char c, int pos = 0) const;
int find_first_not_of(const char *s, int pos = 0) const;
int find_first_not_of(const char *s, int pos,int n) const;
int find_first_not_of(const string &s,int pos = 0) const;
//�ӵ�ǰ���в��ҵ�һ�����ڴ�s�е��ַ����ֵ�λ�ã�ʧ�ܷ���string::npos
int find_last_of(char c, int pos = npos) const;
int find_last_of(const char *s, int pos = npos) const;
int find_last_of(const char *s, int pos, int n = npos) const;
int find_last_of(const string &s,int pos = npos) const;
int find_last_not_of(char c, int pos = npos) const;
int find_last_not_of(const char *s, int pos = npos) const;
int find_last_not_of(const char *s, int pos, int n) const;
int find_last_not_of(const string &s,int pos = npos) const;
//find_last_of��find_last_not_of��find_first_of��find_first_not_of���ƣ�ֻ�����ǴӺ���ǰ����


*/

/*
int main()
{
    string number("0123456789");
    string name("walt740");
    string:: size_type pos = 0;
    //ÿ��ѭ������name����һ����
    while((pos = name.find_first_of(number,pos))!= string::npos )
    {
        cout << "found number at index: " << pos
             << " element is " << name[pos] <<endl ;
        pos++;

    }
    return 0 ;
}



int main()
{
    string number("0123456789");
    string name("walt740");
    string:: size_type pos = string::npos;
    //ÿ��ѭ������name����һ����
    while((pos = name.find_last_of(number,pos))!= string::npos )
    {
        cout << "found number at index: " << pos
             << " element is " << name[pos] <<endl ;
        pos--;

    }
}
*/



int main()
{
    string letter("asdfghjklqwertyuiopzxcvbnmASDFGHJKLQWERTYUIOPZXCVBNM");
    string number("1234567890");
    string str("ab2c3d7R4E6");
    string::size_type pos = 0;

    while((pos = str.find_first_of(number,pos))!= string::npos )
    {
        cout << "found number at index: " << pos
             << " element is " << str[pos] <<endl ;
        pos++;
    }
    pos = 0;
    while((pos = str.find_first_of(letter,pos))!= string::npos )
    {
        cout << "found number at index: " << pos
             << " element is " << str[pos] <<endl ;
        pos++;
    }
    return 0;
}



