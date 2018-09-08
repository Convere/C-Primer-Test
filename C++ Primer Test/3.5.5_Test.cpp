/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //Á·Ï°3.41
{
	int a[5] = { 1,2,3,4,5 };
	vector <int>b(begin(a),end(a));
	for(auto c:b)
		cout << c << endl;
	cout<<begin(a) << end(a) << endl;
}*/

/*int main() //Á·Ï°3.42
{
	vector<int> a(10, 5);
	int b[10];
	int b1 = 0;
	for (auto beg = a.begin(); beg != a.end(); b1++, beg++)
		b[b1] = *beg;
	for (int i = 0; i < 10; i++)
		cout << "b[" << i << "]=" << b[i] << " ";
}*/

/*int main()  //Á·Ï°3.41
{
	int a[5] = { 1,2,3,4,5 };
	vector <int>b(a, a + 5);
	for (auto c : b)
		cout << c << endl;
	cout<<begin(a) << end(a) << endl;
}*/

