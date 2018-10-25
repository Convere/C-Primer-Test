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

class StrVec
{
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}  //默认构造函数
	StrVec(initializer_list<string> &temp)   //initializer_list<string>的构造函数
	{
		auto newdata = alloc_n_copy(temp.begin(), temp.end());
		elements = newdata.first;
		first_free = cap = newdata.second;   //这里的=cap非常重要，即对cap重新赋值，不然会报错
	}
	StrVec(const StrVec&);  //拷贝构造函数的声明
	StrVec &operator=(const StrVec&);  //拷贝赋值运算符的声明
	~StrVec();  //析构函数的声明
	void push_back(const string&);  //拷贝元素的函数声明
	size_t size() const { return first_free - elements; }  //已用大小的函数声明
	size_t capacity() const { return cap - elements; }  //内存空间大小的函数声明
	string *begin() const { return elements; }   //指向首元素的指针，类似vector的begin
	string *end() const { return first_free; }	 //指向最后一位元素下一位的指针，类似vector的end
//private:
	allocator<string> alloc;  //存放string的未构造内存，用于分配元素
	void chk_n_alloc()	//用于在添加元素前，进行内存位置检查的函数
	{
		if (size() == capacity())reallocate();  //当所用内存大于最大内存时，自动分配新的空间
	}
	pair<string*, string*>alloc_n_copy(const string*, const string*); //分配足够的内存来保存给定范围内的元素，并将输入的这些元素保存到新的内存中
	void free();			//用于销毁元素并释放内存的函数
	void reallocate();		//用于获得更多内存并拷贝已有元素
	void reserve(size_t &);
	void resize(size_t &);
	string *elements;		//指向数组首元素的指针
	string *first_free;		//指向数组第一个空闲元素的指针
	string *cap;			//指向数组尾后位置的指针
};

StrVec::StrVec(const StrVec &s)   //拷贝构造函数
{
	auto newdata = alloc_n_copy(s.begin(), s.end());   //newdata被赋值，其为一个新的内存中指向最后一个元素后面的指针，即end。同时，该新内存中存储了s的数据
	elements = newdata.first;     //begin定义
	first_free = newdata.second;  //end定义
}

StrVec &StrVec::operator=(const StrVec &rhs)  //拷贝赋值运算符
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());  //分配新的内存，data保存了内存元素的begin和end
	free();  //清空将要定义的类元素
	elements = data.first;  //使用新内存的指针来初始化
	first_free = data.second;
	return *this;  //返回rhs中的string字符串
}

StrVec::~StrVec()  //析构函数
{
	free();
}

void StrVec::reserve(size_t &sz)
{
	auto newcapacity = sz;  //自定义内存大小
	auto newdata = alloc.allocate(newcapacity);  //将两倍大的内存分配到新内存中，其中newdata指向新内存的begin位置
	auto dest = newdata;  //dest即新内存的begin
	auto elem = elements; //elem为旧内存的begin
	if (sz >= size())  //sz与size大小比较，当其大于或等于时正常赋值，当其小于时则只拷贝sz所包含的部分
	{
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));  //从新内存的第一位开始，往内依次添加旧内存的元素
	}
	else
	{
		for (size_t i = 0; i != sz; ++i)
			alloc.construct(dest++, std::move(*elem++));  //从新内存的第一位开始，往内依次添加旧内存的元素
	}
	free(); //释放旧内存空间
	elements = newdata;
	first_free = dest;  //递增到最后，dest成为了新内存的end
	cap = elements + newcapacity;  //内存最大位置的指针，由开头指针加整体容量
}

void StrVec::resize(size_t &sz)
{
	if (sz >= size())
	{
		cap = first_free + sz;
		auto temp = first_free + (sz - size());
		first_free = temp;
	}
	else
	{
		auto temp = first_free - (size() - sz);
		first_free = temp;
	}
	chk_n_alloc();
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);  //alloc的构造，相当于向first_free指针所指的位置中添加字符串s
}

pair<string*, string*>StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);   //b是string的end指针，e是string的begin指针，其为alloc的分配，data指向分配的新内存的begin
	return{ data,uninitialized_copy(b,e,data) };  //返回指向所分配的内存的begin的指针data，后面的语句将b到e中的数据拷贝到data所指的内存中,并返回指向新内存最后一个元素之后位置的指针，即end
}

void StrVec::free()
{
	if (elements)
	{
		//for (auto p = first_free; p != elements;)   //先逆序销毁掉string中所包含的元素
			//alloc.destroy(--p);
		for_each(elements, first_free, [this](string &rhs) { alloc.destroy(&rhs); });//this是指向当前类的指针，从旧内存的开头到结尾，捕获alloc后，destroy指向当前位置所存的元素，rhs为一个指针
		alloc.deallocate(elements, cap - elements); //释放string所使用的内存（虽然此时删除了元素，但内存还在，其内为空）
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;  //两倍大的内存
	auto newdata = alloc.allocate(newcapacity);  //将两倍大的内存分配到新内存中，其中newdata指向新内存的begin位置
	auto dest = newdata;  //dest即新内存的begin
	auto elem = elements; //elem为旧内存的begin
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));  //从新内存的第一位开始，往内依次添加旧内存的元素
	free(); //释放旧内存空间
	elements = newdata;
	first_free = dest;  //递增到最后，dest成为了新内存的end
	cap = elements + newcapacity;  //内存最大位置的指针，由开头指针加整体容量
}

using line_no = vector<string>::size_type;

class QueryResult  //字符打印类
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<StrVec> f) :sought(s), lines(p), file(f) {}  //构造函数
private:
	string sought;  //保存查询的单词
	shared_ptr<set<line_no>> lines;  //指向单词出现的行号set；
	shared_ptr<StrVec> file; //指向保存每行输入文件的vector
};

class TextQuery  //字符处理类，通过输入文件，得到存储的每行数据，以及不同单词出现次数的数据。
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	TextQuery(ifstream&);//构造函数的声明，定义定在外部
	QueryResult query(const string&) const;
private:
	shared_ptr<StrVec> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) :file(new StrVec)
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
	initializer_list<string> temp{ "i","can","fly" };
	StrVec a(temp);
	a.push_back("me");
	a.push_back("and");
	a.push_back("you");
	size_t sz = 10;
	a.reserve(sz);
	//a.resize(sz);
	for (auto &s : a)
		cout << s << a.capacity() << a.size() << endl;
	//runQueries(ifstream("input_line.txt"));
}*/

//此类中的resize和reserve编写的仍不严谨，需要在学习移动构造函数后进行改进