#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//Á·Ï°14.35
class PrintString
{
public:

    PrintString(istream &i = cin) :is(i) {}
    string operator()()
    {
        string line;
        if(!getline(is,line))
            return string("");
        return line;
    }
private:
    istream &is;

};



int main()
{
    //Á·Ï°14.36
    PrintString ps ;
    vector<string> vs;
    while(true)
    {
        string line = ps();
        if(!line.empty())
            vs.push_back(line);
        else
            break;
    }
    for(auto &c : vs )
        cout << c << endl;
    return 0;
}
