/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

size_t a()
{
	static size_t b = 0;
	b++;
	if (b == 1)
		return 0;
	else
		return b-1;
}

int main()
{
	for (int i = 0; i < 10; i++)
		cout << a() << endl;
	return 0;
}*/