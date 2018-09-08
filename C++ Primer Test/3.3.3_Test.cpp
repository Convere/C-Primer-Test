/*#include <iostream>
#include <vector>
#include <string>
using std::vector;
using namespace std;

/*int main()  //练习3.17
{
	vector<string>text;
	string word;
	while (cin >> word)  //输入词组存入对象
	{
		text.push_back(word);
	}
	for (auto &a : text) //一遍历数据：获取所有单个词；二遍历数据：获取每个字母
		for (auto &b : a)
			b = toupper(b);  //进行小写字母到大写字母的转换
	for (auto &a : text)   //遍历所有词，单行输出
		cout << a << endl;
	return 0；
}*/
/*
int main()
{
	vector<int>text;
	int add = 0;
	while (cin >> add)
		text.push_back(add);
	cout << "相邻数的和为";
	for (int a = 0; a < text.size() - 1; a++)  //输出相邻数的和
	{
		int sum = 0;
		sum = text[a] + text[a + 1];
		cout << sum << " ";
	}
	cout << endl;
	int size = 0;
	cout << "前与后的和为";
	for (int b = 0; b < text.size()/2; b++)  //输出前与后的和
	{
		int sum = 0;
		sum = text[b] + text[text.size() - b - 1];
		cout << sum << " ";
	}
	if (text.size() % 2 != 0)  //判断数据个数，确保奇数时单数输出
		cout << "此数单独" << text[text.size()/2] << " ";
	cout << endl;
	return 0;
}*/