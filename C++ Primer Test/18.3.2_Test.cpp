//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//using namespace std;
//class B1
//{
//public:
//	B1()
//	{
//		cout << "B1构造函数" << endl;
//	}
//	virtual void print()
//	{
//		cout << "B1打印函数" << endl;
//	}
//	virtual ~B1()
//	{
//		cout << "B1析构函数" << endl;
//	}
//};
//class D1 :public B1
//{
//public:
//	D1()
//	{
//		cout << "D1构造函数" << endl;
//	}
//	void print()
//	{
//		cout << "D1打印函数" << endl;
//	}
//	~D1()
//	{
//		cout << "D1析构函数" << endl;
//	}
//};
//class B2
//{
//public:
//	B2()
//	{
//		cout << "B2构造函数" << endl;
//	}
//	virtual void print()
//	{
//		cout << "B2打印函数" << endl;
//	}
//	virtual ~B2()
//	{
//		cout << "B2析构函数" << endl;
//	}
//};
//class D2 :public B2
//{
//public:
//	D2()
//	{
//		cout << "D2构造函数" << endl;
//	}
//	void print()
//	{
//		cout << "D2打印函数" << endl;
//	}
//	~D2()
//	{
//		cout << "D2析构函数" << endl;
//	}
//};
//class MI :public D1, public D2
//{
//public:
//	MI()
//	{
//		cout << "MI构造函数" << endl;
//	}
//	void print()
//	{
//		cout << "MI打印函数" << endl;
//	}
//	~MI()
//	{
//		cout << "MI析构函数" << endl;
//	}
//};
//int main()  //练习18.25
//{
//	B1 *b1 = new MI;//构造函数的调用是从基类开始到派生类
//	cout << endl;
//	B2 *b2 = new MI;
//	cout << endl;
//	D1 *d1 = new MI;
//	cout << endl;
//	D2 *d2 = new MI;
//	cout << endl;
//
//	b1->print();
//	cout << endl;
//	b2->print();
//	cout << endl;
//	d1->print();
//	cout << endl;
//	d2->print();
//	cout << endl;
//
//	delete b1;//删除指向派生类的基类指针需要注意其过程
//	cout << endl;
//	delete b2;
//	cout << endl;
//	delete d1;
//	cout << endl;
//	delete d2;
//	cout << endl;
//
//	return 0;
//}
