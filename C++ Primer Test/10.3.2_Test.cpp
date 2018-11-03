//#include <iostream>
//#include <numeric>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <iterator>
//#include <list>
//#include <algorithm>
//using namespace std;

/*int main()
{
	int sz = 0;
	[](int &b,int &c) {cout << b + c; }; //练习10.14
	[sz](int &b) {return sz + b; };  //练习10.15
}*/

/*void doit(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto temp = unique(word.begin(), word.end());  //temp此时为迭代器
	word.erase(temp, word.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	doit(words);  //words中所有字符按字母顺序排序，并删除重复的单词
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //长度排序与字典序
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() > sz; });  //查找第一个符合条件的数
	auto count = words.end() - wc;  //计算满足条件的元素个数
	cout << "满足条件的元素个数为：" << count << endl;
	for_each(wc, words.end(), [](const string &s) {cout << "满足条件的元素为：" << s << " "; });
	cout << endl;
}

int main()  //练习10.16
{
	vector<string> word{ "i","can","fly","on","the","sky!" };
	biggies(word,2);
}*/

/*class Sales_data
{
public:
	string isbn;
};

int main()  //练习10.17
{
	Sales_data a, b, c, d;
	a.isbn = "me";
	b.isbn = "and";
	c.isbn = "world";
	d.isbn = "me";
	vector<Sales_data> save{ a,b,c,d };
	stable_sort(save.begin(), save.end(), [](const Sales_data &s1, const Sales_data &s2) {return s1.isbn.size() < s2.isbn.size(); });
	//使用lambda代替了函数的谓词
	for (auto &s : save)
		cout << s.isbn << " ";
	cout << endl;
	return 0;
}*/

/*void doit(vector<string> &word)
{
sort(word.begin(), word.end());
auto temp = unique(word.begin(), word.end());  //temp此时为迭代器
word.erase(temp, word.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	doit(words);  //words中所有字符按字母顺序排序，并删除重复的单词
	//sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //长度排序(sort)与字典序(stable)
	auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a) {return a.size() < sz; });  //将判断条件反转，使得不符合为true
	auto count = words.end() - wc;  //计算满足条件的元素个数												 //stable加入后字符串进行字典序
	cout << "满足条件的元素个数为：" << count << endl;
	cout << "满足条件的元素为：";
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()  //练习10.18
{
	vector<string> word{ "i","can","fly!!!","fly","on","the","sky" };
	biggies(word, 3);
}*/