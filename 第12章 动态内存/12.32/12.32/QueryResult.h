//QueryResult.h
#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "StrBlob.h"


class QueryResult
{  
	using line_no = vector<string>::size_type;
	friend ostream &print(ostream &os, const QueryResult &qr);
public:
	QueryResult(const string s,
				shared_ptr<set<line_no>> p,
				//shared_ptr<vector<string>> file
				StrBlob file) : sought(s), lines(p), file(file) {}
								
    std::set<line_no>::size_type size() const  { return lines->size(); }
    //line_it begin() const { return lines->cbegin(); }
    //line_it end() const   { return lines->cend(); }
    //StrBlob get_file() { return file; }
private:
	string sought; //查询单词
	shared_ptr<set<line_no>> lines; // 出现的行号
											   //shared_ptr<vector<string>> file; //输入文件
	StrBlob file;
};


#endif

