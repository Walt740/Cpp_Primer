#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

//int main()
//{
//	int ival;
//	while(cin >> ival)
//		cout << "读写成功！" <<endl;
//	cout << "读写失败！" << endl;
//	return 0;
//}

istream& func(istream& in)
{
	string v;
	/****************************************************************************************
		int iVal;
		cin >> iVal;
		如果我们在标准输入上键入Boo,读操作就会失败。代码中的输入运算符期待读取一个int，
		但却得到了一个字符B。这样，cin会进入错误状态。类似的，如果我们输入一个文件结束标识，cin
		也会进入错误状态。
	****************************************************************************************/
	while (in >> v, !in.eof())
	{
		if (in.bad())
			throw runtime_error("IO流错误");
		if(in.fail()){
			cerr << "数据错误，请重试:" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
		in.clear();
		return in;
}

istream& f(istream& is)
{
	string num;
	while(is>>num,!is.eof())
	{
       // is >> num;
		if (is.bad())
			throw runtime_error("IO流错误");
		if (is.fail())
		{
			cout << "输入数据错误，请重输..." << endl;
			is.clear(); //仅仅是清除流中的状态位
			is.ignore(100, '\n');  //忽略流中的元素 在前100个元素中找'\n' ,若无'\n'，则忽略前100个
								   // 若有'\n'，则忽略'\n'前的元素
			continue;
		}	
	    cout << num << endl;
		
	}//while (!is.eof());
	is.clear();
	return is;
}




int main() 
{
//	cout << "请输入一些整数，按Ctrl+Z结束" << endl;
	ostringstream msg;
	msg << "C++ Primer 第五版" << endl;
	istringstream in(msg.str());
	
	f(in);
	return 0;
}