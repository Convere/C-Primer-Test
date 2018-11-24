#include "Ch4.h"
#include <vector>
#include <iostream>
using namespace std;

class ab
{
public:
	ab() {cout << "默认构造函数" << endl;}
	ab(int a) :t(a) { cout << "拷贝构造函数" << endl; }
	int t;
};

int main()
{
	ab a(4);
	cout << endl;
	ab b[1];
	cout << endl;
	ab *p[2];
	//int x1 = 1;
	//int x2 = 2;
	//int x3 = 3;
	//vector<int*> a{ &x1,&x2,&x3 };
	//cout << *a[0] << endl;
	//*a[0] = 3;
	//cout << x1 << endl;
	//unsigned short array[] = { 10,22,35,49,58,66,77 };
	//int i = 3;
	//cout<<&array[0];
}

//void Convert(Stack<char> &S, int n, int base)   //进制转换的递归法
//{
//	static char d[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//	if (n > 0)
//	{
//		S.push(d[n%base]);
//		Convert(S, n / base, base);
//	}
//}
//
//void Convert2(Stack<char> &S, int n, int base)  //进制转换的迭代法  个人觉得递归的运算效率远不如迭代，所以尽量避免递归
//{
//	static char d[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//	while (n > 0)
//	{
//		S.push(d[n%base]);
//		n /= base;
//	}
//}
//
//int main()
//{
//	Stack<char> S;
//	Convert2(S, 1000, 8);
//	S.print();
//}