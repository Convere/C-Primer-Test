/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

auto daxie(const string &a)  //检测大写函数
{
	int m = 0;
	for (auto i : a)
	{
		if (isupper(a[m]))
			break;
		m++;
	}
	return m;
}

auto xiaoxie(string &a)  //小写修改函数
{
	int m = 0;
	for (auto &i : a)
	{
		a[m] = tolower(a[m]);
		m++;
	}
	return 0;
}

int main()  //主函数
{
	string A = ("My Name is YZT.");
	auto n = daxie(A);
	cout << "原字符串为：" << A << endl;
	if (n == A.size())
		cout << "字符串中没有大写字母" << endl;
	else
		cout << "字符串中有大写字母" << endl;
	xiaoxie(A);
	cout << "全为小写的字符串为：" << A << endl;
	return 0;
}*/