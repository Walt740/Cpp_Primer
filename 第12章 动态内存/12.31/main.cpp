#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;


class QueryResult;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &)const;
    string cleanup_str(const string &word);
private:
    shared_ptr<vector<string>> file;
    map<string,shared_ptr<vector<line_no>>> wm;
};

string TextQuery::cleanup_str(const string &word)
{
    string ret ;
    for(auto it = word.begin();it!= word.end(); it++)
    {
        if(!ispunct(*it))
        {
            ret += tolower(*it);
        }
    }
    return ret;
}
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while(getline(is,text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word)
        {
            auto &lines = wm[cleanup_str(word)];
            if(!lines)
                lines.reset(new vector<line_no>);
            lines->push_back(n);
        }
    }
}


class QueryResult
{

friend ostream &print(ostream &,const QueryResult& );
public:
    QueryResult(string s,
                shared_ptr<vector<TextQuery::line_no>>p,
                shared_ptr<vector<string>>f):
                    sought(s),lines(p),file(f){}
private:
    string sought;
    shared_ptr<vector<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream  &print(ostream &os,const QueryResult &qr)
{
    os << qr.sought << "occurs " << qr.lines->size() << " "
    << ((qr.lines->size() > 1)? " times " : " time ") << endl;
    for(auto num : *qr.lines)
        os << " \t (line " << num + 1 << " ) " << *(qr.file->begin() + num) << endl;
    return os;
}

QueryResult TextQuery::query(const string &sought)const
{
    static shared_ptr<vector<TextQuery::line_no>> nodata(new vector<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought,nodata,file);
    else
        return QueryResult(sought,loc->second,file);
}
void runqueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "enter word to look for ,or q to quit :" ;
        string s ;
        if(!(cin >> s) || s == "q") break;
        print(cout,tq.query(s)) << endl;
    }
}



int main()
{
     ifstream file("file.txt");
     runqueries(file);
     return 0;
}
