/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>  
#include <map>
using namespace std;

class Str_EQ
{
public:
	Str_EQ() {}
	Str_EQ(int &temp) :limit(temp) {}
	bool operator()(const string &temp) const { return temp.size() == limit; }
private:
	size_t limit;
};

int main1()   //练习14.38
{
	ifstream in("input_line.txt");
	string word;
	vector<string> save;
	while (in >> word)
		save.push_back(word);
	for (int n = 1; n <= 10; ++n)
	{
		Str_EQ eq(n);
		int add = 0;
		for (auto &s : save)
		{
			if (eq(s))
				++add;
		}
		cout << "长度等于 " << n << " 的字符有 " << add << " 个" << endl;
	}
	return 0;
}

int main2()   //练习14.39  //这个函数不健壮，不易于修改
{
	ifstream in("input_line.txt");
	string word;
	vector<string> save;
	while (in >> word)
		save.push_back(word);
	int add1 = 0, add2 = 0;
	for (int n = 1; n <= 9; ++n)
	{
		Str_EQ eq(n);
		for(auto &s :save)
		{
			if (eq(s))
				++add1;
		}
	}
	cout << "长度等于1到9的字符有 " << add1 << " 个" << endl;
	for (int n = 10; n <= 100; ++n)
	{
		Str_EQ eq(n);
		for (auto &s : save)
		{
			if (eq(s))
				++add2;
		}
	}
	cout << "长度大于10的字符有 " << add2 << " 个" << endl;
	return 0;
}

int main3()  //练习14.39  //这个函数使用map存储，易于修改
{
	ifstream in("input_line.txt");
	string word;
	map<size_t, size_t> save;
	while (in >> word)
	{
		auto ret = save.insert({ word.size(),1 });
		if (!ret.second)
			++ret.first->second;
	}
	size_t add1 = 0, add2 = 0;
	for (auto &s : save)
	{
		if (s.first < 10)
			add1 += s.second;
		else
			add2 += s.second;
	}
	cout << "长度等于1到9的字符有 " << add1 << endl;
	cout << "长度大于10的字符有 " << add2 << endl;
	return 0;
}

void doit(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto temp = unique(word.begin(), word.end());  //temp此时为迭代器
	word.erase(temp, word.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	doit(words);  //words中所有字符按字母顺序排序，并删除重复的单词
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //长度排序与字典序
	auto wc = find_if(words.begin(), words.end(), SizeComp(sz));  //查找第一个符合条件的数
	auto count = words.end() - wc;  //计算满足条件的元素个数
	cout << "满足条件的元素个数为：" << count << endl;
	for_each(wc, words.end(), [](const string &s) {cout << "满足条件的元素为：" << s << " "; });
	cout << endl;
}

class SizeComp
{
	friend void biggies(vector<string> &words, vector<string>::size_type sz);
public:
	SizeComp(size_t n):sz(n){}
	bool operator()(const string &s) const { return s.size() > sz; }
private:
	size_t sz;
};*/