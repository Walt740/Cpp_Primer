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

    ifstream in("d:11.txt");  //打开文件
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

		const StrBlob b2 = { "a","an","the" };
		//b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;

    for(auto it = b2.begin();neq(it,b2.end());it.incr())
        cout << it.deref()<<endl;
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
//    ifstream in("../8.4.sln");  //打开文件
//	if (!in)
//	{
//		cerr << "无法打开输入文件" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while (getline(in, line))
//	{
//		words.push_back(line);//添加到vector中
//	}
//	in.close();//关闭文件
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
//	ifstream in("../11.txt");  //打开文件
//	if (!in)
//	{
//		cerr << "无法打开输入文件" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while (getline(in, line))
//	{
//		words.push_back(line);//添加到vector中
//	}
//	in.close();//关闭文件
//	//vector<string>::const_iterator it = words.begin();//迭代器
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
