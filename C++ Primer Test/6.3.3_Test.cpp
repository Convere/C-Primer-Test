/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
string ARR[10];
int func()
{
	return 0;
}

decltype(odd) &fund(int i)
{
	return (i % 2) ? odd : even;
}

int main()
{
	string arr[10];
	string(*func(string(&arr)[10]))[10];   //声明返回数组指针的函数
	auto func(string arr)->string(*)[10];  //尾置返回类型(最好最易理解的）

	decltype(ARR) *func(string arr);//decltype函数
}*/
