/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*bool find(vector<int>::iterator a, vector<int>::iterator b,int c)   //练习9.4
{
	while (a != b)  //迭代器循环
	{
		if (*a == c)
			return true;  //若找到，则直接返回true
		++a;
	}
	return false;  //若遍历循环仍未找到，则返回false；
}

int main()
{
	vector<int> word(10,1);
	int num = 1;
	if (find(word.begin(), word.end(), num))
		cout << "find the number " << num << " in the word" << endl;
	else
		cout << "don't find the number" << endl;
	return 0;
}*/

/*auto find(vector<int>::iterator a, vector<int>::iterator b, int c)   //练习9.5
{
	while (a != b)  //迭代器循环
	{
		if (*a == c)
			return a;  //若找到，则直接返回当前迭代器的值
		++a;
	}
	return a;  //若遍历循环仍未找到，则返回当前迭代器的值（此时返回end是相同作用，因为未找到结果后所得结果就是end）
}

int main()
{
	vector<int> word(10, 1);
	int num = 2;
	auto res = find(word.begin(), word.end(), num);
	if (res != word.end())
		cout << "find the number " << *res << " in the word" << endl;
	else
		cout << "don't find the number" << endl;
	return 0;
}*/