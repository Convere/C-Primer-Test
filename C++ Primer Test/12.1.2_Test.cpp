/*#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>
#include <memory>

using namespace std;

vector<int>* a1()
{
	vector<int> *p = new vector<int>;
	return p;
}

void a2(vector<int>* temp)
{
	int word;
	while (cin >> word)
		temp->push_back(word);
}

void a3(vector<int>* temp)
{
	for (auto &s : *temp)
		cout << s << endl;
	delete temp;
}

int main1()  //Á·Ï°12.6
{
	auto temp = a1();
	a2(temp);
	a3(temp);
	return 0;
}

shared_ptr<vector<int>> b1()
{
	shared_ptr<vector<int>> p;
	return p;
}

void a2(shared_ptr<vector<int>> temp)
{
	int word;
	while (cin >> word)
		temp->push_back(word);
}

void a3(shared_ptr<vector<int>> temp)
{
	for (auto &s : *temp)
		cout << s << endl;
}

int main()  //Á·Ï°12.7
{
	auto temp = a1();
	a2(temp);
	a3(temp);
	return 0;
}*/