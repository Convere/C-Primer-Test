/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*istream &fun(istringstream& is)
{
	string word;
	while (is >> word)
	{
		cout << word << endl;
	}
	is.clear();
	return is;
}

int main()  //练习8.9
{
	string file = "8.3.1.txt";
	vector<string> text;
	ifstream in(file);
	istringstream word("hello world!");
	fun(word);
}*/


/*int main()   //练习8.10
{
	string file = "8.3.1.txt";
	vector<string> text;
	ifstream in(file);

	if (in)  //检查文件的读取是否成功,养成良好的习惯！
	{
		string buf;
		while (in >> buf)  //每个单词的独立输入，自动以空格为间隔
		{
			text.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << file << endl;
	}
	for (auto &s : text)
	{
		istringstream record(s);
		string temp;
		while(record >> temp)
			cout << temp << endl;
	}
	return 0;
}*/

/*struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{
	string file1 = "8.3.1.txt";
	string file2 = "8.3.1_out.txt";
	ifstream in(file1);
	ofstream out(file2);
	string line, word;
	vector<PersonInfo> people;
	istringstream record;  //外部定义字符流的读取

	if (in)
	{
		while (getline(in, line))  //从文件file1中输入数据;in>>line效果为全部单行，getline函数效果为根据输入的换行符才换行
		{
			PersonInfo info;
			record.clear(); //循环内部复位
			record.str(line);//绑定line与record
			record >> info.name;  //只读取一次，从而读取第一位数据
			while (record >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}
	}
	for (const auto &s : people)
	{
		out << "用户名为：" << s.name;   //由于ofstream也是IO对象，所以直接将常规的cout输出改成对应的of对象out输出，即可实现文件输出
		for (const auto &s2 : s.phones)
			out << "  电话号码为：" << s2;
		out << endl;
	}
	return 0;
}*/