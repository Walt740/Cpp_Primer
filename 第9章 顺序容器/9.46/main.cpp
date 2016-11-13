#include <iostream>
#include <string>
using namespace std;

void name_string(string& s,const string& prefix,const string& suffix)
{
    s.insert(0,1,' '); //0 表示下标为0
    s.insert(0,prefix);
    s.insert(s.size()," ");
    s.insert(s.size(),suffix);
}


int main()
{

    string s = "James Bond";
    name_string(s,"Mrs.","III");
    cout << s << endl;

    s = "M";
    name_string(s,"Mrs.","III");
    cout << s << endl;

    return 0;
}


