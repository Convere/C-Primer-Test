/*#include<iostream>  
#include<string>  
#include<vector>  
using namespace std;

class HasPtr  //模板类   
{
	
	HasPtr(const HasPtr &rhs) : ps(new string (*rhs.ps)), i(rhs.i) {}  //拷贝构造函数  //练习13.5 
	HasPtr& operator=(const HasPtr &rhs)  //拷贝赋值运算符=的构造函数    //练习13.8
	{
		string *p = new string(*rhs.ps);
		delete ps;
		ps = p;
		i = rhs.i;
		return *this;
	}
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}   //类成员的直接初始化，ps默认是一个指针，指向一个s的字符串；i默认为0
	~HasPtr()  //练习13.10  //析构函数
	{
		delete ps; //必须delete对象ps，因为其是new的动态内存，需要手动释放
	}
private:
	string *ps;
	int i;
};*/

