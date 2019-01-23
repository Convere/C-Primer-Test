#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

static bool flag = false;

void find(int lo, int hi, string &a, string &b)
{
	if (hi == lo)
		return;
	int mid = (lo + hi) / 2;
	string c = a.substr(mid) + a.substr(0, mid);
	if (c == b)
	{
		flag = true;
		return;
	}
	find(lo, mid, a, b);
	find(mid + 1, hi, a, b);
}

bool find2(int lo, int hi, string a, string b)
{
	for (int mid = 0; mid < a.size(); mid++)
	{
		string c = a.substr(mid) + a.substr(0, mid);
		if (c == b)
			return true;
	}
	return false;
}

int main_xunhuanyiwei()
{
	string a, b;
	while (cin >> a >> b)
	{
		find(0, a.size(), a, b);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		flag = false;
	}
	return 0;
}