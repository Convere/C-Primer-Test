#include <iostream>
#include <cmath>
#include <Shape.h>
#include <time.h>
#include <string>
#include <algorithm>
using namespace std;

class EX
{
	static int b;
	int a = 0;
public:
	EX() { b++; }
	~EX() { b--; }
	static int sum(int &t) { return b + t; }
	int getb() { return b; }
};

int EX::b = 0;  //定义EX的静态成员变量的数值

int main_exclass()
{
	EX ex1;
	EX ex2;
	int t = 2;
	cout << ex1.getb() << ex2.getb() << EX::sum(t) << endl;
	return 0;
}

double arctan(double x)
{
	double sum = 0.0;
	int i = 1;
	while ((pow(x, i) / i) > 1e-15)
	{
		int p = (i % 4 == 1) ? 1 : -1;
		sum += p*pow(x, i) / i;
		i += 2;
	}
	return sum;
}

int main_calpi()
{
	double pi = 16 * arctan(1 / 5.0) - 4 * arctan(1 / 239.0);  //这里有个天大的陷阱，1/5与1/239必须做到加.0，不然算出来都为0
	cout << pi << endl;
	return 0;
}

bool find_hw(int n)
{
	int t = n, s = 0;
	while (t > 0)
	{
		s = s * 10 + t % 10;
		t = t / 10;
	}
	return n == s;
}

int main_findhw()
{
	int m = 11;
	while (m <= 999)
	{
		if (find_hw(m) && find_hw(m*m) && find_hw(m*m*m))
			cout << "回文数为：" << m << endl;
		m++;
	}
	return 0;
}

int JC(int n)
{
	int sum = 1;
	for (int i = 1; i <= n; i++)
		sum *= i;
	return sum;
}

const double tiny_value = 1e-6;
double sin(double x)
{
	double g = 0.0; double t = x; int n = 1;
	while (fabs(t) >= tiny_value)
	{
		g += t;
		n++;
		t = -t*x*x / (2 * n - 1) / (2 * n - 2);
		cout << g << endl;
		cout << n << endl;
	} 
	return g;
}

int mainsinqiujie()
{
	double r, s, k;
	cin >> r >> s;
	if (r*r <= s*s)
		k = sqrt(sin(r)*sin(r) + sin(s)*sin(s));
	else
		k = 0.5*sin(r*s);
	cout << k << endl;
	return 0;
}

class base1
{
public:
	/*base1() = default; */ //默认构造函数
	base1() {}
	base1(int val) :val1(val) { cout << "base1 cf" << endl; }  //参数构造函数
	int val1 = 1;
	void fun1() {}
};

class base2
{
public:
	base2() {}   //默认构造函数
	base2(int val) :val2(val) { cout << "base2 cf" << endl; }  //参数构造函数
	int val2 = 2;
	void fun2() {}
};

class base3 :public base2 , public base1
{
public:
	base3() {cout << "默认构造函数" << endl;}
	base3(int vala, int valb, int valc) :base1(vala), base2(valb), val3(valc) { cout << "多参数默认构造函数" << endl; }
	base3(int vala) :val3(vala) { cout << "单参数默认构造函数" << endl; }
	base3(const base3 &b3) :val3(b3.val3) { cout << "拷贝构造函数" << endl; }
	base3(base3 &&b3) noexcept { val3 = std::move(b3.val3); cout << "移动构造函数" << endl; }
	base3 &operator=(const base3 &b3) { val3 = b3.val3; cout << "拷贝赋值运算符" << endl; return *this; }
	base3 &operator=(base3 &&b3) noexcept {if (this != &b3) val3 = std::move(b3.val3); cout << "移动赋值运算符" << endl; return *this;}
	~base3() { cout << "析构函数" << endl; }
	//base3(int vala) :val3(vala) {}
	int val3;
	void fun1() { }
};

int main_EXXX()
{
	clock_t start, finish;
	double totaltime;
	start = clock();

	//circle c1("c1", 10);
	//c1.print();
	base3 b31(5,6,7);
	base3 b32(10);
	base3 b33(20);
	base3 b34(0);
	b34 = b33;
	base3 b35(b32);
	cout << endl;
	vector<base3> save;
	save.push_back(b31);
	save.push_back(b32);
	save.push_back(b33);
	save.push_back(b34);
	save.push_back(b35);
	save.push_back(b31);
	save.push_back(b32);
	save.push_back(b33);
	save.push_back(b34);
	save.push_back(b35);
	save.push_back(b31);
	save.push_back(b32);
	save.push_back(b33);
	save.push_back(b34);
	save.push_back(b35);
	for (auto &s : save)
		cout << s.val3 << endl;
	cout << b31.val1 << b31.val2<< b31.val3 << endl;

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	return 0;
}

int main_midcal()
{
	int num;
	vector<int> a;
	while (cin >> num)
		a.push_back(num);
	sort(a.begin(), a.end());
	int mid = (a.front() + a.back())/2;
	for (auto &s : a)
	{
		if (s <= mid)
			cout << "<=mid " << s << endl;
		else
			cout << ">mid " << s << endl;
	}
	return 0;
}

bool hw(string &a)
{
	auto len = a.length();
	for (int i = 0; i < len; i++)
	{
		if (a[i] != a[len - 1])
			return false;
		len = len - 1;
	}
	return true;
}

int mainhwscal()
{
	string a; string b; int sum = 0;
	cin >> a>> b;
	auto temp = a;
	auto len = a.length() + 1;   //最好不要把函数计算结果放在循环判断语句里面
	for (int i = 0; i < len ; i++)
	{
		a = temp;
		a.insert(i, b);
		if (hw(a))
			sum++;
	}
	cout << sum << endl;
	return 0;
}

//template<class T> T square(T x)
//{
//	return x*x;
//}
//
//int main()
//{
//	cout << square(5) << endl;
//}