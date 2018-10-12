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

auto trns1(const char *a, const char *b)
{
	unsigned len = strlen(a) + strlen(b) + 1;
	char *r = new char[len]();
	strcat_s(r, len, a);
	strcat_s(r, len, b);
	return r;
}

auto trns2(string &a, string &b)
{
	auto temp = new string[100]{ a + b };
	return *temp;
}

int main1()  //练习12.23
{
	const char *a1 = "hs ";
	const char *b1 = "hb";
	string a2 = "new";
	string b2 = "life";
	auto temp1 = trns1(a1, b1);
	cout << temp1 << endl;
	auto temp2 = trns2(a2, b2);
	cout << temp2 << endl;
	return 0;
}

int main() //练习12.24
{
	string a;
	cin >> a;
	auto temp = new string[2]{a};  //动态数组，自动填充
	cout << *temp << endl;
	delete[] temp;//一定要记得delete
	return 0;
}*/