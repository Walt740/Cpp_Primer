#include <iostream>
<<<<<<< HEAD

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
=======
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;


using line_no = vector<string>::size_type;
vector<string> file;
map<string,set<line_no>> wm;

string cleanup_str(const string &word)
{
    string ret ;
    for(auto it = word.begin();it!=word.end();++it)
        if(!ispunct(*it))
            ret += tolower(*it); //转换为小写，去掉标点符号
    return ret;
}

void input_text(ifstream &is)
{
    string text;
    while(getline(is,text))
    {
        file.push_back(text);
        int n = file.size() -1 ;
        istringstream line(text);
        string word;
        while(line >> word)
        //将当前行号插入到其行号set中
        //如果单词不在wm中， 以之为下标在wm中添加一项
            wm[cleanup_str(word)].insert(n);
    }
    for(auto it = wm.cbegin();it != wm.cend();it++)
    {
        cout << it->first << endl ;
        for(auto iter = it->second.cbegin();iter != it->second.cend(); iter++)
            cout  << *iter << " ";
        cout << endl ;
    }
}

ostream &query_and_print(const string &sought,ostream &os)
{
    //使用find而不是下标运算符来查找单词，避免将单词添加到wm中
    auto loc = wm.find(sought);
    if(loc == wm.end())
        os << sought << "出现了0次" << endl;
    else
    {
        auto lines = loc->second ; //行号set
        os << sought << "出现了" << lines.size() <<" 次 " << endl;
        for(auto num : lines)
            os << " \t(第" << num + 1 << "行)" << *(file.begin() + num) <<endl;
    }
    return os;

}

void runqueries(ifstream &infile)
{
    //infile是一个ifstream，指向我们要查询的文件
    input_text(infile);
    //与用户交互：提示用户输入要查询的单词，完成查询并打印结果
//    while(true)
//    {
//        cout << "enter word to look for , or q to quit: ";
//        string s ;
//        if(!(cin >> s) || s == "q") break;
//        query_and_print(s,cout) << endl;
//    }

    do//while(true)
    {
        cout << "enter word to look for , or q to quit: ";
        string s ;
        if(!(cin >> s) || s == "q") break;
        query_and_print(s,cout) << endl;0

}

int main()
{
    ifstream infile("file.txt");
    if(!infile)
    {
        cerr <<"打开输入文件失败！" << endl;
        return -1;
    }
    runqueries(infile);
    return 0;
}



>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
