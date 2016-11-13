
#include "Example.h"


//class Account
//{
//public:
//    static double rate(){return interestRate;}
//    static void rate(double);
//
//private:
//    string strName;
//    double dAmount = 0.0;
//    static double dRate;   //����������ȶ���ͳһ�ģ�Ӧ���Ǿ�̬��Ա
//};

//double Example::rate;
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
 int main(){

     Example::vec.push_back(10.5);
     cout << Example::vec.back() << endl;
     cout << Example::rate << endl;
     cout << Example::vecSize << endl;
     return 0;
 }


 
 /*
 һ����˵������C++�ྲ̬��Ա�ĳ�ʼ�������������˸е�������⣬�����ᵽC++ ��̬��Ա��"���ڳ�ʼ��"�Ǿ������Ժ��ˡ�

�����������´��룺

���ƴ���
 1 //example.h
 2 #include<iostream>
 3 #include<vector>
 4 using namespace std;
 5 
 6 class Example{
 7 public:
 8     static double rate = 6.5;
 9     static const int vecSize = 20;
10     static vector<double> vec(vecSize);
11 };
12 
13 //example.cpp
14 #include "example.h"
1516 double Example::rate;
17 vector<double> Example::vec;
18
���ƴ���
������Ҫ�ж�����ľ�̬���ݳ�Ա�������Ͷ�����û�д��󣬲�����ԭ��

���ȣ�Ҫ���ǣ�ͨ������£���Ӧ�������ڲ���ʼ����Ա�������Ƿ�Ϊ��̬��Ա��

��Σ���һ��Ҫ�����ڳ�ʼ����̬��Ա����ô�ͱ������������������У�

1�� ��̬��Ա����Ϊ����ֵ�������͵�constexpr��

      ��ν������ֵ���;���ͨ�������ģ��������ͣ����ã�ָ��ȡ�����ֵ�������;���const�͵��������ͣ����ã�ָ��ȡ�

      ��ν��constexpr�����ǳ������ʽ��ֵָ����ı����ڱ�������о��ܵõ��������ı��ʽ����������ֵ�������ó������ʽ��ʼ����const����Ҳ�ǳ������ʽ��Ϊ�˰����û�����Լ�����/����ı�����ֵ�Ƿ�Ϊһ���������ʽ��C++11�¹涨��������������Ϊconstexpr���ͣ��Ա��ɱ�������������֤�����Ƿ�Ϊ�������ʽ��

2������̬��Ա�ṩ�ĳ�ʼֵ������Ϊ�������ʽ

ע�⣺��C++ primer �������˵��ֻ�ܸ���̬��Ա�ṩconst �������͵����ڳ�ʼֵ���Ҹ�const�������͵ĳ�ʼֵ�����ǳ������ʽ���Ҿ���������ģ���������������

 

����������ԭ�����ǾͿ��Զ�����Ĵ��������֤�ˡ�

1��static double rate = 6.5; 

��Ȼ�������һ������Ϊrate���ǳ������͡��ĳ�constexprt static const double rate = 6.5����

������Ҳ���Կ�����ʼֵ��һ������Ϊconst �������͡�

ps: ������ǲ����������constexprt���η��Ļ�������������ʾ����error: ��constexpr�� needed for in-class initialization of static data member ��const double Example::rate�� of non-integral type [-fpermissive] 
������˼���ǣ����ڷ�const�������͵ĳ�ʼֵ��������ǳ������ʽ�Ļ���������Ҫ�ֹ���ǰ��������η�constexprt��

����Example.cpp�ļ��еĶ��岿�֣����������Ѿ������ڲ������˳�ʼ�����Ͳ���Ҫ�������ⲿ���ж����ˡ������Ҫ����Ļ�������������¸�ʽ��

//example.cpp
constexpr const double Example::rate;  //���е�const�ǿ���ɾ���ģ���Ϊconstexprt����Ͱ�����const

2��static const int vecSize = 20;

vecSize��const int���͵ģ���Ϊ�������ʽ���������һ�����ṩ�ĳ�ʼֵΪ20����һ���������ʽ��������ڶ�������������const int�͵ģ�ǰ����Բ������η�constexpr��

3��static vector<double> vec(vecSize);

����vector��ģ�岻������ֵ�������ͣ����Բ������һ����Ӧ�ø�Ϊ static vector<double> vec; //������ֻ�ܽ������������ܶ���

Ȼ����Example.cpp�н��ж��壺

static vector<double> vec(Example::vecSize);

�������ǿ�����Example.cpp����Ӳ��Դ�����в����ˣ�

 

���ƴ���
 1 #include "example.h"
 2 vector<double> Example::vec(Example::vecSize);
 3 constexpr const double Example::rate;
 4 
 5 int main(){
 6 
 7     Example::vec.push_back(10.5);
 8     cout << Example::vec.back() << endl;
 9     cout << Example::rate << endl;
10     cout << Example::vecSize << endl;
11 }
���ƴ���
 

 

ִ�н����

 

wanchouchou@wanchouchou-virtual-machine:~/c++/7.5$ ./Example 
10.5
6.5
20
 */