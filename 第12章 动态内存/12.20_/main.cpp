#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream in;
	in.open("../11.txt");  //���ļ�
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



