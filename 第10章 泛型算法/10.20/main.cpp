//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//
//using namespace std;
//
//void  func3()
//{
//    size_t v1 = 42;
//    auto f = [v1]() mutable
//    {
//        return ++v1;
//    };
//    v1 = 0;
//    auto j = f();
//    cout << j <<endl;
//}
//
//void func4()
//{
//    size_t v1 = 43;
//    auto f2 = [&v1]{return ++v1;};
//    v1 = 0;
//    auto j = f2();
//    cout << j << endl;
//}
//
//
//
//int main()
//{
//    func3();
//    func4();
//
//    vector<int> vi{1,2,-1,-2,-4};
////    transform(vi.begin(),vi.end(),vi.begin(),
////              [](int i){ return i < 0 ?  -i:i;});
////
//
//    transform(vi.begin(),vi.end(),vi.begin(),
//                [](int i )
//              {
//                 if(i>0) return i;
////                 else return -i;
//              });
//
//    for(auto iter = vi.begin(); iter != vi.end();iter++)
//        cout << *iter <<" " ;
//    cout << endl;
//    return 0;
//}





#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string > vs{"yinhao","zheng","okok","hfkdhsf","fdsvcsdyc","dhsf","dsfksd"};
    const size_t sz = 6;
    auto j = count_if(vs.begin(),vs.end(),[=](string& s) { return  s.size() >= sz; });
    cout << j << endl;
    return 0;
}

