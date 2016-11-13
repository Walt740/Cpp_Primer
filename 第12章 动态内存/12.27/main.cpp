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

class QueryResult;//ǰ������
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    
	shared_ptr<vector<string>> file; //�����ļ�
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
	string sought; //��ѯ����
	shared_ptr<set<TextQuery::line_no>> lines; // ���ֵ��к�
	shared_ptr<vector<string>> file; //�����ļ�

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
			auto &lines = wm[word]; //lines��ֻ�ǿ���ָ���ֵ�����ǰ󶨵�wm������ָ�룬��һ������
			if (!lines)
				lines.reset(new set<line_no>); //����һ���µ�set
			lines->insert(n); //�����кŲ��뵽set��
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
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< ((qr.lines->size() > 1) ? " times" : " time") << endl;
	//��ӡ���ʳ��ֵ�ÿһ��
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}


void runQueries(ifstream &infile)
{
	//infile��һ��ifstream��ָ������Ҫ������ļ�
	TextQuery tq(infile);
	//���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
	while (true)
	{
		cout << "enter word to look for ,or q to quit: ";
		string s;
		//�������ļ�β���û������ˡ�q�� ʱѭ����ֹ
		if (!(cin >> s) || s == "q") break;
		//ָ���ѯ����ӡ���
		print(cout,tq.query(s)) << endl ;
	}
}


int main()
{
	ifstream file("../file.txt");
	if (!file)
	{
		cerr << "δ�ҵ������ļ� " << endl;
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
