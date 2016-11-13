#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    //统计每个单词在输入中出现的次数
    map<string,size_t> word_count; //string到size_t的空map
    string word;
    while(cin >> word)
        word_count[word]++; //提取word的计数器并将其加1
    for(const auto &w :word_count)
        cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times ":" time ") << endl;


    return 0;
}
