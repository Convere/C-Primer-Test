/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*int main() //练习5.9
{
	int cnt = 0, othercnt = 0;
	char m = 0;
	while(cin>>m)
	{ 
		if (m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u')
			cnt++;
		else othercnt++;
	}
	cout << "元音字符数为：" << cnt << endl;
	cout << "非元音字符数为：" << othercnt << endl;
}*/



/*int main()  //练习5.12
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, space = 0, zb = 0, hh = 0, ff = 0, fl = 0, fi = 0;
	char ch, ch2 = '\0';
	while (cin >> std::noskipws >> ch)
	{
		switch (ch)
		{
		case 'a': case'A':
			++aCnt;
			break;
		case 'e':case 'E':
			++eCnt;
			break;
		case 'i':
			if (ch2 == 'f')
				++fi;
			else
			{
				++iCnt;
				break;
			}
		case 'I':
			++iCnt;
			break;
		case 'o':case 'O':
			++oCnt;
			break;
		case 'u':case 'U':
			++uCnt;
			break;
		case'\40':
			++space;
			break;
		case'\t':
			++zb;
			break;
		case'\n':
			++hh;
			break;
		case'f':
			if (ch2 == 'f')
				++ff;
		case'l':
			if (ch2 == 'f')
				++fl;
		}
		ch2 = ch;
	}
	cout << "Number of vowel a(A): \t" << aCnt << '\n'
		<< "Number of vowel e(E): \t" << eCnt << '\n'
		<< "Number of vowel i(I): \t" << iCnt << '\n'
		<< "Number of vowel o(O): \t" << oCnt << '\n'
		<< "Number of vowel u(U): \t" << uCnt << '\n'
		<< "Number of vowel 空格 \t" << space << '\n'
		<<"Number of vowel 制表符 \t" << zb << '\n'
		<< "Number of vowel 换行符 \t" << hh << endl
		<< "Number of vowel fi \t" << fi << endl
		<< "Number of vowel ff \t" << ff << endl
		<< "Number of vowel fl \t" << fl << endl;
	return 0;
}*/