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
			auto &lines = wm[word]; //lines��ֻ�ǿ���ָ���ֵ�����ǰ󶨵�wm������ָ�룬��һ������
			if (!lines)
				lines.reset(new set<line_no>); //����һ���µ�set
			lines->insert(n); //�����кŲ��뵽set��
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
	//���δ�ҵ�sought�����ǽ�����һ��ָ���set��ָ��
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//ʹ��find�������±�����������ҵ��ʣ����⽫������ӵ�wm�У�
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}






ostream &print(ostream &os, const QueryResult &qr)
{
	//����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	os << qr.sought << " occurs " << qr.lines->size() << " " << ((qr.lines->size() > 1) ? " times" : " time") << endl;
	//��ӡ���ʳ��ֵ�ÿһ��
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
	return os;
}

