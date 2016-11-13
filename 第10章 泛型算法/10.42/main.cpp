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
    words.sort();   //list�Դ����㷨
//    output_words(words);
    words.unique();  //�����Դ����㷨
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

