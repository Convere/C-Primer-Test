/*#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //练习9.47
{
	string a{ "ab2c3d7R4E6" };
	string num{ "0123456789" };
	auto pos = 0;
	while ((pos = a.find_first_of(num, pos)) != string::npos)
	{
		cout << "在第 " << pos << " 个位置找到数字 " << a[pos] << endl;
		++pos;
	}
	cout << endl;
	pos = 0;
	while ((pos = a.find_first_not_of(num, pos)) != string::npos)
	{
		cout << "在第 " << pos << " 个位置找到字母 " << a[pos] << endl;
		++pos;
	}
	return 0;
}*/

/*int main()  //练习9.49
{
	string word;
	auto pos1 = 0, pos2 = 0;
	string st{ "bdfhiklt" };
	string xt{ "jgpqy" };
	ifstream infile("wordinput.txt");
	while (infile >> word)         //批量输入单词
	{
		cout << "原单词为：" << word << endl;
		while ((pos1 = word.find_first_of(st, pos1)) != string::npos)  //删除上出头字母
			word.erase(pos1, 1);
		pos1 = 0;
		while ((pos2 = word.find_first_of(xt, pos2)) != string::npos)  //删除下出头字母
			word.erase(pos2, 1);
		pos2 = 0;
		cout << "现单词为：" << word << endl;
	}
	return 0;
}*/