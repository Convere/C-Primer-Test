/*#include <iostream>
#include <numeric>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include <algorithm>
#include<functional>

using namespace std::placeholders;
using namespace std;

/*bool doit(const string &words)
{
	return words.size() <= 6;
}

int main()  //练习10.22
{
	vector<string> word{ "i","can","fly!!!!!!","fly","on","the","sky" };
	auto temp = count_if(word.begin(), word.end(), doit);
	cout << temp << endl;
}*/

/*bool check_size(const string &s, const size_t sz)
{
	return s.size() > sz;
}

int main()  //练习10.24
{
	string ex = "Time";
	vector<string> word{ "i","can","fly!!!!!!","fly","on","the","sky" };
	auto temp = find_if(word.begin(), word.end(), bind(check_size, _1, ex.size()));
	cout << *temp << endl;
}*/

/*bool check_size(const string &s, const size_t sz)
{
	return s.size() < sz;
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
				  //sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //长度排序(sort)与字典序(stable)
	auto wc = stable_partition(words.begin(), words.end(), bind(check_size,_1,sz));  //bind函数重构代码，保留1号位，2号位根据参数调用
	auto count = words.end() - wc;  //计算满足条件的元素个数												 
	cout << "满足条件的元素个数为：" << count << endl;
	cout << "满足条件的元素为：";
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()  //练习10.25
{
	vector<string> word{ "i","can","fly!!!","fly","on","the","sky" };
	biggies(word, 3);   //得到所有大于或等于sz的数及数目
}*/