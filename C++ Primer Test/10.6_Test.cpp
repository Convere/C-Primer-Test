/*#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>

using namespace std;

int main()  //练习10.42
{
	list<string> words{ "my","name","is","amazing","name" };
	for (auto &s : words)
		cout << s << endl;
	for (auto beg = words.begin(); beg != words.end(); beg++)
		cout << "原句为：" << *beg << endl;
	words.sort();
	words.unique();
	//doit(words);
	for (auto beg = words.begin(); beg != words.end(); beg++)
		cout << "修改为：" << *beg << endl;
}*/