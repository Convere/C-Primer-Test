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
#include <map>
#include <set>
#include <utility>

using namespace::std;

int main1()  //练习11.16
{
	multimap<string, string> word{ {"mike","jason"},{"mike","jack"} ,{"diny","jeff"} };  //multimap一个关键词可以有多个元素
	auto word1 = word.begin();
	for (const auto &s : word)
		cout << s.first << " " << s.second << endl;
	//word1->first = "name";  //key_type是const，无法进行改变，错误用法
	word1->second = "mike";
	for (const auto &s : word)
		cout << s.first << " " << s.second << endl;
}

int main()  //練習11.19
{
	using compareType = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
	multiset<Sales_data, compareType> bookstore(compareIsbn);
	multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
}*/