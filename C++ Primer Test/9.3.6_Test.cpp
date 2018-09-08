/*#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //练习9.31
{
	forward_list<int> vi{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = vi.before_begin();
	auto curr = vi.begin();
	while (curr != vi.end())
	{
		if (*curr % 2)
		{
			curr = vi.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
		else
			curr = vi.erase_after(prev);   //由于链表结构的特殊性，在删除两者之间的一个元素后，其两者仍为连接状态
	}
	for (auto &s : vi)
		cout << s << endl;
}*/


/*int main()  //练习9.33
{
	vector<int> v{ 1,2,3,4 };
	auto begin = v.begin();
	while(begin!=v.end())
	{
		++begin;
		begin = v.insert(begin, 42);
		++begin;
	}
	for (auto &s : v)
		cout << s << endl;
}*/