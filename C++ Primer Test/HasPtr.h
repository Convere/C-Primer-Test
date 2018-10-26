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

	HasPtr(HasPtr &&rhs) noexcept:ps(new string(*rhs.ps)), i(rhs.i)   //移动构造函数
	{
		rhs.ps = nullptr;
		rhs.i = 0;
		cout << "移动构造函数" << endl;
	}

	void swap(HasPtr &a, HasPtr &b)
	{
		using std::swap;
		swap(a.ps, b.ps);
		swap(a.i, b.i);
	}

	HasPtr& operator=(HasPtr &rhs) //拷贝赋值运算符=的构造函数  //此处不能加引号，因为要直接赋值更改数据（使用swap时）
	{							   //此处使用swap时不能加引号，因为其需要拷贝赋值；在进行传统拷贝赋值运算符定义时，加引号，进行引用传递
		//swap(*this, rhs);  //拷贝并交换的赋值运算符
		delete ps;
		ps = new string(*rhs.ps);  //还是使用传统的拷贝赋值顺手
		i = rhs.i;
		cout << "拷贝赋值运算符" << endl;
		return *this;
	}

	HasPtr& operator=(HasPtr &&rhs) noexcept   //移动赋值运算符
	{
		if (this != &rhs)
		{
			delete ps;
			ps = new string(*rhs.ps);
			i = rhs.i;
		}
		cout << "移动赋值运算符" << endl;
		return *this;
	}

	~HasPtr()  //练习13.10  //析构函数
	{
		delete ps; //必须delete对象ps，因为其是new的动态内存，需要手动释放
	}
//private:
	string *ps;
	int i;
};