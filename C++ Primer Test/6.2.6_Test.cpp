/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int sum(const initializer_list<int> aa)  //Á·Ï°6.27
{
	int add = 0;
	for (auto beg = aa.begin(); beg != aa.end(); beg++)
		add += *beg;
	return add;
}

int main()
{
	int add2;
	add2 = sum({ 1,2,3,4,5,5 });
	cout << add2 << endl;
}*/