/*#include <iostream>
#include <numeric>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include <algorithm>
#include "Sales_item.h"
using namespace std;

/*void doit(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto temp = unique(word.begin(), word.end());  //temp此时为迭代器
	word.erase(temp, word.end());
}

bool isshoter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()  //练习10.11
{
	vector<string> words{ "my","name","is","amazing","name" };
	for (auto &s : words)
		cout << "原句为：" << s << endl;
	doit(words);
	stable_sort(words.begin(), words.end(), isshoter);
	for (auto &s : words)
		cout << "修改后为：" << s << endl;
}*/

/*class Sales_data
{
public:
	string isbn;
};

bool compareisbn(const Sales_data &s1, const Sales_data &s2)
{
	return s1.isbn.size() < s2.isbn.size();
}

int main()  //练习10.12
{
	Sales_data a, b, c, d;
	a.isbn = "me";
	b.isbn = "and";
	c.isbn = "world";
	d.isbn = "me";
	vector<Sales_data> save{ a,b,c,d };
	stable_sort(save.begin(),save.end(),compareisbn);
	for (auto &s : save)
		cout << s.isbn <<" ";
	cout << endl;
	return 0;
}*/

/*bool doit(const string &s1)
{
	if (s1.size() > 5)
		return true;
	else
		return false;
}

int main()  //练习10.13
{
	vector<string> word{ "i","topsky" ,"amazing","night" };
	auto temp = partition(word.begin(), word.end(), doit);
	for (auto &s : word)
		cout << s << " ";
	cout << endl;
	if (temp != word.begin())
	{
		cout << "have" << endl;
		for (; temp != word.begin(); --temp)
			cout << *(temp-1) << endl;
	}
	else
		cout << "dont have" << endl;
	return 0;
}*/