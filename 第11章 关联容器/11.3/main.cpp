#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    //ͳ��ÿ�������������г��ֵĴ���
    map<string,size_t> word_count; //string��size_t�Ŀ�map
    string word;
    while(cin >> word)
        word_count[word]++; //��ȡword�ļ������������1
    for(const auto &w :word_count)
        cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times ":" time ") << endl;


    return 0;
}
