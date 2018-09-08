/*#include <iostream>
#include <string>
using namespace std;

struct Sales_data  //练习2.41
{
	string bookNo;
	unsigned units_sold;
	double revenue;
}; 

int main()
{
	Sales_data book1, book2;
	double price = 0;
	cin >> book1.bookNo >> book1.units_sold >> price;  //第一本书信息输入
	book1.revenue = book1.units_sold*price;            //计算第一本书总价
	cin >> book2.bookNo >> book2.units_sold >> price;  //第二本书信息输入
	book2.revenue = book2.units_sold*price;            //计算第二本书总价
	
	if (book1.bookNo == book2.bookNo)
	{
		unsigned totalCnt = book1.units_sold + book2.units_sold;  //两本书的销量之和
		double totalRevenue = book1.revenue + book2.revenue;      //两本书的总价之和
		//输出书本编号、总销售量、总销售价
		cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
			//输出书本平均价格
			cout << totalRevenue / totalCnt << endl;
		else
			cout << "No Sale" << endl;			  //无销售量
		return 0;
	}
	else
		cerr << "两本书的ISBN号不一致！" << endl; //报错
	return -1;
}*/