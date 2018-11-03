#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <istream>
#include <memory>
#include "Query.h"
using namespace std;

int main()
{
	//Query q1 = Query("fiery");
	//print_qr(cout, q1, ifstream("Alice_Emma.txt"));
	//cout << endl;
	//Query q2 = Query("fiery")&Query("bird");
	//print_qr(cout, q2, ifstream("Alice_Emma.txt"));
	//cout << endl;
	//Query q3 = Query("fiery")&Query("bird") | Query("wind");
	//print_qr(cout, q3, ifstream("Alice_Emma.txt"));
	//cout << endl;
	//cout << q3 << endl;

	//runQueries(ifstream("Alice_Emma.txt"));

	history h;
	while (true)
	{
		cin.clear();
		cout << "press other to use this program,or out to quit: ";
		string s;
		if (!(cin >> s)||s == "out")break;
		{
			runQueries(ifstream("Alice_Emma.txt"), h); cin.clear();
			cout << endl;
			check_history(h); cin.clear();
			cout << endl;
		}
	}
}