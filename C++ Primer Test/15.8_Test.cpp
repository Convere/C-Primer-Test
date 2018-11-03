//#include <iostream>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//#include "Quote.h"
//using namespace std;
//
//int main()   //练习15.28与15.29与练习15.30
//{
//	vector<Quote> save;
//	Bulk_quote bb1("Light", 100, 10, 0.25);
//	Bulk_quote bb2("Night", 75, 10, 0.25);
//	Bulk_quote bb3("Right", 50, 10, 0.25);
//	//save.push_back(bb1);
//	//save.push_back(bb2);
//	//save.push_back(bb3);
//	//for (auto &s : save)
//	//	print_total(cout, s, 15);   //结果全是原价乘以销量，因为派生类的部分被切掉了，只有bookNo和price
//	//cout << endl;
//	//vector<shared_ptr<Quote>> save2;
//	//save2.push_back(make_shared<Bulk_quote>(bb1));
//	//save2.push_back(make_shared<Bulk_quote>(bb2));
//	//save2.push_back(make_shared<Bulk_quote>(bb3));
//	//for (auto &s : save2)
//	//	print_total(cout, *s, 15);   //容器中对象为指向bulk_quote类型的指针，所以调用时折扣有用
//
//	cout << endl;
//
//	Basket all;
//	for(int i=0;i<15;i++)
//		all.add_item(bb1);
//	all.add_item(bb1);
//	all.add_item(bb2);
//	all.add_item(bb3);
//	all.total_receipt(cout);
//}