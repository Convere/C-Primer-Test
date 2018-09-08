/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()  //练习5.23—5.25
{
	int a, b;
	double c;
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("第二个数不能为0");
			cout << 1.0*a / b << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << "\n是否需要重新输入? Enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n') //!cin 或 c=='n'
				break;
		}
	}
}*/