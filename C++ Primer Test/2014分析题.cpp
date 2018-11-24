#include<iostream>
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
	}
	cout << "#" << endl;
	return 0;
}