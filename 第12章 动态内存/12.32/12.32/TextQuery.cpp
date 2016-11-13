//TextQuery.cc
#include "TextQuery.h"
//#include "make_plural.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;


TextQuery::TextQuery(ifstream &is) //: file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word]; //lines不只是拷贝指针的值，而是绑定到wm的智能指针，是一个引用
			if (!lines)
				lines.reset(new set<line_no>); //分配一个新的set
			lines->insert(n); //将此行号插入到set中
		}
	}
}




string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it)
	{
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}



QueryResult
TextQuery::query(const string &sought) const
{
	//如果未找到sought，我们将返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//使用find而不是下标运算符来查找单词，避免将单词添加到wm中！
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}






ostream &print(ostream &os, const QueryResult &qr)
{
	//如果找到了单词，打印出现次数和所有出现的位置
	os << qr.sought << " occurs " << qr.lines->size() << " " << ((qr.lines->size() > 1) ? " times" : " time") << endl;
	//打印单词出现的每一行
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
	return os;
}

