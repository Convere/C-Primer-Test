/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

auto f1(int a, int *b)
{
	int c;
	if (a > *b)
		return a;
	else
		return *b;
}

auto f2(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

void print(int* const pi)
{
	if (pi) 
		cout << *pi << endl;
}

void print(const int ia[],size_t size)
{
	for (size_t i = 0; i != size; i++)
		cout << ia[i] << endl;
}

int main()
{
	/*int ia = 0;  //Á·Ï°6.21
	int a = 4, *b = &a;
	ia = f1(a, b);
	cout << ia << endl;*/

	/*int a, b;  //Á·Ï°6.22
	cin >> a >> b;
	int *a1 = &a, *b1 = &b;
	cout << *a1 << "  " << *b1 << endl;
	f2(a1, b1);
	cout << *a1 << "  " << *b1 << endl;

	int i = 0;
	int j[2] = { 0,1 };
	print(&i);
	print(j, end(j) - begin(j));
}*/