#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	vector<pair<string,int> > data;
	string s;
	int v;
	while (cin >> s && cin >> v)
	{
		//data.push_back(pair<string,int> (s,v));
		data.push_back({s,v});
		//data.push_back(make_pair(s, v));
	}
	for (const auto& d: data)
	{
		cout << d.first << " " << d.second << endl;
	}
	return 0;
}