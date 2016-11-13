// 8.11.cpp : 定义控制台应用程序的入口点。

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo 
{
	string name;
	vector<string> phones;
};



int main()
{
	string line, word;
	vector<PersonInfo> people;
	
	while (getline(cin,line))
	{
		PersonInfo info;
		istringstream record;
		//record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	return 0;
}


