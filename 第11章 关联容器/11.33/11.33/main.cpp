#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


map<string, string> buildMap(ifstream& map_file)
{
	map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
			//trans_map.insert({key,value.substr(1)});
		else
			throw runtime_error("no rule for" + key);
	return trans_map;
}
const string & transform(const string & s, map<string,string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
	//return m[s];
}

void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word,trans_map);
		}
		cout << endl;
	}
}


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "ifs_rules ifs_txt" << endl;
		return -1;
	}
	ifstream ifs_rules(argv[1]);
	
	if (!ifs_rules)
	{
		cout << "打开输入文件失败！" << endl;
		exit(1);
	}
	ifstream ifs_txt(argv[2]);
	if (!ifs_txt)
	{
		cout << "打开输入文件失败！" << endl;
		exit(1);
	}

	word_transform(ifs_rules,ifs_txt);
	return 0;
}

//#include <iostream>
//#include <map>
//#include <fstream>
//#include <sstream>
//#include <string>
//using namespace std;
//
//void word_transform(ifstream&, ifstream&);
//map<string, string> buildMap(ifstream&);
//string transform(const string&, map<string, string>&);
//
//int main()
//{
//	ifstream ifs_rules("H:/code/C++/Cpp_Primer_Answers/data/transform_rules.txt");
//	ifstream ifs_txt("H:/code/C++/Cpp_Primer_Answers/data/for_transform.txt");
//
//	word_transform(ifs_rules, ifs_txt);
//	return 0;
//}
//
//void word_transform(ifstream& rule_file, ifstream& input)
//{
//	auto rule_map = buildMap(rule_file);
//	string text;
//	while (getline(input, text))
//	{
//		istringstream stream(text);
//		string word;
//		bool firstword = true;
//		while (stream >> word)
//		{
//			if (firstword)
//				firstword = false;
//			else
//				cout << " ";
//			cout << transform(word, rule_map);
//		}
//		cout << endl;
//	}
//}
//
//map<string, string> buildMap(ifstream& rule_file)
//{
//	map<string, string> m;
//	string key;
//	string value;
//	while (rule_file >> key && getline(rule_file, value))
//	{
//		if (value.size() > 1)
//			m[key] = value.substr(1);
//		else
//			throw runtime_error("no rule for " + key);
//	}
//	return m;
//}
//
//string transform(const string& s, map<string, string>& m)
//{
//	auto it = m.find(s);
//	if (it != m.cend())
//		return it->second;
//	else
//		return s;
//}