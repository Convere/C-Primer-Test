/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //Á·Ï°5.5  if
{
	const vector<string> rank{ "F","D","C","B","A","A++" };
	int grade;
	cin >> grade;
	if (grade < 60)
		cout << rank[0] << endl;
	else
		cout << rank[(grade - 50) / 10] << endl;
	return 0;
}*/

/*int main()  //Á·Ï°5.5  Ìõ¼þ
{
	const vector<string> rank{ "F","D","C","B","A","A++" };
	int grade;
	cin >> grade;
	cout << ((grade < 60) ? rank[0] : (rank[(grade - 50) / 10])) << endl;
	return 0;
}*/