#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<char*> slist = {"hello","world","!"};
	vector<string> svec;
		
	svec.assign(slist.begin(),slist.end()); //¸³ÖµÓï¾äÓÃassign
	cout << svec.capacity() << " " << svec.size()
		 << " " << svec[0]  << " " << svec[svec.size() - 1] << endl;

	return 0;
 }