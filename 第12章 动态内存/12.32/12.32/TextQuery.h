//TextQuery.h
#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <string>
#include <fstream>
#include "QueryResult.h"


class QueryResult;
class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	StrBlob file;
	//shared_ptr<vector<string>> file; //ÊäÈëÎÄ¼þ
	map<string, shared_ptr<set<line_no>>> wm;
	static string cleanup_str(const string &word);
};





#endif


