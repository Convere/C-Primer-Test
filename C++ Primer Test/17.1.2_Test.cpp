//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <algorithm>  
//#include <istream>
//#include <memory>
//#include <initializer_list>
//#include <tuple>
//#include "Sales_data.h"
//using namespace::std;
//
//bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() < rhs.isbn(); }
////练习17.4
////typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;
////vector<vector<Sales_data>> files;
////vector<matches> findBook(const vector<vector<Sales_data>> &files, string &book)
////{
////	vector<matches> ret;
////	//对每家书店，查找与给定书籍匹配的记录范围
////	for (auto it = files.begin(); it != files.end(); ++it)
////	{
////		auto found = equal_range(it->cbegin(), it->end(), book, compareIsbn);
////		if (found.first != found.second)  //此书店销售了给定书籍
////			//记住此书店的索引及匹配范围
////			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
////	}
////	return ret;
////}
//
////练习17.5
//typedef pair<vector<Sales_data>::size_type,pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches;
//vector<vector<Sales_data>> files;
//vector<matches> findBook(const vector<vector<Sales_data>> &files, string &book)
//{
//	vector<matches> ret;
//	//对每家书店，查找与给定书籍匹配的记录范围
//	for (auto it = files.begin(); it != files.end(); ++it)
//	{
//		auto found = equal_range(it->cbegin(), it->end(), book, compareIsbn);
//		if (found.first != found.second)  //此书店销售了给定书籍
//										  //记住此书店的索引及匹配范围
//			ret.push_back({ it - files.cbegin(), {found.first, found.second} });
//	}
//	return ret;
//}