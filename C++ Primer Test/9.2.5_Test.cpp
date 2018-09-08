/*#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
using namespace std;

int main()
{
	list<char*> a{"my","name"};
	vector<string> b{"my name is"};
	for (auto &s : b)
		cout << s << endl;
	b.assign(a.begin(),a.end());  //assign 类似于将a中的元素赋予到b中，允许从一个不同但相容的类型赋值
	for (auto &s : b)
		cout << s << endl;
}*/