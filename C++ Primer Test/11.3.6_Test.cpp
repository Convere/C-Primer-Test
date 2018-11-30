//#include<iostream>  
//#include<string>  
//#include<vector>  
//#include<algorithm>  
//#include<numeric>  
//#include<functional>
//#include<iterator>
//#include<list>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <set>
//#include <utility>
//
//using namespace std;
//
//map<string, string> bulidMap(ifstream &map_file)
//{
//	map<string, string> trans_map;
//	string key;
//	string value;
//	while (map_file >> key && getline(map_file, value))
//		if (value.size() > 1)
//			trans_map[key] = value.substr(1);   //去除空格，同时将map的关键词设为每一行的第一个词，其元素变为每一行后面的词
//			//trans_map.insert({ key,value.substr(1) });  //使用下标时，一旦map中有了相同的关键词，则使用最后一个，而insert时会一直用第一个
//		else
//			throw runtime_error("no rule for " + key);
//	return trans_map;
//}
//
//const string &transform(const string &s, const map<string, string> &m)
//{
//	auto map_it = m.find(s);
//	if (map_it != m.cend())  //找到就换
//		return map_it->second;
//	else
//		return s;
//}
//
//void word_transform(ifstream &map_file, ifstream &input)
//{
//	auto trans_map = bulidMap(map_file);
//	string text;
//	while (getline(input, text))
//	{
//		istringstream stream(text);
//		string word;
//		bool firstword = true;   //这玩意是用来在每个单词之间打印一个空格的
//		while (stream >> word)
//		{
//			if (firstword)
//				firstword = false;
//			else
//				cout << " ";
//			cout << transform(word, trans_map);
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	ifstream mapfile("map_file.txt");
//	ifstream input("input.txt");
//	word_transform(mapfile, input);
//}
