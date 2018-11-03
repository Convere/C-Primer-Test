//#include <iostream>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//using namespace std;
//
//class ex
//{
//public:
//	int a;
//	ex() {};
//};
//
//class Ex
//{
//public:
//	int a = 0;
//	Ex() = default;
//	Ex(const int &t) : a(t) { cout << "参数化默认构造函数" << endl; }
//	Ex(const Ex&t) :a(t.a) { cout << "拷贝构造函数" << endl; }
//	Ex &operator=(const Ex&t) { };
//	//Ex &operator=(const Ex&t) { a = t.a; cout << "拷贝赋值运算符" << endl; return *this; }
//	/*Ex &operator=(const Ex&)=delete;*/
//	~Ex(){}
//};
//
//int main()
//{
//	Ex ex1(1);
//	Ex ex2(2);
//	Ex ex3(3);
//	Ex ex4(ex1);
//	cout <<ex4.a<< endl;
//	ex1 = ex3;
//
//	cout << ex1.a << endl;
//}

//class A
//{
//public:
//	//A(bool _isTrue = true, int _num = 0) { isTrue = _isTrue; num = _num; }; //默认构造函数
//	//A() = default;
//	bool isTrue;
//	int num;
//
//};
//class B
//{
//public:
//	A a;//类A含有默认构造函数
//	int b;
//	//...
//};
//int main()
//{
//	B b;    //编译至此时，编译器将为B合成默认构造函数
//	cout << b.b << endl;
//	return 0;
//}