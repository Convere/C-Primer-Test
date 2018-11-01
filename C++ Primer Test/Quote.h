#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <istream>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; }
	//返回给定数量的书籍的销售总额，而派生类改写此函数用于不同折扣的算法中
	virtual double net_price(size_t n) const { return n*price; }
	virtual ~Quote() = default;  //对析构函数进行动态绑定
	virtual void debug() { cout << "书的ISBN编号为： " << bookNo << " 书的原价为： " << price << endl; }
private:
	string bookNo;   //书的ISBN编号
protected:
	double price = 0.0;    //基类状态下，不打折的价格初始量
};

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) {}
	double net_price(size_t n) const = 0;
protected:
	size_t min_qty = 0;   //折扣的最低购买量
	double discount = 0.0;   //折扣额度
};



class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	//此派生类的构造函数，调用Disc_quote抽象基类
	Bulk_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
	//覆盖基类中的价格计算函数版本
	double net_price(size_t cnt) const override
	{
		if (cnt > min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
};

class Other_quote :public Disc_quote
{
public:
	Other_quote() = default;
	Other_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
	double net_price(size_t cnt) const override
	{
		if (cnt < min_qty)
			return cnt*(1 - discount)*price;
		else
			return (min_qty*(1 - discount)*price + (cnt - min_qty)*price);
	}
};

//计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # solid: " << n << " total due: " << ret << endl;
	return ret;
}
