#include <iostream>
#include <list>
#include <vector>
#include <string>


using namespace std;

//int main()
//{
//    list<string> lst;
//    auto iter = lst.begin();
//    while(cin >> word)
//        iter = lst.insert(iter,word);
//
//
//    return 0;
//}

/*
    while(cin >> word)
    iter = svec.insert(iter,word);
    相当于是 push_front()操作
*/
int main()
{
    vector<string> svec;
    string word;
    auto iter = svec.begin();
    while(cin >> word)
    iter = svec.insert(iter,word);
    //用cbegin()获取vector首元素迭代器，遍历vector中所有元素
    for(auto iter = svec.cbegin(); iter != svec.cend(); iter++)
        cout << *iter  <<endl ;
    return 0;
}
