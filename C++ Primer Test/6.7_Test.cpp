/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int f1(int a, int b)
{
	int c = a + b;
	return c;
}

int f2(int a, int b)
{
	int c = a - b;
	return c;
}

int f3(int a, int b)
{
	int c = a * b;
	return c;
}

int f4(int a, int b)
{
	int c = a / b;
	if (b == 0)
		return 0;
	else
		return c;
}
/*int main()   //练习6.54
{
	typedef int(*fun1)(int a, int b);
	typedef decltype(f1) *fun2;
	vector<fun1> a;
	return 0;
}*/

/*int main()  //练习6.55与6.56
{
	typedef decltype(f1) *fun2;
	vector<fun2> a { f1,f2,f3,f4 };  //函数在输入单独数据时默认为指针
	for (auto f : a)   //指向函数的指针在调用时无需解引用，直接使用函数名即可
		cout << f(5, 2) << endl;
	return 0;
}*/