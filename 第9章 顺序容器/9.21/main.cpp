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
    �൱���� push_front()����
*/
int main()
{
    vector<string> svec;
    string word;
    auto iter = svec.begin();
    while(cin >> word)
    iter = svec.insert(iter,word);
    //��cbegin()��ȡvector��Ԫ�ص�����������vector������Ԫ��
    for(auto iter = svec.cbegin(); iter != svec.cend(); iter++)
        cout << *iter  <<endl ;
    return 0;
}
