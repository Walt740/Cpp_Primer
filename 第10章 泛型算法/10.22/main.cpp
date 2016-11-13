#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::string;
using namespace std::placeholders;
using namespace std;


bool check_size(const string& s,size_t sz)
{
    return s.size() >= sz;
}

int main()
{
    vector<string> vs{"zhengyinhao","c++ primer","c++ STL"};
    int sz = 6;
    //lambda���ʽʵ��
    //find_if(vs.begin(),vs.end(),[=](const string& s){ return s.size()<= sz;});
    //bind����ʵ��
    //auto wc = find_if(vs.begin(),vs.end(),bind(check_size,_1,sz));
    auto fuc = bind(check_size,_2,_1);
    cout << fuc(6,"yinhao") <<endl;


    auto wc = find_if(vs.begin(),vs.end(),bind(check_size,_1,8));

    for(auto iter = wc; iter!= vs.end();iter++)
       cout << *iter << endl;
    cout << endl;

//    ostream os;
//    for_each(words.begin(),words.end(),
//             [&os,c](const string &s){ os << s << c;});
//
//    for_each(words.begin(),words.end(),
//             bind(print,ref(os),_1,' '));
    return 0;
}




//#include <iostream>
//#include <functional>
//
//// �Զ����һ������
//double my_divide (double x, double y) {return x/y;}
//// �Զ����һ���ṹ��
//struct MyPair {
//  double a,b;
//  double multiply() {return a*b;}
//};
//
//int main () {
//  // ���using��Ϊ��ʹ�� _1, _2, _3,...
//  using namespace std::placeholders;
//
//  // ������:
//  auto fn_five = std::bind (my_divide,10,2); // ���� 10/2
//  std::cout << fn_five() << '\n'; // ��� 5
//
//  auto fn_half = std::bind (my_divide,_1,2); // ���� x/2
//  std::cout << fn_half(10) << '\n'; // ��� 5
//
//  auto fn_invert = std::bind (my_divide,_2,_1); // ���� y/x
//  std::cout << fn_invert(10,2) << '\n'; // ��� 0.2
//
//  auto fn_rounding = std::bind<int> (my_divide,_1,_2); // ���� int(x/y)
//  std::cout << fn_rounding(10,3) << '\n'; // ��� 3
//
//  MyPair ten_two {10,2};
//
//  // �����Ա����:
//  auto bound_member_fn = std::bind (&MyPair::multiply,_1); // ���� x.multiply()
//  std::cout << bound_member_fn(ten_two) << '\n'; // ��� 20
//
//  auto bound_member_data = std::bind (&MyPair::a,ten_two); // ���� ten_two.a
//  std::cout << bound_member_data() << '\n'; // ��� 10
//
//  return 0;
//}








