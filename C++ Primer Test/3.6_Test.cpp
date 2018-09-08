/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()  //练习3.43
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (auto &temp1 : ia)
		for (auto temp2 : temp1)
			cout << temp2 ;
	cout << endl;
	for (int i = 0; i < 3; i++)
		for (int ic = 0; ic < 4; ic++)
			cout << ia[i][ic];
	cout << endl;
	for (auto temp1 = ia; temp1 != ia + 3; temp1++)  //在使用数组名字的地方，编译器会自动将变量替换为指向数组首元素的指针
		for (auto temp2 = *temp1; temp2 != *temp1 + 4; temp2++)
			cout << *temp2;
}*/