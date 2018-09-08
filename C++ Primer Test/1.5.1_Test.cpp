/*#include <iostream>
using namespace std;
#include "Sales_item.h"

/*int main()
{
	Sales_item book;
	cin >> book;
	cout << book << endl;
	system("PAUSE");
	return 0;
}*/

/*int main()
{
	Sales_item item1, item2, item3;
	cin >> item1 >> item2 >> item3;
	cout << item1 + item2 + item3 << endl;
	system("PAUSE");
	return 0;
}

int main()
{
	Sales_item item1, item2;

	std::cin >> item1 >> item2;
	// first check that item1 and item2 represent the same book
	if (item1.isbn() == item2.isbn()) {
		std::cout << item1 + item2 << std::endl;
		return 0;   // indicate success
	}
	else {
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return -1;  // indicate failure
	}
}*/

/*int main()   //练习1.22
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