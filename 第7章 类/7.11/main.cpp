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
//	cout << "书籍的销售情况是： " << endl;
//	cout << data1 <<"\n"<< data2 << "\n" << data3 << "\n" << data4 << endl;
//	return 0;
//}



int main()
{
	cout << "请输入交易记录（ISBN，销售量，原价，实际售价）：" << endl;
	Sales_data total(cin);  // 保存下一条交易记录的变量
					   //读入第一条交易记录，并确保有效数据可以处理
	if (cin)
	{
		Sales_data trans(cin); // 保存和的变量
		do//while (cin) 
		{
			//如果我们仍在处理相同的数
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				//打印前一本书的结果
				print(cout, total);
				cout << endl;
				total = trans;  //total现在表示下一本书的销售额
			}
		} while ( read(cin,trans) );
		print(cout, total); //打印最后一本书的结果
	}
	else
	{
		//没有输入！警告读者
		cerr << "No data ?!" << endl;
		return -1; //表示失败
	}
	return 0;

}




