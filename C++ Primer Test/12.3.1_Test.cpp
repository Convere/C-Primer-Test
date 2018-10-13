/*#include <vector>
#include <string>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
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

int main()  //练习12.28
{
	ifstream in1("input_line.txt");
	ifstream in2("input_line.txt");
	string word1, word2;
	vector<string> save;
	set<string> line;
	map<string, int> place;
	while (getline(in1, word1))
		save.push_back(word1);
	while (in2 >> word2)
		++place[word2]; 


	cout << "输入需要查找的字符" << endl;
	string temp;
	cin >> temp;
	auto ct = place.find(temp);  //这里实现字符出现了多少次
	if (ct != place.end())  //检查该字符串中是否存在该字符
		cout << "word " << temp << " occurs " << ct->second << ((ct->second > 1) ? " times " : " time ") << endl;
	else
	{
		cout << "word not in!" << endl;
		return 0;
	}

	int n = 1;
	for (auto &s : save)  //实现将出现过该字符的某一句枚举并打印出来
	{
		auto pl = s.find(temp);
		if (pl != string::npos)
			cout << "    " << "(line" << n << ")" << " " << s << endl;
		n++;
	}
}*/