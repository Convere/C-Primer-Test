/*#include <iostream>
#include <string>
using namespace std;


struct Sales_data  //练习7.2
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	string isbn() const 
	{ 
		bookNo;
	}
	Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data add;
		while (cin >> add.bookNo >> add.units_sold >> add.revenue)
		{
			if (add.bookNo == total.bookNo)
			{
				total.combine(add);      //调用total类的函数中的combine函数，返回值this返回打total的成员函数中
			}
			else
			{
				cout << "上一批ISBN书籍为" << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << endl;  //输出上一批书籍的信息
				total = add;
			}
		}
		cout << "最后一批ISBN书籍为" << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << endl;   //输出最后一批书籍的信息
	}
	else {
		cerr << "No Data" << endl;
		return -1;
	}
	return 0;
}*/