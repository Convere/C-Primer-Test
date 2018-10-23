/*#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
using namespace std;

class X
{
public:
	X(int temp) : a(temp)  //括号直接初始化   //实际上，默认构造函数是最为必须的，如果不自己定义，合成的默认构造函数常常会出问题
	{
		cout << "默认构造函数" << endl;
	}
	X(const X &temp):a(temp.a)  //拷贝构造函数/拷贝赋值运算符/析构函数 如果不自己定义，系统都会自动合成
	{
		cout << "拷贝构造函数" << endl;
	}
	X &operator=(const X &temp)
	{
		a = temp.a;
		cout << "拷贝赋值运算符" << endl;
		return *this;
	}
	~X()
	{
		cout << "析构函数" << endl;
	}
	int a;
};

int main()  //练习13.13
{
	X val1(1);
	X val2(2);
	X val3(3);
	//直接初始化
	X valx(val1);
	cout << "直接初始化" << val3.a << endl;  //非完全拷贝，以及默认构造函数的方式，通过其余方式达成的初始化，都是通过将数值赋予到对象之后得到的，即拷贝构造函数的初始化方式
	//拷贝
	val3 = val1;   
	cout << "拷贝" << val3.a << endl;  //同类型直接拷贝后会调用拷贝赋值运算符，在输出后销毁执行析构函数
	//引用
	X &yy_val1 = val1;
	cout << "引用" << yy_val1.a << endl;   //引用出的X类是不通过默认构造函数/拷贝构造函数/拷贝赋值运算符的，但是在输出后会析构（引用就是起别名，所以不会有任何初始化过程）
	//容器
	vector<X> m;
	m.push_back(val2);
	cout << "容器" << m[0].a << endl; //容器中的X类已经被定义，没有默认构造函数和拷贝赋值运算符，但在容器中定义时，对于其中的地址所指内容进行了拷贝构造函数，同时在输出时也不会使其析构，因为其仍存在于容器中，不应该被销毁
	//动态分配—直接赋值
	shared_ptr<X> val4 = make_shared<X>(4);//使用直接赋值时，此处智能指针会调用一次默认构造函数，并在输出后完成析构
	cout << "动态分配—直接赋值" << val4->a << endl;
	//动态分配—拷贝赋值
	shared_ptr<X> val5 = make_shared<X>(val2);//使用动态指针的拷贝赋值时，此处相当于*val5=val2，没有使用拷贝赋值运算符，因为前后的类型并不相同，即进行了一次拷贝构造函数，并在输出后完成析构
	cout << "动态分配—拷贝赋值" << val5->a << endl;

	//整个过程，输出6个值，共有4个默认构造函数，1个拷贝赋值运算符，3个拷贝构造函数，7个析构函数调用
}*/