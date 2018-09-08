/*#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()   //练习1.25 与练习1.22相同
{
	Sales_item add, total;
	if (cin >> total)
	{
		while (cin >> add)
		{
			if (add.isbn() == total.isbn())
				total += add;
			else {
				cout << "上一批ISBN书籍为" << total << endl;
				total = add;
			}
		}
		cout << "最后一批ISBN书籍为" << total << endl;
	}
	else {
		cerr << "No Data" << endl;
		return -1;
	}
	return 0;
}*/