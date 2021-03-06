//#pragma once
//
//#include <string>
//
//class Sales_data
//{
//private:  //定义私有数据成员
//	  std::string bookNo;	//书籍编号，隐式初始化为空串
//	  unsigned units_sold = 0; // 销售量，显式初始化为0
//	  double sellingprice = 0.0; // 原始价格，显式初始化为0.0
//	  double saleprice = 0.0;//实售价格，显式初始化为0.0
//	  double discount = 0.0; //折扣，显式初始化为0.0
//public :	//定义公有函数成员
//	//isbn函数只有一条语句，返回bookNo
//	std::string isbn() const { return bookNo; } 
//	//combine函数用于把两个ISBN相同的销售记录合并在一起
//	Sales_data& combine(const Sales_data &rhs)
//	{
//		units_sold += rhs.units_sold; //累加书籍的销售量
//		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) 
//			/ (rhs.units_sold + units_sold); //重新计算销售价格
//		if (sellingprice)		
//			discount = saleprice / sellingprice; //重新计算实际折扣
//		return *this; //返回合并后的结果
//	}
//	
//};


#pragma once
#include <string>

//struct Sales_data {
//	std::string bookNo;
//	unsigned units_sold = 0;
//	double revenue = 0.0;
//};

class Sales_data
{
	//友元函数
	friend std::istream& operator >> (std::istream&, Sales_data&);
	//友元函数
	friend std::ostream& operator << (std::ostream &, const Sales_data&);
	//友元函数
	friend bool operator < (const Sales_data&, const Sales_data&);
	//友元函数
	friend bool operator == (const Sales_data&, const Sales_data&);


public: // 构造函数的三种形式
	Sales_data() = default;
	Sales_data(const std::string &book) : bookNo(book) {}
	Sales_data(std::istream &is) { is >> *this; }
public: //定义公有成员函数
	Sales_data& operator += (const Sales_data&);
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data & rhs);
	//{
	//	units_sold += rhs.units_sold; //累加书籍的销售量
	//    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) 
	//		/ (rhs.units_sold + units_sold); //重新计算销售价格
	//	if (sellingprice)		
	//		discount = saleprice / sellingprice; //重新计算实际折扣
	//	return *this; //返回合并后的结果
	//}
private:
	std::string bookNo; //书籍编号，隐式初始化为空串
	unsigned units_sold = 0; //销售量，显示初始化为0
	double sellingprice = 0.0; //原始价格，显式初始化为0.0
	double saleprice = 0.0; //实售价格，显式初始化为0.0
	double discount = 0.0; // 折扣，显式初始化为0.0

};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data& rhs)
{
	return lhs.isbn() == rhs.isbn();
}

Sales_data operator + (const Sales_data&, const Sales_data&);

inline bool operator == (const Sales_data& lhs, const Sales_data &rhs)
{
	return lhs.units_sold == rhs.units_sold &&
		lhs.sellingprice == rhs.sellingprice &&
		lhs.saleprice == rhs.sellingprice &&
		lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data&rhs)
{
	return !(lhs == rhs);
}

Sales_data & Sales_data :: operator += (const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	saleprice = (rhs.saleprice * rhs.units_sold + saleprice*units_sold) /
		(rhs.units_sold + units_sold);
	if (sellingprice != 0)
		discount = saleprice / sellingprice;
	return *this;
}

Sales_data operator + (const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data ret(lhs); //把lhs的内容拷贝到临时变量ret中，这种做法便于运算
	ret += rhs; // 把rhs 的内容加入其中
	return ret; //返回ret
}

std::istream& operator >> (std::istream & in, Sales_data & s)
{
	in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
	if (in && s.sellingprice != 0)
		s.discount = s.saleprice / s.sellingprice;
	else
		s = Sales_data();  //输入错误，重置输入的数据
	return in;
}

std::ostream& operator << (std::ostream & out, const Sales_data& s)
{
	out << s.isbn() << " " << s.units_sold << " "
		<< s.sellingprice << " " << s.saleprice << " " << s.discount;
	return out;
}

Sales_data& Sales_data::combine(const Sales_data & rhs) //
{
		units_sold += rhs.units_sold; //累加书籍的销售量
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold)
			/ (rhs.units_sold + units_sold); //重新计算销售价格
		if (sellingprice)
			discount = saleprice / sellingprice; //重新计算实际折扣
		return *this; //返回合并后的结果
}
