#include <iostream>  
#include <vector>
#include "String.h"
using namespace std;

int main() //练习13.50   //增加了移动构造函数，	其几乎大量覆盖了原有的拷贝构造函数
{
	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;
	for (auto &s : s1)
		cout << s;
	cout << s1.size() << endl;

	cout << endl;

	foo(s1);
	bar(s1);

	cout << endl;

	foo("temporary");
	bar("temporary");
	String s4 = baz();   //在baz函数调用时，原有的拷贝构造函数均变成了移动构造函数，因为其在返回时为字符串变量变成的右值返回
	String &s5 = baz();
	baz();//baz()初始化一次C风格，然后函数的形参实参转换一次拷贝构造函数

	cout << endl;

	std::vector<String> svec;        //旧内存到新内存的转换过程均变成了移动构造函数，而新数据的读入由于均为左值的变量，所以为拷贝构造
	cout << svec.capacity() << endl;
	svec.push_back(s0);  //新数据读入，调用正常的拷贝构造函数
	cout << svec.capacity() << endl;
	svec.push_back(s1);  //svec内存扩大，旧内存的元素到新内存的移动构造一次；新数据读入，调用正常的拷贝构造函数一次
	cout << svec.capacity() << endl;
	svec.push_back(baz()); //svec内存扩大，旧内存的元素到新内存的移动构造两次；新数据读入，调用正常的拷贝构造函数一次；baz()函数调用一次C一次拷贝构造
	cout << svec.capacity() << endl;
	svec.push_back("good job");  //svec内存扩大，旧内存的元素到新内存的移动构造三次；新数据读入，调用正常的拷贝构造函数一次；good job作为C字符串一次C一次拷贝构造
	cout << svec.capacity() << endl;
	svec.push_back(s1);//svec内存扩大，旧内存的元素到新内存的拷贝移动四次；新数据读入，调用正常的拷贝构造函数一次；
	cout << svec.capacity() << endl;
	svec.push_back(s1);//新数据读入，调用正常的拷贝构造函数一次//因为此时的cap已经变成了6，此数据插入时不需要调整内存大小；
	cout << svec.capacity() << endl;
	svec.push_back(s1);//svec内存扩大，旧内存的元素到新内存的移动构造六次；新数据读入，调用正常的拷贝构造函数一次；
	cout << svec.capacity() << endl;

	for (auto &s : svec)
	{
		for (auto &ss : s)
			cout << ss;
		cout << " " << s.size() << " ";
	}
	cout << endl;
}