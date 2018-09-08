/*#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()   //练习1.23与1.24
{
	Sales_item input, total;
	int add = 1;
	if (cin >> total)
	{
		while (cin >> input)
		{
			if (input.isbn() == total.isbn())
				add++;
			else
			{
				cout << "ISBN为 " << total.isbn() << " 的书籍销售记录共有 " << add << " 条" << endl;
				add = 1;
				total = input;
			}
		}
		cout << "ISBN为 " << total.isbn() << " 的书籍销售记录共有 " << add << " 条" << endl;
	}
	else
	{
		cerr << "No Data!" << endl;
		return -1;
	}
	return 0;
}*/