#include <vector>
#include <string>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>  
#include <algorithm>  
#include <numeric>  
#include <functional>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>
using namespace std;

class String
{
	friend bool operator<(const String &lhs, const String &rhs);
public:
	String() { cout << "默认构造函数调用" << endl; }  //默认构造函数
	String(const char*s)//接受c风格字符串参数的构造函数，s为指向字符串的指针(首位置)
	{
		auto s1 = const_cast<char*>(s);//转化为非常量的指针
		while (*s1)
			++s1;//使其指向最后一个位置的尾部
		auto newdata = alloc_n_copy(s, s1);//进行拷贝
		elements = newdata.first;
		first_free = newdata.second;
		cout << "c风格字符串默认构造函数调用" << endl;
	}
	String(const String&);  //拷贝构造函数的声明
	String &operator=(const String&);  //拷贝赋值运算符的声明
	String(String&& s) noexcept: elements(s.elements), first_free(s.first_free) { s.elements = s.first_free = nullptr; cout << "移动构造函数调用" << endl; } //移动构造函数的声明
	String& operator=(String&&) noexcept;  //移动赋值运算符的声明
	~String() { free(); };  //析构函数的声明

	size_t size() const { return first_free - elements; }  //已用大小的函数声明
	char *begin() const { return elements; }   //指向首元素的指针，类似vector的begin
	char *end() const { return first_free; }	 //指向最后一位元素下一位的指针，类似vector的end
private:
	allocator<char> alloc;  //存放char的未构造内存，用于分配元素
	pair<char*, char*>alloc_n_copy(const char*, const char*); //分配足够的内存来保存给定范围内的元素，并将输入的这些元素保存到新的内存中
	void range_initializer(const char*, const char*);
	void free();			//用于销毁元素并释放内存的函数
	char *elements;		//指向数组首元素的指针
	char *first_free;		//指向数组第一个空闲元素的指针
};

bool operator<(const String &lhs, const String &rhs)
{
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),rhs.end());
}

bool operator>(const String &lhs, const String &rhs)
{
	return rhs < lhs;
}

bool operator==(const String &a, const String &b)
{
	return a.size() == b.size() && equal(a.begin(), a.end(), b.begin());
}

bool operator!=(const String &a, const String &b)
{
	return !(a == b);
}

ostream &operator<<(ostream &out, const String &temp)
{
	for (auto &s : temp)
		out << s;
	out << endl;
	return out;
}

String::String(const String &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cout << "拷贝构造函数调用" << endl;
}

String &String::operator=(const String&s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = newdata.second;
	cout << "拷贝赋值运算符调用" << endl;
	return *this;
}

String& String::operator=(String&& rhs) noexcept
{
	if (this != &rhs) 
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		rhs.elements = rhs.first_free = nullptr;
		cout << "移动赋值运算符调用" << endl;
	}
	return *this;
}

pair<char*, char*>String::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);   //b是string的end指针，e是string的begin指针，其为alloc的分配，data指向分配的新内存的begin
	return{ data,uninitialized_copy(b,e,data) };  //返回指向所分配的内存的begin的指针data，后面的语句将b到e中的数据拷贝到data所指的内存中,并返回指向新内存最后一个元素之后位置的指针，即end
}

void String::range_initializer(const char*a, const char*b)
{
	auto newdata = alloc_n_copy(a, b);
	elements = newdata.first;
	first_free = newdata.second;
}

void String::free()
{
	if (elements)
	{
		//for (auto p = first_free; p != elements;)   //先逆序销毁掉string中所包含的元素
		//alloc.destroy(--p);
		for_each(elements, first_free, [this](char &rhs) { alloc.destroy(&rhs); });//this是指向当前类的指针，从旧内存的开头到结尾，捕获alloc后，destroy指向当前位置所存的元素，rhs为一个指针
		alloc.deallocate(elements, first_free - elements); //释放string所使用的内存（虽然此时删除了元素，但内存还在，其内为空）
	}
}

void foo(String x)  //这里没有用引用，所以会直接赋值
{
	for (auto &s : x)
		cout << s;
	cout << endl;
}

void bar(const String& x)  //这里调用了一次拷贝构造函数
{
	for (auto &s : x)
		cout << s;
	cout << endl;
}

String baz()
{
	String ret("world");
	return ret;
}