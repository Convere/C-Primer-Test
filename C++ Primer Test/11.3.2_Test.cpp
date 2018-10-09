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
#include <utility>

using namespace std;

int main1()  //练习11.20
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
		auto ret = count.insert({ word, 1 });  //insert的方式记录单词以及次数，明显更为繁琐
		if (!ret.second)
			++ret.first->second;
	}
	for (const auto &s : count)
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	return 0;
}

int main2()  //练习11.23
{
	multimap<string, vector<string>> family;
	string word1, word2;
	while ([&]()->bool { cout << "输入家庭的姓" << endl; return (cin >> word1) && (word1 != "end"); }())  //这里最后的（）实在不懂，还不能删
	{
		cout << "输入对应家庭孩子的名字" << endl;
		vector<string> temp;
		while (cin >> word2 && word2 != "end")
			temp.push_back(word2);
		family.insert({ word1,temp });  //插入姓与名的综合体，省去很多事
	}
	for (const auto &s : family)
		for (const auto &s2 : s.second)
			cout << s.first << " " << s2 << endl;
	return 0;
}*/