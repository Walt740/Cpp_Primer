#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1 = {1,2,3,4,5,6};
	vector<int> v2 = {1,2,3,4};

	if (v1 == v2)
		cout << "两个容器相等" << endl;
	else
	{
		cout << "两个容器不相等" << endl;
		if (v1 < v2)
			cout << "v1 < v2 " << endl;
		else
			cout << "v1 > v2 " << endl;
 	}
		

	return 0;

}