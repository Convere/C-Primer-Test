/*#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <iterator>
using namespace std;

void change(string& word, const string& old, const string& ne)
{
	for (auto beg = word.begin(); distance(beg, word.end()) >= distance(old.begin(), old.end()); )  //beg开始直接被定义
	{
		if (string{ beg,beg + old.size() } == old)
		{
			beg = word.erase(beg, beg + old.size());
			beg = word.insert(beg, ne.cbegin(), ne.cend());
			advance(beg, ne.size());
		}
		else
			++beg;
	}
}

void rep(string& word, const string& old, const string& ne)  //练习9.44
{
	for (auto i=0;i!=word.size();++i )
		if (word.substr(i,old.size()) == old)
		{
			word.replace(i, old.size(), ne);
			i = i + ne.size();
		}
}

auto banf(string na, string bef, string fro)   //练习9.45
{
	na.insert(0, bef);
	na.append(fro);
	return na;
}

auto banf2(string na, string bef, string fro)   //练习9.46
{
	na.insert(na.end() , fro.begin(), fro.end());
	na.insert(0, bef,0,bef.size());
	return na;
}

int main()   //练习9.43
{
	string s{"i can tho the thru!"};
	string oldval{ "tho" };
	string newval{ "though" };
	change(s, oldval, newval);
	rep(s, "thru", "through");
	cout << s << endl;

	string name{ "yzt" };
	name = banf2(name, "Mr.", "III");
	cout << name << endl;
}*/