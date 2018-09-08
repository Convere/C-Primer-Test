/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

inline string make_plural(size_t ctr, const string &word, const string &ending)  //inline内联函数，有效提升函数运行速度
{
	return (ctr > 1) ? word + ending : word;
}

int main()  //练习6.42
{
	string word1 = make_plural(3, "success", "es");
	string word2 = make_plural(2, "failure", "s");
	cout << word1 << endl;
	cout << word2 << endl;
}*/