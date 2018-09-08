/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Account
{
	friend istream &read(istream&is, Account&item);
	friend ostream &print(ostream&os, const Account &item);
public:
	void calculate() { amount += amount*interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 0.42;   //定义今日利率
	static double initRate() { return todayRate; }   //initRate函数的声明与定义，用于返回今日利率值
};

double Account::interestRate = initRate();  //类中静态成员interestRate的初始化，其被赋值今日利率值

void Account::rate(double newRate)
{
	interestRate = newRate;
}

istream &read(istream&is, Account&item)  //非类成员函数read的定义，用于输入某类中姓名和地址
{
	cout << "依次输入姓名与本金：" << endl;
	is >> item.owner >> item.amount;
	return is;
}

ostream &print(ostream&os, const Account &item)  //非类成员函数print的定义，用于输出某类中姓名与地址
{
	os << "姓名为：" << item.owner << " 存后总额为：" << item.amount << endl;
	return os;
}

int main()
{
	Account D7_31;
	Account::rate(0.5);   //手动更改利率初始值
	read(cin, D7_31);
	D7_31.calculate();
	print(cout, D7_31);
}*/