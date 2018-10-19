/*#include <vector>
#include <string>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>  
#include <algorithm>  
#include <numeric>  
#include <functional>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>

using namespace std;
using line_no = vector<string>::size_type;

class QueryResult  //字符打印类
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}  //构造函数
private:
	string sought;  //保存查询的单词
	shared_ptr<set<line_no>> lines;  //指向单词出现的行号set；
	shared_ptr<vector<string>> file; //指向保存每行输入文件的vector
};

class TextQuery  //字符处理类，通过输入文件，得到存储的每行数据，以及不同单词出现次数的数据。
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	TextQuery(ifstream&);//构造函数的声明，定义定在外部
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);  //在vector中将源文件每行保留
		int n = file->size();  //记录行号
		istringstream line(text);  //分解每行，使之成为各个单词，再次形成输入流
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];  //将输入的单词存入map中，自己递增，同时再创建一个引用型的指针lines，指向map的元素set
			if (!lines)
				lines.reset(new set<line_no>);  //若wm中有word，返回其对应的元素，则不执行此语句；
			//没有word，则将其存入，此时该word的元素为空，执行此语句，为其添加一个新的set作为七元素
			lines->insert(n);//在对应的word元素set中插入数字，代表行数
		}
	}
}

QueryResult TextQuery::query(const string &sought)const  //查找函数，用于将输入的单词进行查询，并存储数据
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);  //一个空的set指针
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); //没找到，输出搜索词，无数据，查找文件
	else
		return QueryResult(sought, loc->second, file); //找到了，输出搜索词，出现次数，查找文件
}

ostream &print(ostream &os, const QueryResult &qr)  //用于打印数据
{
	os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num << ") " << *(qr.file->begin() + num - 1) << endl;
	return os;
}

void runQueries(ifstream &infile)  //统筹函数，用于输入数据，以及使其计算加打印
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter a word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	runQueries(ifstream ("input_line.txt"));
}*/