#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <set>
#include <memory>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) { cout << "Quote参数构造函数" << endl; }
	string isbn() const { return bookNo; }
	//返回给定数量的书籍的销售总额，而派生类改写此函数用于不同折扣的算法中
	virtual double net_price(size_t n) const { return n*price; }

	Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {cout << "Quote拷贝构造函数" << endl;}

	Quote& operator=(const Quote &rhs) 
	{
		cout << "Quote拷贝赋值运算符" << endl;
		price = rhs.price;
		bookNo = rhs.bookNo;
		return *this;
	}

	Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {cout << "Quote移动构造函数" << endl;}

	Quote& operator=(Quote &&rhs) noexcept 
	{
		cout << "Quote移动赋值运算符" << endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move((*this))); }
	virtual ~Quote() { cout << "Quote析构函数" << endl; };  
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
	Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) { cout << "Disc_quote参数默认构造函数" << endl; }
	double net_price(size_t n) const = 0;
protected:
	size_t min_qty = 0;   //折扣的最低购买量
	double discount = 0.0;   //折扣额度
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	//此派生类的构造函数，调用Quote抽象基类
	Bulk_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) { cout << "Bulk_quote参数默认构造函数" << endl; }
	Bulk_quote(const Bulk_quote &rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "Bulk_quote拷贝构造函数" << endl; }

	Bulk_quote& operator=(const Bulk_quote &rhs)
	{
		cout << "Bulk_quote拷贝赋值运算符" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}

	Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)) { cout << "Bulk_quote移动构造函数" << endl; }

	Bulk_quote& operator=(Bulk_quote &&rhs) noexcept
	{
		cout << "Bulk_quote移动赋值运算符" << endl;
		Quote::operator=(rhs);
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}

	virtual Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	virtual Bulk_quote* clone() && { return new Bulk_quote(std::move((*this))); }
	virtual ~Bulk_quote() { cout << "Bulk_quote析构函数" << endl; };

	//覆盖基类中的价格计算函数版本
	double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
protected:
	size_t min_qty = 0;   //折扣的最低购买量
	double discount = 0.0;   //折扣额度
};

class Other_quote : public Quote
{
public:
	Other_quote() = default;
	//此派生类的构造函数，调用Disc_quote抽象基类
	Other_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) { cout << "Other_quote参数默认构造函数" << endl; }

	Other_quote(const Other_quote &rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "Other_quote拷贝构造函数" << endl; }

	Other_quote& operator=(const Other_quote &rhs)
	{
		cout << "Other_quote拷贝赋值运算符" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}

	Other_quote(Other_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)) { cout << "Other_quote移动构造函数" << endl; }

	Other_quote& operator=(Other_quote &&rhs) noexcept
	{
		cout << "Other_quote移动赋值运算符" << endl;
		Quote::operator=(rhs);
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}

	virtual ~Other_quote() { cout << "Other_quote析构函数" << endl; };

	//覆盖基类中的价格计算函数版本
	double net_price(size_t cnt) const override
	{
		if (cnt <= min_qty)
			return cnt*(1 - discount)*price;
		else
			return (min_qty*(1 - discount)*price + (cnt - min_qty)*price);
	}
protected:
	size_t min_qty = 0;   //折扣的最低购买量
	double discount = 0.0;   //折扣额度
};

class Basket
{
public:
	void add_item(const Quote &sale) { items.insert(shared_ptr<Quote>(sale.clone())); }   //左值添加
	void add_item(Quote &&sale) { items.insert(shared_ptr<Quote>(std::move(sale.clone()))); }  //右值添加
	void add_item(const shared_ptr<Quote> &sale) { items.insert(sale); }    //问题的关键在于输入的sale类型的适应
	//void add_item(const Quote &sale) { items.insert (make_shared<Quote>(sale)); }
	double total_receipt(ostream &) const;
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

//计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # solid: " << n << " total due: " << ret << endl;
	return ret;
}

double Basket::total_receipt(ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
		sum += print_total(os, **iter, items.count(*iter));
	os << "总价格为： " << sum << endl;
	return sum;
}
