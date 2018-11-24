//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Widget
//{
//public:
//	Widget() = default;
//	Widget(const Widget&t) :a(t.a) { cout << "拷贝构造函数" << endl; }
//private:
//	int a = 0;
//};
//
//Widget f(Widget u)
//{
//	Widget v(u);
//	cout << "1" << endl;
//	Widget w = v;
//	cout << "2" << endl;
//	return w;
//}
//
////int main() 
////{
////	Widget x;
////	cout << " " << endl;
////	Widget y = f(f(x));
////}
//
////int main()  //网易的盒子题
////{
////	int H, W;
////	cin >> H >> W;
////	int m = H / 4, n = H % 4, sum = 0;
////	switch (n)
////	{
////	case 0:sum = 2 * m*W;
////		break;
////	case 1:sum = 2 * m*W + (W / 4) * 2 + ((W % 4 < 2) ? (W % 4) : 2);
////		break;
////	case 2:sum = 2 * m*W + (W / 4) * 4 + ((W % 4 < 2) ? (2 * (W % 4)) : 4);
////		break;
////	case 3:sum = 2 * m*W + (W / 4) * 6 + ((W % 4 < 3) ? (2 * (W % 4)) : 5);
////		break;
////	}
////	cout << sum << endl;
////}
//
////#include <iostream>
////using namespace std;
////
////static int num = 0;
////long f(long x)
////{
////	switch (rand() % 2)
////	{
////	case 0:
////		x = (4 * x + 3) % 1000000007;
////		break;
////	case 1:
////		x = (8 * x + 7) % 1000000007;
////		break;
////	}
////	num++;
////	return x;
////}
////
////int main()
////{
////	long x_0;
////	cin >> x_0;
////	while (num <= 100000)
////	{
////		x_0 = f(x_0);
////		if (x_0 % 1000000007 == 0)
////		{
////			cout << num << endl;
////			return 0;
////		}
////	}
////	int err = -1;
////	cout << err << endl;
////}
//
////int main()   //不断的降低总数    //网易的饥饿的小易
////{
////	long long x_0;
////	cin >> x_0;
////	long long temp = (4 * x_0 + 3) % 1000000007;
////	if (temp == 0)
////	{
////		cout << 1 << endl;
////		return 0;
////	}
////	for (int i = 3; i <= 300000; i++)
////	{
////		temp = (2*temp + 1) % 1000000007;
////		if (temp == 0)
////		{
////			if (i % 3 == 0)
////				cout << i / 3 << endl;
////			else
////				cout << 1 + (i / 3) << endl;
////			return 0;
////		}
////	}
////	cout << "not find" << endl;
////	cout << -1 << endl;
////	return 0;
////}
//
//int fib(int n)
//{
//	int f = 1, g = 0; //初始化：fib(0)、fib(-1)
//	while (0 < n--) { g += f; f = g - f; } //依据原始定义，通过n次加法和减法计算fib(n)
//	return g; //返回
//}
//
//
//
//
////int main()
////{
////	int N, s = 0;
////	cin >> N;
////	for (int n = 0; n<32; n++)
////	{
////		if (N>fib(n) && N<fib(n + 1))
////			s = (N - fib(n)>fib(n + 1) - N) ? fib(n + 1) - N : N - fib(n);
////	}
////	cout << s << endl;
////	return 0;
////}
//
//void f(vector<int> &a)
//{
//}
//
//int main()
//{
//	vector<int> a{ 1,2 };
//	f(a);
//	vector<int> b;
//	b = a;
//}