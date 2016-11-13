#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int main()
{
//    vector<string> roster1{"yinhao.zheng","xuewen.li"};
//    vector<string> roster2{"yinhao.zheng","xuewen.li"};

    string roster1{"zhengyinhao"};
    string roster2{"zheng"};
//
//     const char* roster1 = {"zhengyinhao"};
//     const char* roster2 = {"zhengyinhao"};
    cout << equal(roster1.begin(),roster1.end() ,roster2.begin())<< endl;
    //cout << equal(roster1,roster1+2,roster2)<<endl;



    int ia[] = {27120};




    return 0;
}


/*
*练习10.5
*2015/8/11
*问题描述：练习10.5：在本节对名册（roster）调用equal的例子中，如果连个名册中保存的都是C风格字符串而不是string会发生什么？
*说明：如果写成 char * 会发出警告，表示字符串可以修改，而例子中的字符串不允许修改，更好的方法是写成const char *;
*作者：Nick Feng
*邮箱：nickgreen23@163.com
*/

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    const char *s1 = "good";
//    const char *s2 = "boy";
//    vector<const char *> roster1, roster2;
//    roster1.push_back(s1);
//    roster1.push_back(s2);
//    roster2.push_back(s1);
//    roster2.push_back(s2);
//
//    bool flag = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
//
//    if(true == flag)
//        cout << "same..." << endl;
//    else
//        cout << "not same..." << endl;
//
//    return 0;
//}
