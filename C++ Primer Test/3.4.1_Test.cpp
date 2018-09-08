/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //Á·Ï°3.21
{
	vector<int> v1;
	cout << "v1" << endl;
	for (auto it = v1.begin(); it != v1.end(); ++it)
		cout << *it << endl;
	vector<int> v2(10);
	cout << "v2" << endl;
	for (auto it = v2.begin(); it != v2.end(); ++it)
		cout << *it << endl;
	vector<int> v3(10,42);
	cout << "v3" << endl;
	for (auto it = v3.begin(); it != v3.end(); ++it)
		cout << *it << endl;
	vector<int> v4{ 10 };
	cout << "v4" << endl;
	for (auto it = v4.begin(); it != v4.end(); ++it)
		cout << *it << endl;
	vector<int> v5{ 10,42 };
	cout << "v5" << endl;
	for (auto it = v5.begin(); it != v5.end(); ++it)
		cout << *it << endl;
	vector<string> v6{ 10 };
	cout << "v6" << endl;
	for (auto it = v6.begin(); it != v6.end() && !it->empty(); ++it)
		cout << *it << endl;
	vector<string> v7{ 10,"hi" };
	cout << "v7" << endl;
	for (auto it = v7.begin(); it != v7.end() && !it->empty(); ++it)
		cout << *it << endl;
}*/

/*int main()  //Á·Ï°3.22
{
	string text("my name");
	for (auto it = text.begin(); it != text.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it);
	}
	cout << text << endl;
}*/

/*int main()
{
	vector<int> text(10,3);
	for (auto it = text.begin(); it != text.end() && !isspace(*it); ++it)
		*it = *it * 2;
	for (auto it = text.begin(); it != text.end() && !isspace(*it); ++it)
		cout << *it << endl;
	return 0;
}*/