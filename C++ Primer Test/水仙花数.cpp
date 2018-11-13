#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <memory>
using namespace std;

int main_shuixianhua()
{
	for (int a= 1; a != 10; ++a)
	{
		for (int b = 0; b != 10; ++b)
		{
			for (int c = 0; c != 10; ++c)
			{
				int sum = a * 100 + b * 10 + c;
				if (sum == (a*a*a) + (b*b*b) + (c*c*c))
					cout << "水仙花数为：" << a << b << c << endl;
			}
		}
	}
	return 0;
}

//我们都知道，C++在三种情况下会调用拷贝构造函数（可能有纰漏），第一种情况是函数形实结合时，第二种情况是函数返回时，
//函数栈区的对象会复制一份到函数的返回去，第三种情况是用一个对象初始化另一个对象时也会调用拷贝构造函数。

//除了这三种情况下会调用拷贝构造函数，另外如果将一个对象赋值给另一个对象，这个时候回调用重载的赋值运算符函数。
//当定义了移动构造函数后，拷贝构造函数的所有情况将会根据左值右值来确定调用拷贝构造函数还是移动构造函数