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
class TextQuery{
public:
    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    void display_map();
private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    static std::string cleanup_str(const string &word);
};
#endif
