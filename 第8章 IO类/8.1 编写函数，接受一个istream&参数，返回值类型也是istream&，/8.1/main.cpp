#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

//int main()
//{
//	int ival;
//	while(cin >> ival)
//		cout << "��д�ɹ���" <<endl;
//	cout << "��дʧ�ܣ�" << endl;
//	return 0;
//}

istream& func(istream& in)
{
	string v;
	/****************************************************************************************
		int iVal;
		cin >> iVal;
		��������ڱ�׼�����ϼ���Boo,�������ͻ�ʧ�ܡ������е�����������ڴ���ȡһ��int��
		��ȴ�õ���һ���ַ�B��������cin��������״̬�����Ƶģ������������һ���ļ�������ʶ��cin
		Ҳ��������״̬��
	****************************************************************************************/
	while (in >> v, !in.eof())
	{
		if (in.bad())
			throw runtime_error("IO������");
		if(in.fail()){
			cerr << "���ݴ���������:" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
		in.clear();
		return in;
}

istream& f(istream& is)
{
	string num;
	while(is>>num,!is.eof())
	{
       // is >> num;
		if (is.bad())
			throw runtime_error("IO������");
		if (is.fail())
		{
			cout << "�������ݴ���������..." << endl;
			is.clear(); //������������е�״̬λ
			is.ignore(100, '\n');  //�������е�Ԫ�� ��ǰ100��Ԫ������'\n' ,����'\n'�������ǰ100��
								   // ����'\n'�������'\n'ǰ��Ԫ��
			continue;
		}	
	    cout << num << endl;
		
	}//while (!is.eof());
	is.clear();
	return is;
}




int main() 
{
//	cout << "������һЩ��������Ctrl+Z����" << endl;
	ostringstream msg;
	msg << "C++ Primer �����" << endl;
	istringstream in(msg.str());
	
	f(in);
	return 0;
}