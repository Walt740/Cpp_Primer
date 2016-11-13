#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <memory>

using namespace std;

class QueryResult;//前向声明
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    
	shared_ptr<vector<string>> file; //输入文件
    map<string,shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
	friend ostream &print(ostream &os, const QueryResult &qr);
public:
	QueryResult(const string s,
		shared_ptr<set<TextQuery::line_no>> p,
		shared_ptr<vector<string>> file) :
		sought(s), lines(p), file(file) {}

private:
	string sought; //查询单词
	shared_ptr<set<TextQuery::line_no>> lines; // 出现的行号
	shared_ptr<vector<string>> file; //输入文件

};

=======
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
    using line_no  =  vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &)const;
    string cleanup_str(const string &word) ;
private:
    shared_ptr<vector<string>> file;
    map<string,shared_ptr<set<line_no>>> wm;
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
>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while(getline(is,text))
    {
<<<<<<< HEAD
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word]; //lines不只是拷贝指针的值，而是绑定到wm的智能指针，是一个引用
			if (!lines)
				lines.reset(new set<line_no>); //分配一个新的set
			lines->insert(n); //将此行号插入到set中
		}
=======
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word)
        {
            auto &lines = wm[cleanup_str(word)];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
    }
}





<<<<<<< HEAD
QueryResult TextQuery::query(const string &sought) const
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
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< ((qr.lines->size() > 1) ? " times" : " time") << endl;
	//打印单词出现的每一行
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}


void runQueries(ifstream &infile)
{
	//infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);
	//与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while (true)
	{
		cout << "enter word to look for ,or q to quit: ";
		string s;
		//若遇到文件尾或用户输入了‘q’ 时循环终止
		if (!(cin >> s) || s == "q") break;
		//指向查询并打印结果
		print(cout,tq.query(s)) << endl ;
	}
}


int main()
{
	ifstream file("../file.txt");
	if (!file)
	{
		cerr << "未找到输入文件 " << endl;
		return -1;
	}
	runQueries(file);
    return 0;
=======
class QueryResult
{

friend ostream &print(ostream &,const QueryResult& );
public:
    QueryResult(string s,
                shared_ptr<set<TextQuery::line_no>>p,
                shared_ptr<vector<string>>f):
                    sought(s),lines(p),file(f){}
private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
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
    static shared_ptr<set<TextQuery::line_no>> nodata(new set<line_no>);
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
>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
}



<<<<<<< HEAD

//

=======
int main()
{
     ifstream file("file.txt");
     runqueries(file);
     return 0;
}
>>>>>>> 7f8096c2a2d72166ab1441a3b1ee2e18fb6e4bfe
