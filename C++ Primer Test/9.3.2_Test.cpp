/*#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <iterator>
using namespace std;

int main()  //练习9.24
{
	vector<int> c{ };
	auto val1 = c.at(0);  //报错out of range
	auto val2 = c[0];  //无对应元素
	auto val3 = c.front();  //无对应元素
	auto val4 = *c.begin();  //无对应元素
	cout << val1 << val2 << val3 << val4 << endl;
}*/