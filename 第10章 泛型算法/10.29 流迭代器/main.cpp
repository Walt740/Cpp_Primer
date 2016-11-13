#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc,char* argv[] )
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "�������ļ�ʧ�ܣ�" << endl;
    }
    istream_iterator<string> in_iter(in);
    istream_iterator<string> in_eof;
    ostream_iterator<string> out_iter(cout," ");
    vector<string> vs;

    while(in_iter != in_eof)
        vs.push_back(*in_iter++);

    copy(vs.cbegin(),vs.cend(),out_iter);
    cout << endl;

    return 0;
}
