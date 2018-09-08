/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int trs(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	return 0;
}

int main()
{
	int a = 5, b = 7;
	trs(a, b);  //int &a=a;函数中相当于对于实参的引用
	cout << a << "  " << b << endl;
}*/