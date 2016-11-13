#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


string& trans(string& s)
{
	for (int p = 0; p < s.size(); p++)
		s[p] = tolower(s[p]);
	s.erase(find_if(s.begin(),s.end(),ispunct),s.end());
	return s;
}

int main()
{
vector<string > unique_word;
string word;
while(cin >> word)
{
trans(word);
if (find(unique_word.begin(), unique_word.end(), word) == unique_word.end())
{
unique_word.push_back(word);  //添加不重复单词
}
}

for (const auto &w : unique_word)

cout << w << " ";
cout << endl;

return 0;
}






//int main()
//{
//	set<string> unique_word;
//	string word;
//	while (cin >> word)
//	{
//		trans(word);
//		unique_word.insert(word);
//	}
//	for (const auto &w : unique_word)
//		cout << w << " ";
//	cout << endl;
//	return 0;
//}