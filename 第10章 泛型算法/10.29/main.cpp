#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> int_it(cin); //从cin读取int
    istream_iterator<int> int_eof();  // 尾后迭代器
    ifstream in("afile");
    istream_iterator<string> str_it(in); //从"afile"读取字符串
    istream_iterator<int> in_iter(cin); //从cin读取int
    istream_iterator<int> eof;
    while(in_iter != eof)
    //后置递增运算读取流，返回迭代器的旧值
    //解引用迭代器，获得从流读取的前一个值
        vec.push_back(*in_iter++);

    istream_iterator<int> in_iter(cin),eof;
    vector<int> vec(in_iter,eof); //从迭代器范围构造vec
    return 0;
}
