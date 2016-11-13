#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>


using namespace std;

int main()
{
	ifstream filein("file.txt");
	if (!filein) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
	
	string line;
	vector<string> words;
	while (getline(filein, line))
	{
		words.push_back(line);
	}

	filein.close();

	for (auto c : words)
	{
		istringstream line_str(c);
		string word;
		while (line_str >> word)
			cout << word << " ";
		cout << endl;
	}
	return 0;

}