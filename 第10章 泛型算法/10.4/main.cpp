//#include <iostream>
//#include <vector>
//#include <numeric>
//using namespace std;
//
//int main()
//{
//    vector<double> vd{1.5,2.33,3.1,4.5,5.34,6.223};
//    double sum =  accumulate(vd.cbegin(),vd.cend(),1000.0);
//    cout << sum << endl;
//
//
//
//
//
//    return 0;
//}
/*
*练习10.4
*2015/8/11
*问题描述：练习10.4：假定v是一个vector<double>，那么调用accmulate(v.cbegin(),v.cend(),0)有何错误（如果存在的话）?
*说明：序列中的元素的类型必须与第三个参数匹配，或者能够转换为第三个参数的类型。因此，由于此处是0，元素中的元素转化为int型，最终计算结果是int型。
*作者：Nick Feng
*邮箱：nickgreen23@163.com
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double val;
    vector<double> v;
    cout << "please input numbers..." << endl;
    while(cin >> val)
        v.push_back(val);
    //double sum = accumulate(v.cbegin(), v.cend(), 0);
    double sum = accumulate(v.cbegin(), v.cend(), 0.0);//正确写法
    cout << "Sum of the vector is: " << sum << endl;
    return 0;
}
