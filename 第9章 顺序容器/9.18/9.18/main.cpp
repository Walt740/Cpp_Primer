//#include <iostream>
//#include <string>
//#include <deque>
//
//using namespace std;
//
//int main()
//{
//    string words;
//    deque<string> de_str;
//    /*deque<string>::iterator*/ 
//	auto iter = de_str.cbegin();
//    while(cin >> words)
//        de_str.push_back(words);
//        //de_str.push_front(words);
//
//    for(;iter != de_str.cend();iter++)
//        cout << *iter << " ";
//    cout << endl;
////    cout << "Hello world!" << endl;
//    return 0;
//}



//



#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	deque<string> sd;
	string word;
	//auto si = sd.cbegin();  //���������ǲ��Եģ���Ϊsd�л�û��Ԫ��
	while (cin >> word)
		//sd.push_back(word);
		sd.push_front(word);
	for (auto si = sd.cbegin(); si != sd.cend(); si++)
		cout << *si << endl;
	return 0;

}