#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

/*分析题1*/
class A
{
public:
	virtual void print(void)
	{
		cout << "A::print()" << endl;
	}
};

class B :public A
{
public:
	virtual void print(void)
	{
		cout << "B::print()" << endl;
	}
};

class C:public B
{
public:
	virtual void print(void)
	{
		cout << "C::print()" << endl;
	}
};

void print(A a)
{
	a.print();
}

int main1()
{
	A a, *pa, *pb, *pc;
	B b;
	C c;
	pa = &a;
	pb = &b;
	pc = &c;
	cout << endl;
	a.print();
	b.print();
	c.print();
	cout << endl;
	pa->print();
	pb->print();
	pc->print();
	cout << endl;
	print(a);
	print(b);
	print(c);

	return 0;
}

/*分析题2*/
int sum(int a)
{
	int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return (a + b + c);
}

int main2()
{
	int a = 3;
	for (int i = 0; i < 5; i++)
		cout << sum(a) << endl;
	return 0;
}

/*分析题3*/
class Base1
{
public:
	Base1(int i) { cout << "Constructing Base1 " << i << endl; }
	virtual ~Base1() { cout << "Destructing Base1" << endl; }
};

class Base2
{
public:
	Base2(int j) { cout << "Constructing Base2 " << j << endl; }
	virtual ~Base2() { cout << "Destructing Base2" << endl; }
};

class Derived :public Base2, public Base1
{
public:
	Derived(int a, int b, int c, int d) :Base1(a), member2(d), member1(c), Base2(b) { cout << "Constructing Derived" << endl; }
	~Derived() { cout << "Destructing Derived" << endl; }
private:
	Base1 member1;
	Base2 member2;
};

int main3()
{
	Derived *p = new Derived{ 1,2,3,4 };
	delete p;
	return 0;
}

/*分析题4*/
int main4()
{
	char s[] = "abccda";
	char c;
	for (int i = 1; (c = s[i]) != '\0'; i++)
	{
		switch (c)
		{
		case 'a':
			cout << "%";
			continue;
		case 'b':
			cout << "$";
		case 'c':
			cout << "*";
			break;
		case 'd':
			continue;
		}
		cout << "#" << endl;
	}
	return 0;
}

/*分析题5*/
class Base
{
private:
	char* name;
public:
	Base(char* className)  //默认构造函数
	{
		name = new char[strlen(className) + 1];
		strcpy(name, className);
	}
	//~Base() { delete name; }
	~Base() { cout << "析构函数调用" << endl; }   //上述为原析构函数，删除了不该删除的成员name，其并不是动态内存，故去掉删除的内容
	char* copyName()
	{
		//char newname[256];
		char* newname = new char[256];    //修改后语句，原文为上，没有用新内存存储数据，修改为new存储
		strcpy(newname, name);
		return newname;
	}
	char* getName() { return name; }
	static void print(Base base)
	{
		printf("name: %s\n", base.name);
	}
};

class Subclass :public Base
{
public:
	Subclass(char* className) :Base(className) {}
};

int main5()
{
	Base* pBase = new Subclass("text");
	Base::print(*pBase);  //这玩意会调用析构函数！因为此时系统认为此类已经使用完毕！
	printf("name: %s\n", pBase->getName());  //析构函数此时已被调用
	printf("name: %s\n", pBase->copyName());
	return 0;
}

/*2015分析题1*/
void main()
{
	int a[7] = { 1,5,2,3,4,1,2 };
	for (int i = 0; i<7; i++)
	{
		switch (a[i])
		{
		case 1:
			cout << "%";
			continue;
		case 2:
			cout << "$";
		case 3:
			cout << "*";
			break;
		case 4:
			continue;
		}
		cout << "#" << endl;
	}
}
