#include <iostream>
#include "Sales_data.h"


using namespace std;

int main()
{
    cout << "�����뽻�׼�¼��ISBN����������ԭ�ۣ�ʵ���ۼۣ���" << endl;
	Sales_data total;  // ������һ�����׼�¼�ı���
	//�����һ�����׼�¼����ȷ����Ч���ݿ��Դ���
	if (read(cin,total))
	{
		Sales_data trans; // ����͵ı���
		while(read(cin,trans))
		{
			//����������ڴ�����ͬ����
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				//��ӡǰһ����Ľ��
				print(cout,total);
				cout << endl;
				total = trans;  //total���ڱ�ʾ��һ��������۶�
			}
		}
		print(cout,total); //��ӡ���һ����Ľ��
	}
	else
	{
		//û�����룡�������
		cerr << "No data ?!" << endl;
		return -1; //��ʾʧ��
	}
	return 0;

}




