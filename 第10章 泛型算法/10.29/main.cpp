#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> int_it(cin); //��cin��ȡint
    istream_iterator<int> int_eof();  // β�������
    ifstream in("afile");
    istream_iterator<string> str_it(in); //��"afile"��ȡ�ַ���
    istream_iterator<int> in_iter(cin); //��cin��ȡint
    istream_iterator<int> eof;
    while(in_iter != eof)
    //���õ��������ȡ�������ص������ľ�ֵ
    //�����õ���������ô�����ȡ��ǰһ��ֵ
        vec.push_back(*in_iter++);

    istream_iterator<int> in_iter(cin),eof;
    vector<int> vec(in_iter,eof); //�ӵ�������Χ����vec
    return 0;
}
