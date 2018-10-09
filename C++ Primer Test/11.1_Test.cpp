/*#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main1() //练习11.3
{
	ifstream in("file2.txt");
	map<string, int> count;
	set<string> exclude{ "" };
	string word;
	while (in >> word)
		++count[word];
	for (const auto &s : count)
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time " )<< endl;
	return 0;
}

int main2()  //练习11.4
{
	ifstream in("file2.txt");
	map<string, int> count;
	string word;
	while (in >> word)
	{
		for (auto beg = word.begin(); beg != word.end();)
		{
			if (ispunct(*beg))  //删除string中的标点符号
				beg = word.erase(beg); //这里的erase采用的是容器的删除定义，即删除对应迭代器位置的值，返回指向后一个迭代器。而word作为string字符串也有自定的erase操作
			else
			{
				*beg = tolower(*beg);  //大写全部变成小写
				++beg;
			}
		}
		++count[word];
	}
	for (const auto &s : count)
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	return 0;
}*/