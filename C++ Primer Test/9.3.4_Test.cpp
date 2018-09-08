/*#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <iterator>
using namespace std;

/*int main()   //练习9.27
{
	forward_list<int> flst{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
		if (*curr % 2)
			curr = flst.erase_after(prev);  //删除prev之后的元素，即curr迭代器中本来所指的元素，删除之后将之后元素的迭代器赋值给curr中，
		else                                //同时，由于curr中元素被删除，所以其之后的元素自动填充，curr迭代器仍处于prev迭代器之后
		{
			prev = curr;  //将curr迭代器数值赋予prev中，使其前进一格
			curr++;  //curr迭代器向前进一格
		}
	for (auto &s : flst)
	{
		cout << "链表中的偶数为：";
		cout << s << endl;
	}
}*/

/*void find(forward_list<string> &a, string b, string c)  //若想改变a中数值，设置引用格式
{
	auto it1 = a.before_begin();
	auto it2 = a.begin();
	bool tm = false;
	for (; it2 != a.end(); it1 = it2++)  //对于forward_list的循环方式，两个相邻的迭代器不断向前递增  //后++保证it2永远比it1大一位
	{
		if (*it2 == b)
		{
			a.insert_after(it2, c);
			tm = true;
		}
	}
	if (!tm)
		a.insert_after(it1, c);
}

int main()  //练习9.28
{
	forward_list<string> text{ "my","name","yzt" };
	string word1{ "name" };
	string word2{ "is" };
	find(text, word1, word2);
	for (auto &s : text)
		cout << s  <<" ";
	cout << endl;
}*/