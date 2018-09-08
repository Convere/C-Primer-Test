/*#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
using namespace std;

vector<int> ex{ 1,2,3 };         //练习9.11
vector<int> a0;
vector<int> a1(ex);    //直接拷贝初始化
vector<int> a2 = ex;   //拷贝初始化 
vector<int> a3{ 1,2,3 };	//直接列表初始化
vector<int> a4 = { 1,2,3 };	//列表初始化
vector<int> a5(ex.begin(), ex.end());	//迭代器范围初始化
vector<int> a6(10);	//值初始化
vector<int> a7(10, 2);	//规定值的初始化

int main()  //练习9.13
{
	list<int> b1{ 1,2 };   //使用迭代器初始化即可
	vector<double> b2(b1.begin(), b1.end());
	for (auto &s : b2)
		cout << s << endl;
}*/