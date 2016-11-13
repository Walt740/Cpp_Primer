#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream in;
	in.open("../11.txt");  //打开文件
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
	string line;
	vector<string> words;
	while (getline(in, line))
	{
		words.push_back(line);//添加到vector中
	}
	in.close();//关闭文件
	//vector<string>::const_iterator it = words.begin();//迭代器
	//while (it != words.end())
	//{
	//	cout << *it << endl;
	//	++it;
	//}
	for (string it : words)
		cout << it << endl;
	return 0;


}



