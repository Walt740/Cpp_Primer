#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

inline void output_words(list<string> &words)
{
    for(auto iter = words.begin();iter != words.end();iter++)
        cout << *iter << " ";
    cout << endl;
}

void elimdups(list<string> &words)
{
//    output_words(words);
    words.sort();   //list自带的算法
//    output_words(words);
    words.unique();  //容器自带的算法
    output_words(words);
}

int main()
{
    list<string> words;
    string word;
    while(cin >> word)
        words.push_back(word);
    elimdups(words);
    return 0 ;
}

