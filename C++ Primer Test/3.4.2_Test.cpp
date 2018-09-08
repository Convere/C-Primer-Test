/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //练习3.21
{
	vector<int> text;
	for (int word; cin >> word; text.push_back(word));
	cout << "相邻整数的和为：";
	for (auto it = text.begin(); it != text.end()-1; ++it)
	{
		int add1;
		add1 = *it + *(it + 1);
		cout << add1 << " ";
	}
	cout << "前后整数的和为：";
	int trn = 0;
	for (auto it = text.begin(), end = text.end(); trn != text.size() / 2; ++it, ++trn)
	{
		int add2 = 0;
		--end;
		add2 = *it + *end;
		cout << add2 << " ";
	}
	if (text.size() % 2 != 0)  //判断数据个数，确保奇数时单数输出
		cout << "此数单独" << text[text.size() / 2] << " ";
	cout << endl;
	return 0;
}*/

/*int main()
{
	vector<int> scores;
	vector<int> rank(11,0);
	for (int grade; cin >> grade; scores.push_back(grade));
	for (auto beg = scores.begin(), end = scores.end(); beg != end ; beg++)
	{
		if (*beg <= 100)
			++rank[(*beg) / 10];
	}
	for (auto &a : rank)
		cout << a << " ";
	cout << endl;
	return 0;
}*/