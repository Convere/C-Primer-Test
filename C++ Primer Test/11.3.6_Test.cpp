#include<iostream>  
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

using namespace std;


void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = bulidMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;

	}
}
