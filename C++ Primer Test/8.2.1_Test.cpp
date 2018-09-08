#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*void fun(const string &file, vector<string> &word)     //运行结果一直都是无法打开文件，因为压根就没有mfile这个文件存在
{
	ifstream in(file);
	if (in)
	{
		string temp;
		while (getline(cin, temp))
			word.push_back(temp);
	}
	else
		cerr << "无法打开文件！" << endl;
	for (auto &s : word)
		cout << s << endl;
}

int main()           //练习8.4
{
	string mfile{ "1.txt" };
	vector<string> mword;
	fun(mfile,mword);
}*/

/*void fun(const string &file, vector<string> &word)
{
	ifstream in(file);
	if (in)
	{
		string temp;
		while (cin >> temp)   //单个单词输入   //单个字母输入应该是char temp；或者把单词的遍历循环拆成字母的
			word.push_back(temp);
	}
	else
		cerr << "无法打开文件！" << endl;
	for (auto &s : word)
		cout << s << endl;
}

int main()           //练习8.5
{
	string mfile{ "1.txt" };
	vector<string> mword;
	fun(mfile, mword);
}*/

/*struct Sales_data  //练习8.6
{
	friend istream &read(istream&is, Sales_data&item);              //友元函数的声明，用于使相关函数调用private对象
	friend ostream &print(ostream&os, const Sales_data&item);
	friend Sales_data add(const Sales_data&lhs, const Sales_data&rhs);
public:
	//构造函数
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s), units_sold(0), revenue(0) {}
	Sales_data(istream &);
	string isbn() const { return bookNo; }   //函数isbn在类中的声明与定义，其返回对应的bookNo
	Sales_data& combine(const Sales_data&);  //函数combine在类中的声明，用于将括号中的类与其主类的数值相加
	double avg_price() const;                //函数avg_price在类中的声明，用于计算某类中的商品价格平均值
    //构造函数即以上
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&lhs, const Sales_data&rhs)  //非类成员函数add的定义，用于将二类中的数据加入一类中，然后返回一类的值
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream&os, const Sales_data&item)  //非类成员函数print的定义，用于输出某类中的isbn号（bookNo）,单价，总价以及平均价格
{
	os << "上一批书的编号为：" << item.isbn() << " 销量为：" << item.units_sold << " 总价为：" << item.revenue << " 平均价格为：" << item.avg_price() << endl;
	return os;
}

istream &read(istream&is, Sales_data&item)  //非类成员函数read的定义，用于将输入流中的编号，销量，单价，并计算出总价，然后返回数据到类中
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

Sales_data::Sales_data(istream &is)  //istream为参数的构造函数
{
	read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs) //类成员函数combine的定义，其类型为Sales_data的类类型
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const  //成员函数avg_price的定义，其类型为double的数据类型，返回值直接为商品单价
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int main(int argc, char** argv)
{
	Sales_data total;
	string file1 = "book.txt";  //在当前文件夹下设立文件，输入的数据加入在输入文件中，结果会被打印到输出文件中
	string file2 = "out.txt";
	ifstream input(file1);
	//ofstream output(file2);
	ofstream output;
	output.open("file2", ofstream::app);
	if (read(input, total))
	{
		Sales_data add;
		while (read(input, add))
		{
			if (add.isbn() == total.isbn())
			{
				total.combine(add);      //调用total类的函数中的combine函数，返回值this返回打total的成员函数中
			}
			else
			{
				print(output, total);
				total = add;
			}
		}
		print(output, total);
	}
	else {
		cerr << "No Data" << endl;
		return -1;
	}
	return 0;
}*/