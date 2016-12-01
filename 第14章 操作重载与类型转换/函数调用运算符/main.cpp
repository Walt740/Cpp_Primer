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
    ostream &os;   //����д���Ŀ����
    char sep;       //���ڽ���ͬ����������ַ�
};




int main()
{

    string s = "yinhao" ;
    PrintString printer;
    printer(s);
    PrintString errors(cerr,'\n');
    errors(s);  //��cerr�д�ӡs�������һ�����з�
    errors(s);
    errors(s);

    vector<string> vs = {"yinhao","zheng","1","2","3","4"};
    for_each(vs.begin(),vs.end(),PrintString(cerr,'\n'));

    return 0 ;
}


