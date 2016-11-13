#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

//int main()
//{
//    int i = 42;
//    string s = to_string(i);
//    cout << s << endl;
//	double d = stod(s);
//	cout << d << endl;
//	string s2 = "pi = 3.14";
//	//d = stod(s.substr(s2.find_first_of("+-.0123456789")));
//	d = stod(s2);
//
//    return 0;
//}


/*
int main()
{
    vector<string> vs = {"123","+456","-789"};
    int sum = 0;
    for(auto iter = vs.begin();iter != vs.end();iter++)
    {
        sum += stoi(*iter);
    }
    cout << "ºÍ£º" << sum << endl;
    return 0;

}

*/

int main()
{
    vector<string> vs = {"12.3","-4.56","-7.8e-2"};
    float sum = 0;
    for(auto iter = vs.begin();iter != vs.end();iter++)
    {
        sum += stof(*iter);
    }
    cout << "ºÍ£º" << sum << endl;
    return 0;

}
