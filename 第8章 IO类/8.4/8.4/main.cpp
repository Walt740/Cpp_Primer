//#include <iostream>
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	//ostream os;
//	//os << "Please  enter a value: ";
//	cout << unitbuf;	  //������������󶼻�����ˢ�»�����
//	cout << "hi" << ends; //
//	cout << "hi" << flush;
//	cout << "hi" << endl;
//	cout << nounitbuf;   //�ص������Ļ��巽ʽ
//
//
//	cin.tie(&cout);
//
//	return 0;
//}   

//#include <ios>
//#include <iostream>
//
//int main()
//{
//	using namespace std;
//	int i;
//	cin.tie(&cout);
//	cout << "Enter a number:";
//	cin >> i;
//}

//8.4��д�������Զ�ģʽ��һ���ļ����������ݶ��뵽һ��string��vector�У�
//��ÿһ����Ϊһ��������Ԫ�ش���vector��

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream in("../8.4.sln");  //���ļ�
	if (!in)
	{
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}
	string line;
	vector<string> words;
	while (getline(in, line))
	{
		words.push_back(line);//��ӵ�vector��
	}
	in.close();//�ر��ļ�
	//vector<string>::const_iterator it = words.begin();//������
	//while (it != words.end())
	//{
	//	cout << *it << endl;
	//	++it;
	//}
	for (string it : words)
		cout << it << endl;
	return 0;


}



