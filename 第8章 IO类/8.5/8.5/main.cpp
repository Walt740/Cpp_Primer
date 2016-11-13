#include <fstream>
#include <iostream>
#include <string>
#include <vector>



using namespace std;


int main()
{
	ifstream in("main.cpp");

	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1; 
	}
		
	ofstream out;
	out.open(".copy");
	string line;
	vector<string> words;
	while (in >> line)
	{
		words.push_back(line);
	}
	for (auto &it : words)
		cout << it << endl;


	return 0;
}

