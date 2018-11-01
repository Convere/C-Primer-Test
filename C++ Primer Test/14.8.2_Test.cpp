/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>  
#include <map>
#include <functional>
using namespace std;

int main1()
{
	vector<int> save1;
	std::count_if(save1.cbegin(), save1.cend(), std::bind(std::greater<int>(), _1, 1024));
	std::find_if(save1.cbegin(), save1.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
	std::transform(save1.begin(), save1.end(), save1.begin(), std::bind(std::multiplies<int>(), _1, 2));
	return 0;
}

int main()
{
	auto data = { 2, 3, 4, 5 };
	int input;
	std::cin >> input;
	std::modulus<int> mod;
	auto predicator = [&](int i) { return 0 == mod(input, i); };
	auto is_divisible = std::any_of(data.begin(), data.end(), predicator);
	std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

	return 0;
}*/