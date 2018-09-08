/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //练习4.21
{
	vector<int>a{ 1,2,3,4,5,6 };
	for (auto &b : a)
		b = (b % 2 != 0) ? (b * 2) : (b);
	for (auto b : a)
		cout << b << endl;
}*/

/*int main()  //练习4.22
{
	int grade;
	cin >> grade;
	string rank = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "low pass" : "fail";
	cout << rank << endl;

	if (grade > 90)  //if版本虽然比较直观，但是实在是不简洁
		cout << "high pass" << endl;
	else
	{
		if (grade > 75)
			cout << "pass" << endl;
		else
		{
			if (grade > 60)
				cout << "low pass" << endl;
			else cout << "fail" << endl;
		}
	}
	return 0;
}*/

/*int main()
{
	string s = "word";
	string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
	cout << p1 << endl;
}*/