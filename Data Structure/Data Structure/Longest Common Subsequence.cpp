#include "Ch1.h"
#include <vector>
#include <string>

static int num1 = 0;
static int num2 = 0;
static int num3 = 0;
string LCS(string &a, string &b)
{
	string temp;
	for (auto &s1 : a)
	{
		++num3;
		for (auto &s2 : b)
		{
			++num2;
			if (s1 == s2)
			{
				++num1;
				temp.push_back(s1);
				break;
			}
		}
	}
	return temp;
}

int main_LCS()
{
	string a{ "string" };
	string b{ "rrnsg" };
	cout << LCS(a, b) << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	return 0;
}