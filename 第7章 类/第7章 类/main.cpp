#include <iostream>
#include "Sales_data.h"


using namespace std;

int main()
{
    cout << "�����뽻�׼�¼��ISBN����������ԭ�ۣ�ʵ���ۼۣ���" << endl;
	Sales_data total;  // ������һ�����׼�¼�ı���
	//�����һ�����׼�¼����ȷ����Ч���ݿ��Դ���
	if (cin >> total)
	{
		Sales_data trans; // ����͵ı���
		while(cin >> trans)
		{
			//����������ڴ�����ͬ����
			if (total.isbn() == trans.isbn())
				total += trans; //���������ۺ�
			else
			{
				//��ӡǰһ����Ľ��
				cout << total << endl;
				total = trans;  //total���ڱ�ʾ��һ��������۶�
			}
		}
		cout << total << endl; //��ӡ���һ����Ľ��
	}
	else
	{
		//û�����룡�������
		cerr << "No data ?!" << endl;
		return -1; //��ʾʧ��
	}
	return 0;

}



