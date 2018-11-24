#include <iostream>
using namespace std;

int main()
{
	int n, m, point;
	static int save[500002], sum_save[500002];
	cin >> n >> m;
	cin >> point;
	save[0] = point;
	while (cin.get() != '\n')
	{
		for (int i = 1; i < n; i++)
		{
			cin >> point;
			save[i] = point;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, sum = 0;
		if (cin >> a >> b)
		{
			for (auto &s : save)
			{
				if ((a <= s) && (b >= s))
					sum++;
			}
			sum_save[i - 1] = sum;
		}
	}
	for (int i = 0; i < m; i++)
		cout << sum_save[i] << endl;
	return 0;
}