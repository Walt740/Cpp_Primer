//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <algorithm>
//
//using namespace std;
//
//int main(int argc,char* argv[])
//{
//    if(argc != 4)
//    {
//        cout << " �÷���execise.exe in_file out_file1 out_file2" << endl;
//        return -1;
//    }
//
//    ifstream in(argv[1]);
//    if(!in)
//    {
//        cout << "�������ļ�ʧ�ܣ�" <<endl;
//        exit(1);
//    }
//    ofstream out1(argv[2]);
//    if(!out1)
//    {
//        cout << "������ļ�1ʧ�ܣ�" <<endl;
//        exit(1);
//    }
//    ofstream out2(argv[3]);
//    if(!out2)
//    {
//        cout << "������ļ�2ʧ�ܣ�" <<endl;
//        exit(1);
//    }
//
//    //���������������ļ��ж�������
//    istream_iterator <int> in_iter(in);
//    //β�������
//    istream_iterator<int> in_eof;
//    ostream_iterator<int> out_iter1(out1," ");
//    ostream_iterator<int> out_iter2(out2,"\n");
//    while(in_iter != in_eof)
//    {
//        if(*in_iter & 1 )
//            *out_iter1++ = *in_iter;
//        else
//            *out_iter2++ = *in_iter;
//        in_iter++;
//    }
//
//    return 0;
//}



#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv)
{
	if (argc != 4) return -1;

	std::ifstream ifs(argv[1]);
	std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

	std::istream_iterator<int> in(ifs), in_eof;
	std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");

	std::for_each(in, in_eof, [&out_odd, &out_even](const int i)
	{
		*(i & 0x1 ? out_odd : out_even)++ = i;
	});

	return 0;
}
