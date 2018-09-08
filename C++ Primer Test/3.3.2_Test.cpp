/*#include <iostream>
#include <vector>
#include <string>
using std::vector;
using namespace std;

int main()  //Á·Ï°3.14 ÕûÊı
{
	int word;
	vector<int>text;
	while (cin >> word)
		text.push_back(word);
	for (auto a : text)
		cout << a << " ";
	cout << endl;
}

/*int main()  //Á·Ï°3.15 ×Ö·û´®
{
	string word;
	vector<string>text;
	while (cin >> word)
	{
		text.push_back(word);
	}
	for (auto a : text)  //±éÀúÊä³ö
	cout << a << " ";
	cout << endl;
}*/