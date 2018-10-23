/*#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
using namespace std;

class Employee
{
public:
	Employee() {};  //默认的空构造函数
	Employee(const string &name)  //接受字符串的默认构造函数
	{
		Emname = name;
		static int temp = 10000;
		Emnum = temp++;
	}
	Employee(const Employee &temp) = delete;   //拷贝构造函数的定义，需要声明，但是不需要其功能，所以直接delete
	Employee &operator=(const Employee &temp) = delete;  //拷贝赋值运算符的定义，需要声明，但是不需要其功能，所以直接delete
	~Employee() = default;    //析构函数的声明，设其为默认值
	string Emname;
	int Emnum;
};

int main()   //练习13.18
{
	Employee jeck;
	Employee jack("jack"), mike("mike");
	cout << jack.Emname << " " << jack.Emnum << endl;
	cout << mike.Emname << " " << mike.Emnum << endl;
}*/