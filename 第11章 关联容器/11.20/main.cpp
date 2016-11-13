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
        if(!ret.second) //���������ص�������һ��pair���� firstΪָ����и����ؼ��ֵ�Ԫ�أ�second��Ա��һ��boolֵ��
            //ָ��Ԫ���ǲ���ɹ������Ѿ�������������
            ++ret.first->second;//����������
    }
//    while(cin >> word)
//        ++word_count.insert({word,0}).first->second;
    for(auto &w: word_count)

        cout << w.first << "������"  << w.second << "��" << endl;
    return 0;
}
