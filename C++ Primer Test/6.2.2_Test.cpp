/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret)i = 0; i != s.size(); i++)
	{
		if (s[i] == c)
		{
			if(ret==s.size())
				ret = i;
			occurs++;
		}
	}
	return ret;
}

int main()
{
	string s = ( "my name is yzt" );
	char c = 'y';
	string::size_type ctr;
	auto index = find_char(s, c, ctr);
	if (ctr == 0)
		cout << "字符" << c << "没有在该字符串中出现过" << endl;
	else
	{ 
		cout << "原字符串为：" << s << endl << "字符" << c << "第一次出现在字符串的第" << index + 1
			<< "位，" << "其共出现" << ctr << "次。" << endl;
	}
	return 0;
}*/