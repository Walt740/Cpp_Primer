//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//class IsShorter
//{
//public:
//    bool operator()(const string &s1,const string &s2)
//    {
//        return s1.size() < s2.size();
//    }
//};
//
//
//class NotShorterThan
//{
//public:
//    NotShorterThan(int len): minLen(len){}
//    bool operator()(const string &str)
//    {
//        return str.size() >= minLen;
//    }
//private:
//    int minLen;
//};
//
//
//class PrintString
//{
//public:
//    void operator() (const string &str)
//    {
//        cout << str << " ";
//    }
//};
//void elimdups(vector<string>&vec)
//{
//    sort(vec.begin(),vec.end());
//    auto new_end = unique(vec.begin(),vec.end());
//    vec.erase(new_end,vec.end());
//}
//
//
//string  make_plural(vector<string>::size_type sz,  const string &s1, const string &s2)
//{
//   return  (sz > 1 )? s1+s2 : s1;
//}
//
//void biggies(vector<string>&vec,size_t sz)
//{
//    elimdups(vec);
//    IsShorter is;
//    stable_sort(vec.begin(),vec.end(),is);
//    NotShorterThan nst(sz);
//    auto wc = find_if(vec.begin(),vec.end(),nst);
//
//    auto count = vec.end() - wc;
//    cout << count <<" "<< make_plural(count,"word","s") <<
//    " of length " <<sz <<" or longer "<< endl;
//
//    for_each(wc,vec.end(),PrintString());
//    cout << endl;
//}
//
//
//int main()
//{
//
//    auto v = vector<string>{"a","aaa","aaaa","aaaaa","aaaaaa","aaaaaaaa"};
//    biggies(v,10);
//
//    return 0;
//}


#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> coll;
	for(int i = 1; i <= 10; ++i)
	{
		coll.push_back(i);
	}
	//查找元素值大于10的元素的个数
	//也就是使得10 < elem成立的元素个数
	int res = count_if(coll.begin(), coll.end(), bind1st(less<int>(), 10));
	cout << res << endl;
	//查找元素值小于10的元素的个数
	//也就是使得elem < 10成立的元素个数
	res = count_if(coll.begin(), coll.end(), bind2nd(less<int>(), 10));
	cout << res << endl;

	return 0;
}
