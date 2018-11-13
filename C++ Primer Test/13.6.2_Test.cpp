//#include <iostream>  
//#include <vector>
//#include "String.h"
//#include "HasPtr.h"
//using namespace std;
//
//int main() //练习13.50   //增加了移动构造函数，	其几乎大量覆盖了原有的拷贝构造函数
//{
//	String s0;
//	String s1("hello");
//	String s2(s0);
//	String s3 = s1;
//	cout << endl;
//	s2 = s1;
//	cout << endl;
//	for (auto &s : s1)
//		cout << s;
//	cout << s1.size() << endl;
//
//	cout << endl;
//
//	foo(s1);
//	cout << endl;
//	bar(s1);
//
//	cout << endl;
//
//	foo("temporary");
//	bar("temporary");
//	String s4 = baz();   //在baz函数调用时，原有的拷贝构造函数均变成了移动构造函数，因为其在返回时为字符串变量变成的右值返回
//	String &s5 = baz();
//	baz();//baz()初始化一次C风格，然后函数返回时调用一次拷贝构造函数
//
//	cout << endl;
//
//	//这里的新值导入，左值（String的变量，等各种变量对象）使用拷贝构造函数，右值（如字面常量，函数返回值等）使用移动构造函数
//	std::vector<String> svec;        //旧内存到新内存的转换过程均变成了移动构造函数，而新数据的读入为变量时，为左值，采用拷贝构造；输入的数据为函数返回值或字面变量时，为右值，采用移动构造
//	cout << svec.capacity() << endl;
//	svec.push_back(s0);  //新数据变量读入，调用正常的拷贝构造函数
//	cout << svec.capacity() << endl;
//	svec.push_back(s1);  //svec内存扩大，旧内存的元素到新内存的移动构造一次；新数据变量读入，调用正常的拷贝构造函数一次
//	cout << svec.capacity() << endl;
//	svec.push_back(baz()); //svec内存扩大，旧内存的元素到新内存的移动构造两次；新数据函数返回值读入，调用正常的移动构造函数一次；baz()函数导入调用一次C一次移动构造
//	cout << svec.capacity() << endl;
//	svec.push_back("good job");  //svec内存扩大，旧内存的元素到新内存的移动构造三次；新数据字符串读入，调用正常的移动构造函数一次；good job作为C字符串导入进行C风格的构造
//	cout << svec.capacity() << endl;
//	svec.push_back(s2);//svec内存扩大，旧内存的元素到新内存的拷贝移动四次；新数据读入，调用正常的拷贝构造函数一次；
//	cout << svec.capacity() << endl;
//	svec.push_back("good job");//新数据字符串读入，移动构造函数一次；字符串导入调用C风格一次//因为此时的cap已经变成了6，此数据插入时不需要调整内存大小；
//	cout << svec.capacity() << endl;
//	svec.push_back(s3);//svec内存扩大，旧内存的元素到新内存的移动构造六次；新数据读入，调用正常的拷贝构造函数一次；
//	cout << svec.capacity() << endl;
//	svec.push_back(baz()); //baz()函数导入调用一次C一次移动构造（C为字符串的初始化，移动构造为return时原成员的初始化）；新数据函数返回值导入，调用一次移动构造函数
//	cout << svec.capacity() << endl;
//
//	for (auto &s : svec)
//	{
//		for (auto &ss : s)
//			cout << ss;
//		cout << " " << s.size() << " ";
//	}
//	cout << endl;
//	return 0;
//}
//
//int main2()   //练习13.53
//{
//	HasPtr a;
//	HasPtr b("me");
//	HasPtr c("icon");
//	cout << endl;
//	a = b;  //拷贝构造函数+拷贝赋值运算符
//	cout << endl;
//	HasPtr d(c);
//	cout << *a.ps << *b.ps << *c.ps << *d.ps << endl;
//
//	vector<HasPtr> word;
//	cout << word.capacity() << endl;
//	word.push_back(a);
//	cout << word.capacity() << endl;
//	word.push_back(b);
//	cout << word.capacity() << endl;
//	word.push_back(c);
//	cout << word.capacity() << endl;
//	word.push_back(d);
//	cout << word.capacity() << endl;
//
//	for (auto &s : word)
//		cout << *s.ps << endl;
//
//	return 0;
//}