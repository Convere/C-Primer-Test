//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//#include "Sales_data.h"
//using namespace std;
//
//class out_of_stock :public runtime_error
//{
//public:
//	explicit out_of_stock(const string &s) :runtime_error(s) {}
//};
//class isbn_mismatch :public logic_error
//{
//public:
//	explicit isbn_mismatch(const string &s) :logic_error(s) {}
//	isbn_mismatch(const string &s, const string &lhs, const string &rhs) :logic_error(s), left(lhs), right(rhs) {}
//	const string left, right;
//};
//
//Sales_data &Sales_data::operator+=(const Sales_data &rhs)
//{
//	if (isbn() != rhs.isbn())
//		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}
//
//int main()
//{
//	Sales_data item1, item2, sum;
//	while (cin >> item1 >> item2)
//	{
//		try
//		{
//			auto sum = item1;
//			sum += item2;
//			//此处使用sum
//		}
//		catch (const isbn_mismatch &e)
//		{
//			cerr << e.what() << ":left isbn(" << e.left << ")right isbn(" << e.right << ")" << endl;
//		}
//	}
//}