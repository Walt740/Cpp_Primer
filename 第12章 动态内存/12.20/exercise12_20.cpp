#include <iostream>
#include <fstream>
#include "exercise12_19.h"

using namespace std;

int main()
{
	ifstream ifs("11.txt");
	if (!ifs)
	{
		cout << "文件打开失败" << endl;
		return -1;
	}
	StrBlob sb;
	string s;
	while (getline(ifs, s))
	{
		sb.push_back(s);
	}
	for (StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr())
	{
		cout << sbp.deref() << endl;
	}



	return 0;
}