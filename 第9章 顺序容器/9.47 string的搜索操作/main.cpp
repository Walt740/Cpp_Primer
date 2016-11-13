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
//    //查找与给定字符串中任何一个字符匹配的位置
//    auto pos = name.find_first_of(number);
//    cout << pos << endl;
//    //搜索第一个不在参数中的字符
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
string类的查找函数：
int find(char c, int pos = 0) const;//从pos开始查找字符c在当前字符串的位置
int find(const char *s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
int find(const char *s, int pos, int n) const;//从pos开始查找字符串s中前n个字符在当前串中的位置
int find(const string &s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
//查找成功时返回所在位置，失败返回string::npos的值
int rfind(char c, int pos = npos) const;//从pos开始从后向前查找字符c在当前串中的位置
int rfind(const char *s, int pos = npos) const;
int rfind(const char *s, int pos, int n = npos) const;
int rfind(const string &s,int pos = npos) const;
//从pos开始从后向前查找字符串s中前n个字符组成的字符串在当前串中的位置，成功返回所在位置，失败时返回string::npos的值
int find_first_of(char c, int pos = 0) const;//从pos开始查找字符c第一次出现的位置
int find_first_of(const char *s, int pos = 0) const;
int find_first_of(const char *s, int pos, int n) const;
int find_first_of(const string &s,int pos = 0) const;
//从pos开始查找当前串中第一个在s的前n个字符组成的数组里的字符的位置。查找失败返回string::npos
int find_first_not_of(char c, int pos = 0) const;
int find_first_not_of(const char *s, int pos = 0) const;
int find_first_not_of(const char *s, int pos,int n) const;
int find_first_not_of(const string &s,int pos = 0) const;
//从当前串中查找第一个不在串s中的字符出现的位置，失败返回string::npos
int find_last_of(char c, int pos = npos) const;
int find_last_of(const char *s, int pos = npos) const;
int find_last_of(const char *s, int pos, int n = npos) const;
int find_last_of(const string &s,int pos = npos) const;
int find_last_not_of(char c, int pos = npos) const;
int find_last_not_of(const char *s, int pos = npos) const;
int find_last_not_of(const char *s, int pos, int n) const;
int find_last_not_of(const string &s,int pos = npos) const;
//find_last_of和find_last_not_of与find_first_of和find_first_not_of相似，只不过是从后向前查找


*/

/*
int main()
{
    string number("0123456789");
    string name("walt740");
    string:: size_type pos = 0;
    //每步循环查找name中下一个数
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
    //每步循环查找name中下一个数
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



