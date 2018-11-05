#include <vector>
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
	//friend ostream& print_qr(ostream &a, const Query &b, ifstream &c);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}  //构造函数
	auto begin() { return (*lines).begin(); }
	auto end() { return (*lines).end(); }
	auto get_file() { return file; }
//private:
	string sought;  //保存查询的单词
	shared_ptr<set<line_no>> lines;  //指向单词出现的行号set；
	shared_ptr<vector<string>> file; //指向保存每行输入文件的vector
};

class TextQuery  //字符处理类，通过输入文件，得到存储的每行数据，以及不同单词出现次数的数据。
{
	friend ostream& print(ostream&, const QueryResult&);
	//friend ostream& print_qr(ostream&, const Query &, ifstream &);
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

class history    //history类，runQueries函数，check_history函数，Run函数，是组成历史系统的主要部分
{
public:
	friend void runQueries(ifstream &, history &);
	int num = 1;
	map<int, QueryResult> his;
	history &operator+=(history &add)   //运算符的定义，但还是略有问题
	{
		for (auto &s : add.his)
		{
			his.insert({ num, s.second });
			++num;
		}
		return *this;
	}
};

history add(history &temp1, const history &temp2)
{
	for (auto &s : temp2.his)
	{
		(temp1.his).insert({ temp1.num, s.second });
		++temp1.num;
	}
	return temp1;
}

void runQueries(ifstream &infile,history &h)  //统筹函数，用于输入数据，以及使其计算加打印
{
	const static TextQuery tq(infile);   //const static 静态定值，保证其tq稳定
	while (true)
	{
		cout << "enter a word to look for,or q to quit: ";
		cin.ignore(INT_MAX, '\n');
		//TextQuery tq(infile);
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
		h.his.insert({ h.num,tq.query(s) });
		++(h.num);
	}
}

void check_history(history &h)
{
	while (true)
	{
		cout << "enter a number of history or 0 to quit: ";
		cin.ignore(INT_MAX, '\n');
		size_t number;
		if (!(cin >> number) || number == 0) break;
		auto temp = (h.his).find(number);
		auto limit = (h.his).size();
		if (number > limit)
		{
			cout << "out of range!" << endl;
		}
		else
		{
			cout << temp->first << " # ";
			print(cout, temp->second);
		}
	}
}

void Run(history &h, ifstream &in)
{
	while (true)
	{
		cout << "press other to use this program,or out to quit: ";
		//cin.ignore(INT_MAX, '\n');
		string s;
		cin >> s;
		if (s == "out")
			break;
		else
		{
			runQueries(in, h);
			cout << endl;
			check_history(h);
			cout << endl;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');   //清空输入流，保证能进行下一步输入
	}
}

class Query_base
{
	friend class Query;
protected:
	//using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery &) const = 0;  //用于eval函数，返回与当前Query匹配的QueryResult
	virtual string rep() const = 0;  //rep表示查询的string
};

class Query
{
	//三个友元
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const string &);   //构建一个新的WordQuery
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }   //返回与当前Query匹配的QueryResult
	string rep() const { cout << "Query的rep()" << endl; return q->rep(); }
private:
	Query(shared_ptr<Query_base> query) :q(query){ cout << "Query参数默认构造函数" << endl; }  //参数默认构造函数
	shared_ptr<Query_base> q;
};

ostream &operator<<(ostream &os, const Query &query)
{
	return os << query.rep();
}

class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const string &s) :query_word(s) { cout << "WordQuery参数默认构造函数" << endl; }   //参数默认构造函数
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }  //定义虚函数
	string rep() const { cout << "WordQuery的rep()" << endl; return query_word;}   //定义虚函数
	string query_word; 
};
inline Query::Query(const string &s):q(new WordQuery(s)){}  //对应Quote中建立对应的函数：建立一个新的word_query

class NotQuery : public Query_base
{
	friend Query operator~ (const Query &);
	NotQuery(const Query &q) :query(q){ cout << "NotQuery参数默认构造函数" << endl; }  //参数默认构造函数
	QueryResult eval(const TextQuery &) const;
	string rep() const { cout << "NotQuery的rep()" << endl; return "~(" + query.rep() + ")";}
	Query query;
};
inline Query operator~(const Query &operand) { return shared_ptr<Query_base>(new NotQuery(operand)); }
QueryResult NotQuery::eval(const TextQuery& text) const
{
	auto result = query.eval(text);  //通过Query运算对象对eval进行虚调用，这个result是QueryResult的对象
	auto ret_lines = make_shared<set<line_no>>();  //这是一个空的set
	auto beg = result.begin(), end = result.end();  //beg是指所查单词的出现行号begin迭代器，end即end迭代器
	auto sz = result.get_file()->size();  //得到输入文件的size大小
	for (size_t n = 0; n != sz; n++)   //一旦发现该行不在result中，则将其添加到ret_lines中
	{
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else
			if (beg != end)
				++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, string s) :lhs(l), rhs(r), opSym(s) { cout << "BinaryQuery参数默认构造函数" << endl; }
	//抽象类：BinaryQuote不定义eval
	string rep() const { cout << "BinaryQuery的rep()" << endl; return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	string opSym;
};

class AndQuery :public BinaryQuery
{
	friend Query operator &(const Query&, const Query &);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&"){ cout << "AndQuery参数默认构造函数" << endl; }
	//具体的类：AndQuery继承了rep并且定于了其他虚函数
	QueryResult eval(const TextQuery &) const;
};
inline Query operator&(const Query &lhs, const Query &rhs) { return shared_ptr<Query_base>(new AndQuery(lhs, rhs)); }
QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	//使用标准库算法来合并两个left与right中存放行数的set
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query &);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") { cout << "OrQuery参数默认构造函数" << endl; }
	//具体的类：AndQuery继承了rep并且定于了其他虚函数
	QueryResult eval(const TextQuery &) const;
};
inline Query operator|(const Query &lhs, const Query &rhs) { return shared_ptr<Query_base>(new OrQuery(lhs, rhs)); }
QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());   //把两个加在一起
	return QueryResult(rep(), ret_lines, left.get_file());
}

ostream &print_qr(ostream &os, const Query &q, ifstream &infile)  //用于打印数据
{
	auto qr = q.eval(TextQuery(infile));
	os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num << ") " << *(qr.file->begin() + num - 1) << endl;
	return os;
}

//void runQueries(ifstream &infile)  //统筹函数，用于输入数据，以及使其计算加打印
//{
//	TextQuery tq(infile);
//	while (true)
//	{
//		cout << "enter a word to look for,or q to quit: ";
//		string s;
//		if (!(cin >> s) || s == "q") break;
//		print(cout, tq.query(s)) << endl;
//	}
//}