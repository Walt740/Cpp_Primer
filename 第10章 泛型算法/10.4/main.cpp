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
*��ϰ10.4
*2015/8/11
*������������ϰ10.4���ٶ�v��һ��vector<double>����ô����accmulate(v.cbegin(),v.cend(),0)�кδ���������ڵĻ���?
*˵���������е�Ԫ�ص����ͱ��������������ƥ�䣬�����ܹ�ת��Ϊ���������������͡���ˣ����ڴ˴���0��Ԫ���е�Ԫ��ת��Ϊint�ͣ����ռ�������int�͡�
*���ߣ�Nick Feng
*���䣺nickgreen23@163.com
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
    double sum = accumulate(v.cbegin(), v.cend(), 0.0);//��ȷд��
    cout << "Sum of the vector is: " << sum << endl;
    return 0;
}
