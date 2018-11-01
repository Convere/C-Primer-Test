#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
	friend istream &read(istream&is, Sales_data&item);              //友元函数的声明，用于使相关函数调用private对象
	friend ostream &print(ostream&os, const Sales_data&item);
	friend Sales_data add(const Sales_data&lhs, const Sales_data&rhs);
	friend istream& operator >> (std::istream &in, Sales_data &temp);
	friend ostream& operator<<(std::ostream &out, const Sales_data &temp);
public:
	//构造函数
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s), units_sold(0), revenue(0) {}
	Sales_data(istream &);
	string isbn() const { return bookNo; }   //函数isbn在类中的声明与定义，其返回对应的bookNo
	Sales_data& combine(const Sales_data&);  //函数combine在类中的声明，用于将括号中的类与其主类的数值相加
	double avg_price() const;                //函数avg_price在类中的声明，用于计算某类中的商品价格平均值
											 //构造函数即以上
	Sales_data &operator+=(const Sales_data &);
	Sales_data &operator=(const string &ISBN);
	explicit operator string() const { return bookNo; }
	explicit operator double() const { return avg_price(); }
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data &Sales_data::operator=(const string &ISBN)
{
	(*this).bookNo = ISBN;
	return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &temp)
{
	units_sold += temp.units_sold;
	revenue += temp.revenue;
	return *this;
}

istream& operator >> (std::istream &in, Sales_data &temp)
{
	double price = 0;
	in >> temp.bookNo >> temp.units_sold >> price;
	if (in)
		temp.revenue = price*temp.units_sold;
	else
		temp = Sales_data();
	return in;
}
ostream& operator<<(std::ostream &out, const Sales_data &temp)
{
	out << "上一批书的编号为：" << temp.isbn() << " 销量为：" << temp.units_sold << " 总价为：" << temp.revenue << " 平均价格为：" << temp.avg_price() << endl;
	return out;
}
Sales_data operator+(const Sales_data&lhs, const Sales_data&rhs)
{
	Sales_data sum = lhs;
	sum = sum + rhs;
	return sum;
}

Sales_data add(const Sales_data&lhs, const Sales_data&rhs)  //非类成员函数add的定义，用于将二类中的数据加入一类中，然后返回一类的值
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream&os, const Sales_data&item)  //非类成员函数print的定义，用于输出某类中的isbn号（bookNo）,单价，总价以及平均价格
{
	os << "上一批书的编号为：" << item.isbn() << " 销量为：" << item.units_sold << " 总价为：" << item.revenue << " 平均价格为：" << item.avg_price() << endl;
	return os;
}

istream &read(istream&is, Sales_data&item)  //非类成员函数read的定义，用于将输入流中的编号，销量，单价，并计算出总价，然后返回数据到类中
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

Sales_data::Sales_data(istream &is)  //istream为参数的构造函数
{
	read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs) //类成员函数combine的定义，其类型为Sales_data的类类型
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const  //成员函数avg_price的定义，其类型为double的数据类型，返回值直接为商品单价
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}