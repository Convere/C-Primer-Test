/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()
{
	vector<string>text;
	string word1, word2, wordm;
	int sum, maxsum = 0;
	while (cin >> word1)
	{
		if (word1 == word2)  //word1为目前输入单词，word2为上一个输入的单词
			++sum;  //sum用于表示目前的重复次数
		else
		{
			sum = 1;
			word2 = word1;
		}
		if (maxsum < sum)  //如果新的词的重复数大于最大值，则替换最大值与重复数
		{
			maxsum = sum;
			wordm = word1;
		}
	}
	if (maxsum <= 1)
		cout << "没有单词重复出现过" << endl;
	else
		cout << "单词" << wordm << "重复出现了" << maxsum << endl;
	return 0;
}*/
