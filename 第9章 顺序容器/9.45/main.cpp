#include <iostream>
#include <string>
using namespace std;

void func(string& s,const string& fr,const string &la)
{
    s.insert(s.begin(),1,' ');
    s.insert(s.begin(),fr.cbegin(),fr.cend());
    s.append(" ");
    s.append(la.begin(),la.end());
}


int main()
{

    string s = "James Bond";
    func(s,"Mrs.","III");
    cout << s << endl;
    return 0;
}
