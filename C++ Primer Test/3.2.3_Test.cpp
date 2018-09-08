/*#include <iostream>
#include <string>
using namespace std;

/*int main()  //Á·Ï°3.6
{
	string word("my name is yzt");
	for (auto &c : word)
		c = 'X';
	cout << word << endl;
	return 0;
}*/

/*int main()  //Á·Ï°3.7
{
	string word("my name is yzt");
	for (char &c : word)
		c = 'X';
	cout << word << endl;
	return 0;
}*/

/*int main()   //Á·Ï°3.8 whileÑ­»·
{
	string word("my name");
	int a = 0;
	while (a < word.size())
	{
		word[a] = 'X';
		a++;
	}
	cout << word << endl;
	return 0;
}*/

/*int main()  //Á·Ï°3.8 forÑ­»·
{
	string word("my name");
	for (int a = 0; a < word.size(); a++)
		word[a] = 'X';
	cout << word << endl;
	return 0;
}*/

/*int main()
{
	string word;
	while (getline(cin,word))
	{
		for (auto &a : word)
			if (!ispunct(a))
				cout << a;
	}
	return 0;
}*/