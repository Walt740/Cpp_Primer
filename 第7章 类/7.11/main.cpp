#include <iostream>
#include "Sales_data.h"


using namespace std;

//int main()
//{
//	Sales_data data1;
//	Sales_data data2("978-7-121-15535-2");
//	Sales_data data3("978-7-121-15535-2",100,128,109);
//	Sales_data data4(cin);
//
//	cout << "�鼮����������ǣ� " << endl;
//	cout << data1 <<"\n"<< data2 << "\n" << data3 << "\n" << data4 << endl;
//	return 0;
//}



int main()
{
	cout << "�����뽻�׼�¼��ISBN����������ԭ�ۣ�ʵ���ۼۣ���" << endl;
	Sales_data total(cin);  // ������һ�����׼�¼�ı���
					   //�����һ�����׼�¼����ȷ����Ч���ݿ��Դ���
	if (cin)
	{
		Sales_data trans(cin); // ����͵ı���
		do//while (cin) 
		{
			//����������ڴ�����ͬ����
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				//��ӡǰһ����Ľ��
				print(cout, total);
				cout << endl;
				total = trans;  //total���ڱ�ʾ��һ��������۶�
			}
		} while ( read(cin,trans) );
		print(cout, total); //��ӡ���һ����Ľ��
	}
	else
	{
		//û�����룡�������
		cerr << "No data ?!" << endl;
		return -1; //��ʾʧ��
	}
	return 0;

}




