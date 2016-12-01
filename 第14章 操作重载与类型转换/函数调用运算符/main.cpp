/*

#include <iostream>

using namespace std;

struct absInt
{
    int operator() (int val) const
    {
        return val < 0 ? -val : val;
    }
};



int main()
{
    int i = -42;
    absInt absobj;
    int ui = absobj(i);
    cout << absobj(i) << endl;
    cout << absobj.operator()(i) << endl ;
    return 0;
}

*/

//////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class PrintString
{
public:
    PrintString(ostream &o = cout ,char c =' '):os(o),sep(c) {}
    void operator()(const string &s) const {os << s << sep ;}
private:
    ostream &os;   //用于写入的目的流
    char sep;       //用于将不同输出隔开的字符
};




int main()
{

    string s = "yinhao" ;
    PrintString printer;
    printer(s);
    PrintString errors(cerr,'\n');
    errors(s);  //在cerr中打印s，后面跟一个换行符
    errors(s);
    errors(s);

    vector<string> vs = {"yinhao","zheng","1","2","3","4"};
    for_each(vs.begin(),vs.end(),PrintString(cerr,'\n'));

    return 0 ;
}


