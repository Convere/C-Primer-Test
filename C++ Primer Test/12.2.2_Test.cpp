/*#include <vector>
#include <string>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main()
{
	string s;
	allocator<string> alloc;
	auto p = alloc.allocate(10);//用的是()，只分配内存
	auto q = p;
	while (cin >> s && q != p + 10)
	{
		alloc.construct(q++, s);//创建对象并幅值
	}
	const size_t size = q - p;
	while (q != p)
	{
		alloc.destroy(--q);//逐个销毁对象，destory接受一个指针
	}
	alloc.deallocate(p, 10);//分配多少内存，释放多少
	cout << size << endl;
	return 0;
}*/