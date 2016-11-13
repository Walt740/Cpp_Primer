#include <iostream>
#include <string>
#include <deque>
#include <list>

using namespace std;

int main()
{
    string words;
    list<string> de_str;

    while(cin >> words)
       // de_str.push_back(words);
        de_str.push_front(words);

    for(list<string>::iterator iter = de_str.begin();iter != de_str.end();iter++)
        cout << *iter << " ";
    cout << endl;
//    cout << "Hello world!" << endl;
    return 0;
}
