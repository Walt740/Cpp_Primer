//#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    istream_iterator<int> in_iter(cin);
//    istream_iterator<int> in_eof;
//    vector<int> vi;
//
//    while(in_iter != in_eof)
//        vi.push_back(*in_iter++);
//
//    sort(vi.begin(),vi.end());
//    ostream_iterator<int> out_iter(cout," ");
//    copy(vi.begin(),vi.end(),out_iter);
//   // cout << endl;
//
//   return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	istream_iterator<int> int_it(cin), int_eof;
//
//	copy(int_it, int_eof, back_inserter(v));
//	sort(v.begin(), v.end(),[](int a ,int b){return a < b ; });
//
//	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
//	cout << endl;
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> vec;
	istream_iterator<int> int_it(cin), eof;
	while (int_it != eof)
		vec.push_back(*int_it++);
	sort(vec.begin(), vec.end()); //如果写成vec.cbegin(),vec.cend()报错，因为vec排序后被改变了 
	ostream_iterator<int> out_iter(cout, "/t");
	copy(vec.cbegin(), vec.cend(), out_iter);
	cout << endl;
	return 0;
}