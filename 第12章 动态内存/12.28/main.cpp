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
            ret += tolower(*it); //ת��ΪСд��ȥ��������
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
        //����ǰ�кŲ��뵽���к�set��
        //������ʲ���wm�У� ��֮Ϊ�±���wm�����һ��
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
    //ʹ��find�������±�����������ҵ��ʣ����⽫������ӵ�wm��
    auto loc = wm.find(sought);
    if(loc == wm.end())
        os << sought << "������0��" << endl;
    else
    {
        auto lines = loc->second ; //�к�set
        os << sought << "������" << lines.size() <<" �� " << endl;
        for(auto num : lines)
            os << " \t(��" << num + 1 << "��)" << *(file.begin() + num) <<endl;
    }
    return os;

}

void runqueries(ifstream &infile)
{
    //infile��һ��ifstream��ָ������Ҫ��ѯ���ļ�
    input_text(infile);
    //���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
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
        cerr <<"�������ļ�ʧ�ܣ�" << endl;
        return -1;
    }
    runqueries(infile);
    return 0;
}



>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
