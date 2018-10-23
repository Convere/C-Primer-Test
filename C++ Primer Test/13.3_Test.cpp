/*
#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
#include<algorithm>
using namespace std;

class HasPtr  //模板类   
{
public:
	friend bool operator<(const HasPtr &a, const HasPtr &b)
	{
		cout << "操作符<调用" << endl;
		return *a.ps < *b.ps;
	}
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) { cout << "默认构造函数" << endl; }   //接受一个字符串的默认构造函数
	HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) { cout << "拷贝构造函数" << endl; }  //拷贝构造函数 
	void swap(HasPtr &a, HasPtr &b)
	{
		using std::swap;
		swap(a.ps, b.ps);
		swap(a.i, b.i);
	}
	HasPtr& operator=(HasPtr &rhs) //拷贝赋值运算符=的构造函数  
	{
		swap(*this, rhs);  //拷贝与交换的赋值运算符
		cout << "swap型拷贝赋值运算符" << endl;
		return *this;
	}
	~HasPtr()  //练习13.10  //析构函数
	{
		delete ps; //必须delete对象ps，因为其是new的动态内存，需要手动释放
	}
	string *ps;
	int i;
};

int main()
{
	HasPtr a("time3");
	HasPtr b("mine2");
	//a = b;
	HasPtr c("life1");   //三个默认构造函数加一个swap拷贝赋值运算符
	vector<HasPtr> text{ a, b, c };   //六个拷贝构造函数
	sort(text.begin(), text.end());   //由于sort是一种排序算法， 其计算过程中不断交换赋值数值与临时变量赋值，所以swap拷贝赋值与拷贝构造函数各有一些
}//其中也包含了多次<符号的调用
*/