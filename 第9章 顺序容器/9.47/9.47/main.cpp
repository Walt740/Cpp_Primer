#include <iostream>
#include <string>

using namespace std;

//int main()
//{
////    string name("AnnaBelle");
////    auto pos1 = name.find("0nna");
////    cout << pos1 << endl;
//
//    string number("0123456789"),name("r2d2");
//    //查找与给定字符串中任何一个字符匹配的位置
//    auto pos = name.find_first_of(number);
//    cout << pos << endl;
//    //搜索第一个不在参数中的字符
//    string dept("012");
//    //auto pos1 = dept.find_first_not_of(number);
//    auto pos1 = dept.find(number);
//    cout << pos1 << endl;
//    const char* ch = "zhynj.yinhao";
//    string name1("abcdefgabc");
//    auto posi = name1.find_last_of("dds");
//    cout << posi <<endl ;
//
//    cout << name1.find_first_not_of("abc")<<endl;
//    cout << name1.find_last_not_of("abc")<<endl;
//
//    cout << name1.find_first_of(ch,0,5);
//
//
//    return 0;
//}






int main()
{
    string number("0123456789");
    string name("walt740");
    string:: size_type pos = 0;
    //每步循环查找name中下一个数
//    while((pos = name.find_last_of(number,pos))!= string::npos )
//    {
//        cout << "found number at index: " << pos
//             << " element is " << name[pos] <<endl ;
//        pos++;
//
//    }

	auto posi = name.find_last_not_of(number, 3);
    cout << posi  << endl ;

    return 0 ;
}
