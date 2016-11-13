#include <iostream>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

string& trans(string& s)
{
    for(int p = 0;p < s.size();p++)
    {
        //if(s[p] >= 'A'&& s[p] <= 'Z')
        //    s[p] -= ('A' - 'a');
        //else if(s[p] == ',' || s[p] == '.')
        //    s.erase(p,1);

		s[p] = tolower(s[p]);
		s.erase(remove_if(s.begin(),s.end(),ispunct),s.end());


    }
    return s;
}


int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count[trans(word)];
	for (const auto &w : word_count)
		cout << w.first << "出现了" << w.second << "次" << endl;
    return 0;
}
