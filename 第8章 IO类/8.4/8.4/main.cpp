//#include <iostream>
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	//ostream os;
//	//os << "Please  enter a value: ";
//	cout << unitbuf;	  //所有输出操作后都会立即刷新缓存区
//	cout << "hi" << ends; //
//	cout << "hi" << flush;
//	cout << "hi" << endl;
//	cout << nounitbuf;   //回到正常的缓冲方式
//
//
//	cin.tie(&cout);
//
//	return 0;
//}   

//#include <ios>
//#include <iostream>
//
//int main()
//{
//	using namespace std;
//	int i;
//	cin.tie(&cout);
//	cout << "Enter a number:";
//	cin >> i;
//}

//8.4编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，
//将每一行作为一个独立的元素存于vector中

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream in("../8.4.sln");  //打开文件
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



