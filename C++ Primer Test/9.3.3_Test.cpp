/*#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <iterator>
using namespace std;

int main()  //练习9.26
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int>even(ia, ia + 11);
	list<int>odd(ia, ia + 11);
	auto it1 = even.begin();
	while (it1 != even.end())
	{
		if ((*it1) % 2 == 0)
			it1 = even.erase(it1);
		else
			++it1;
	}

	auto it2 = odd.begin();
	while (it2 != odd.end())
	{
		if ((*it2) % 2 != 0)
			it2 = odd.erase(it2);
		else
			++it2;
	}

	for (auto &s1 : even)
	{
		cout << "奇数为：";
		cout << s1 << endl;
	}
	for (auto &s2 : odd)
	{
		cout << "偶数为：";
		cout << s2 << endl;
	}
}*/