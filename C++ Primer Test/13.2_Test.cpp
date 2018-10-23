/*#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>
#include <memory>
using namespace std;

class HasPtr  //模板类    练习13.23
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}   //接受一个字符串的默认构造函数
	HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) {}  //拷贝构造函数 
	HasPtr& operator=(const HasPtr &rhs)  //拷贝赋值运算符=的构造函数  
	{
		string *p = new string(*rhs.ps);
		delete ps;
		ps = p;
		i = rhs.i;
		return *this;
	}
	~HasPtr()  //练习13.10  //析构函数
	{
		delete ps; //必须delete对象ps，因为其是new的动态内存，需要手动释放
	}
	string *ps;
	int i;
}; 

class StrBlob  //练习13.26 主要是加了拷贝构造函数和拷贝赋值运算符
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob() : data(make_shared<vector<string>>()) {} //默认的空构造函数
	StrBlob(initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}  //默认构造函数，接受一个list<string>的输入

	StrBlob(const StrBlob &temp) :data(make_shared<vector<string>>(*temp.data)) { cout << "拷贝构造函数" << endl; }  //拷贝构造函数
	StrBlob &operator=(const StrBlob &temp) //拷贝赋值运算符
	{
		data = make_shared<vector<string>>(*temp.data);
		cout << "拷贝赋值运算符" << endl;
		return *this;
	}

	//以下为三个功能函数的定义
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string& front() const;
	string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
	shared_ptr<vector<string>>check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

string& StrBlobPtr::deref() const  //解引用
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()  //递增
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();  //调查wptr是否还存在
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this, 0);
}


StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

int main(int argc, char**argv)
{
	ifstream in("input_line.txt");
	string word;
	StrBlob a,b;
	while (getline(in, word))
		b.push_back(word);
	a = b;
	StrBlob c(a);
	for (StrBlobPtr pbeg(a.begin()), pend(a.end()); pbeg != pend; pbeg.incr())
		cout << pbeg.deref() << endl;
	return 0;
}*/