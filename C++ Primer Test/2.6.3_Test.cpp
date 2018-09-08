/*#include <iostream>
#include <string>
using namespace std;

struct Sales_data  //练习2.42
{
	string bookNo;
	unsigned units_sold;
	double revenue;
};

int main()
{
	Sales_data total;
	double price;
	if (cin >> total.bookNo >> total.units_sold >> price)
	{
		total.revenue = total.units_sold*price;
		Sales_data add;
		while (cin >> add.bookNo >> add.units_sold >> price)
		{
			add.revenue = add.units_sold*price;
			if (add.bookNo == total.bookNo)
			{
				total.revenue += add.revenue;      //汇总销售总价与销量
				total.units_sold += add.units_sold;
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