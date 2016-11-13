#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int main()
{
    map<string,size_t> word_count;
    string word;
    while(cin >> word)
    {
//        auto ret = word_count.insert({word,1});
//        auto ret = word_count.insert(pair<string,int>(word,1));
//        auto ret = word_count.insert(make_pair(word,1));
        auto ret = word_count.insert(map<string,int>::value_type(word,1));
        if(!ret.second) //迭代器返回的类型是一个pair类型 first为指向具有给定关键字的元素，second成员是一个bool值，
            //指出元素是插入成功还是已经存在与容器中
            ++ret.first->second;//递增计数器
    }
//    while(cin >> word)
//        ++word_count.insert({word,0}).first->second;
    for(auto &w: word_count)

        cout << w.first << "出现了"  << w.second << "次" << endl;
    return 0;
}
