#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>
#include <memory>
using namespace std;
typedef string::size_type pos;

template <pos, pos> class Screen;   //运算符参数所需要使用的
template <pos H, pos W> istream& operator>>(istream&, Screen<H, W>&);
template <pos H, pos W> ostream& operator<<(ostream&, const Screen<H, W>&);

template<pos H, pos W> class Screen
{
	friend istream& operator>><H, W>(istream&, Screen<H, W>&);
	friend ostream& operator<<<H, W>(ostream&, const Screen<H, W>&);
public:
	//构造函数
	Screen() = default;
	Screen(char c) : contents(H*W, c) {}
	//构造函数
	char get() const { return contents[cursor]; }   //函数get的声明，返回光标当前位置
	inline char get(pos r, pos c)const { pos row = r*W; return contents[row + c]; }   //函数get的重载声明，返回由行号和列号确定位置的字符
	inline Screen &move(pos r, pos c);      //函数move的声明，用于移动光标位置
	void some_member() const;  //函数some_member的声明，用于记录成员函数调用的次数
	inline Screen &set(char);  //函数set的声明，用于设置当前光标所在位置的新值
	inline Screen &set(pos, pos, char);  //函数set的重载声明，用于设置给定光标位置的新值
	inline Screen &display(ostream &os) { do_display(os); return *this; }  //函数display的声明与定义，用于显示非常量版本的screen对象
	const Screen &display(ostream &os)const { do_display(os); return *this; }  //函数display的重载声明与定义，用于显示常量版本的screen对象
private:
	pos cursor = 0;  //光标的位置
	pos height = H, width = W;  //屏幕的高与宽
	string contents;  //用于保存Screen的内容
	mutable size_t access_ctr;   //定义一个可变量用于计数
								 //void do_display(ostream &os)const { os << contents; }  //函数do_display的声明与定义，用于执行display函数中的输出操作
	void do_display(ostream &os)const   //函数do_display的声明与定义，用于执行display函数中的输出操作
	{
		for (pos i = 0; i != H; ++i)
		{
			for (pos j = 0; j != W; ++j)
				//os << (contents[i*W + j]);
				os << get(i, j);
			os << endl;
		}
	}
};

template <pos H, pos W> istream& operator>>(istream&is, Screen<H, W>&s)
{
	string input;
	is >> input;
	for (char ch : input)
		s.set(ch);
	return is;
}
template <pos H, pos W> ostream& operator<<(ostream&os, const Screen<H, W>&s)
{
	for (pos i = 0; i != H; ++i)
	{
		for (pos j = 0; j != W; ++j)
			//os << (contents[i*W + j]);
			os << s.get(i, j);
		os << endl;
	}
	return os;
}

template<pos H, pos W> inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
	pos row = r*W;   //计算行的位置
	cursor = row + c;    //在行内将光标移动到指定的列
	return *this;
}

template<pos H, pos W> void Screen<H, W>::some_member() const
{
	++access_ctr;
}

template<pos H, pos W> inline Screen<H, W> &Screen<H,W>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template<pos H, pos W> inline Screen<H, W> &Screen<H, W>::set(pos r, pos col, char ch)
{
	contents[r*W + col] = ch;
	return *this;
}
