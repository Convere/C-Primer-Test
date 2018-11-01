//#include <iostream>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <istream>
//using namespace std;
//
//class Quote
//{
//public:
//	Quote() = default;
//	Quote(const string &book,double sales_price):bookNo(book),price(sales_price){}
//	string isbn() const { return bookNo; }
//	//返回给定数量的书籍的销售总额，而派生类改写此函数用于不同折扣的算法中
//	virtual double net_price(size_t n) const { return n*price; }
//	virtual ~Quote() = default;  //对析构函数进行动态绑定
//private:
//	string bookNo;   //书的ISBN编号
//protected:
//	double price = 0.0;    //基类状态下，不打折的价格初始量
//};
//
////计算并打印销售给定数量的某种书籍所得的费用
//double print_total(ostream &os, const Quote &item, size_t n)
//{
//	double ret = item.net_price(n);
//	os << "ISBN: " << item.isbn() << " # solid: " << n << " total due: " << ret << endl;
//	return ret;
//}