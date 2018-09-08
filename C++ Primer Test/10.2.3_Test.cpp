/*#include <iostream>
#include <numeric>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include<algorithm>
using namespace std;


/*void doit(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto temp = unique(word.begin(), word.end());  //temp此时为迭代器
	word.erase(temp, word.end());
}

int main()
{
	vector<string> words{ "my","name","is","amazing","name" };
	for (auto &s : words)
		cout << "原句为：" << s << endl;
	doit(words);
	for (auto &s : words)
		cout << "修改后为：" << s << endl;
}*/

/*int main()
{
	vector<int> word{};
	int s;
	while(cin >> s)
		word.push_back(s);
	sort(word.begin(), word.end());
	if (word[word.size() / 2] != word[0] && word[word.size() / 2] != word[word.size() - 1])
		cout << word[word.size() / 2 - 1] << endl;
	else
		cout << "没有" << endl;
	return 0;
}*/