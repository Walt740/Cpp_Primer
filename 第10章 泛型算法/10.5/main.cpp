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
*��ϰ10.5
*2015/8/11
*������������ϰ10.5���ڱ��ڶ����ᣨroster������equal�������У�������������б���Ķ���C����ַ���������string�ᷢ��ʲô��
*˵�������д�� char * �ᷢ�����棬��ʾ�ַ��������޸ģ��������е��ַ����������޸ģ����õķ�����д��const char *;
*���ߣ�Nick Feng
*���䣺nickgreen23@163.com
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
