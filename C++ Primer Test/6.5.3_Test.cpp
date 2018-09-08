/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int a(int val)
{
#ifndef NDEBUG
	cout << "遍历过程中的值均为：" << val << endl;
#endif

		if (val > 1)
			return a(val - 1)*val;
	return 1;
}

int main()  //阶乘函数  练习6.33
{
	cout << a(5) << endl;
}*/