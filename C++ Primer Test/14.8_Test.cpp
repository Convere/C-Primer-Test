/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <istream>
using namespace std;

class IFE    //练习14.34
{
public:
	int &operator()(bool a, int b, int c) { return a ? b : c; }
private:
	bool condition;
	string yes;
	string no;
};

class PrintString  //练习14.35与14.36
{
public:
	PrintString(istream &i = cin) :in(i){}
	string operator()() const
	{
		string temp;
		getline(in, temp);
		return in ? temp : string();
	}
private:
	istream &in;
};

class EQ   //练习14.37
{
public:
	//EQ() { cout << "无参构造函数" << endl; }
	EQ(int a = 0, int b = 0) :num1(a), num2(b) { cout << "默认构造函数" << endl; }
	EQ(int &a, int&b) :num1(a), num2(b) { cout << "带参数的构造函数" << endl; }
	bool operator()(int a, int b) const { return (a == b); }
private:
	int num1 = 0;
	int num2 = 0;
};

int main()
{
	PrintString a;
	cout << a() << endl;
	vector<string> b;
	for (std::string tmp; !(tmp = a()).empty();) b.push_back(tmp);
	for (auto &s : b)
		cout << s << endl;
	int ob_num = 1;
	int cg_num = 3;
	EQ change;
	vector<int> place{ 1,2,3,4,4,2,1,13,5 };
	cout << "before:";
	for (auto &s : place)
	{
		cout << s << " ";
		if (change(s, ob_num))
			s = cg_num;
	}
	cout << endl;
	cout << "after:";
	for (auto &s : place)
		cout << s << " ";
	cout << endl;
	return 0;
}*/

//创建类对象时
//i)类名 对象名：默认调用“对象名()”这个构造函数，在栈内存中存在对象名，在堆内存中存在实际对象；

//ii)类名 对象名(一个或以上个参数)：默认调用相应的构造函数，在栈内存中存在对象名，在堆内存中也是存在实际对象的；

//iii)类名 对象名()：不调用任何构造函数创建对象，仅在栈内在中存在对象名，在堆内存中并不存在实际的对象；