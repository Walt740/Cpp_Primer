#include <iostream>
#include <memory>
#include "StrBlob.h"
#include <fstream>
#include <vector>
#include <string>


using namespace std;



int main(int argc, char *argv[])
{
//    ifstream in(argv[1]);
//    if(!in)
//    {
//        cout << "can not open file" <<endl;
//        return -1;
//    }
//    StrBlob b ;
//    string s ;
//    while(getline(in,s))
//        b.push_back(s);
//    for(auto it = b.begin();neq(it,b.end());it.incr())
//        cout << it.deref() <<endl;
//    return 0;

    ifstream in("..\12.20__.sln");  //���ļ�
	if (!in)
	{
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}
	//{
	//	StrBlob b2 = { "a","an","the" };
	//	//b1 = b2;
	//	b2.push_back("about");
	//	cout << b2.size() << endl;
	//}

    StrBlob b;
    string s;
    while(getline(in,s))
        b.push_back(s);
    in.close();
    for(auto it = b.begin();neq(it,b.end());it.incr())
        cout << it.deref()<<endl;
    return 0;

}

//
///*
//    ifstream in("../8.4.sln");  //���ļ�
//	if (!in)
//	{
//		cerr << "�޷��������ļ�" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while (getline(in, line))
//	{
//		words.push_back(line);//��ӵ�vector��
//	}
//	in.close();//�ر��ļ�
//
//	for (string it : words)
//		cout << it << endl;
//	return 0;
//*/


//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	ifstream in("../11.txt");  //���ļ�
//	if (!in)
//	{
//		cerr << "�޷��������ļ�" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while (getline(in, line))
//	{
//		words.push_back(line);//��ӵ�vector��
//	}
//	in.close();//�ر��ļ�
//	//vector<string>::const_iterator it = words.begin();//������
//	//while (it != words.end())
//	//{
//	//	cout << *it << endl;
//	//	++it;
//	//}
//	for (string it : words)
//		cout << it << endl;
//	return 0;
//
//
//}
//
//
//
