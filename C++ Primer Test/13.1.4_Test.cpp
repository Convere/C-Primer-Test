/*#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
using namespace std;

class numbered1
{
public:
	numbered1()  //默认构造函数的定义
	{
		static int temp = 10;  //static 全局静态变量，保证在初始化一个数值后，下一个初始化开始时temp自身不会被初始化
		mysn = temp++;
		cout << "默认构造函数" << endl;
	}
	int mysn;  //成员mysn的定义
};

void f(numbered1 s)
{
	cout << s.mysn << endl;
}

int main1()  //练习13.14   所有的构造函数均为默认的合成构造函数，所以其拷贝为简单拷贝，不会使数值产生递增
{
	numbered1 a, b = a, c = b;
	numbered1 d, e;
	cout << a.mysn << d.mysn << e.mysn << endl;   //调用默认构造函数定义的d和e，都执行了递增操作
	f(a); f(b); f(c);
	return 0;
}
//全程只有最开始，对于a的一个默认构造函数，然后对于b和c进行直接的简单拷贝，所以最终得到的结果为三个10


class numbered2
{
public:
	numbered2()  //默认构造函数的定义
	{
		static int temp = 10;
		mysn = temp++;
		cout << "默认构造函数" << endl;
	}
	numbered2(const numbered2 &temp)   //拷贝构造函数的定义
	{
		mysn = temp.mysn + 1;  //在拷贝之后，数值将会递增，并不是简单的赋值拷贝
		cout << "拷贝构造函数" << endl;
	}
	int mysn;  //成员mysn的定义
};

void f(numbered2 s)
{
	cout << s.mysn << endl;
}

int main2()  //练习13.15
{
	numbered2 a, b = a, c = b;  //在进行变量的拷贝初始化时，其仍使用的是拷贝构造函数。拷贝赋值运算符只有在两个变量都已经定义初始化过后才会调用
	//b = a; //比如这里，就会调用拷贝赋值运算符，而不是拷贝构造函数（拷贝构造函数用于初始化，而初始化页包括各种形参实参间的转换）
	cout << a.mysn << b.mysn << c.mysn << endl;  //此处用于查看第一次初始化之后abc的数值
	f(a); f(b); f(c);
	return 0;
}
//在对a进行赋值，进行一次默认构造函数，而b和c随后的定义也均为所定义的拷贝构造函数，所以此时a为10，b为11，c为12；
//在调用f函数时，三次调用均有实参与形参之间的转换，故也调用了三次拷贝构造函数，每个对应的数值都会+1，所以a为11，b为12，c为13

class numbered3
{
public:
	numbered3()  //默认构造函数的定义
	{
		static int temp = 10;
		mysn = temp++;
		cout << "默认构造函数" << endl;
	}
	numbered3(const numbered3 &temp)   //拷贝构造函数的定义
	{
		mysn = temp.mysn + 1;  //在拷贝之后，数值将会递增，并不是简单的赋值拷贝
		cout << "拷贝构造函数" << endl;
	}
	int mysn;  //成员mysn的定义
};

void f(const numbered3 &s)  //此处更改为const的引用。将导致在函数的实参形参转换，调用拷贝构造函数时，无法进行递增操作
{
	cout << s.mysn << endl;
}

int main3()  //练习13.15
{
	numbered3 a, b = a, c = b;
	cout << a.mysn << b.mysn << c.mysn << endl;
	f(a); f(b); f(c);  //最终结果无法在调用函数时各自加1，所以为10，11，12
	return 0;
}*/