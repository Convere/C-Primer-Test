//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//#include <initializer_list>
//#include "Blob_MB_Copy.h"
//using namespace std;
//
//class DebugDelete
//{
//public:
//	DebugDelete(ostream &s = cerr) :os(s) {};
//	template<typename T> void operator()(T *p) const { os << "deleting unique_ptr" << endl; delete p; }
//private:
//	ostream &os;
//};
//
//int main1()  //练习16.22
//{
//	double* p = new double(8.0);
//	DebugDelete d;
//	d(p);
//
//	int* ip = new int;
//	DebugDelete()(ip);
//
//	std::unique_ptr<int, DebugDelete> up(new int, DebugDelete());
//	std::unique_ptr<string, DebugDelete> usp(new string, DebugDelete());
//
//	return 0;
//}
//
//class TextQuery  //字符处理类，通过输入文件，得到存储的每行数据，以及不同单词出现次数的数据。  //练习16.23
//{
//public:
//	TextQuery(ifstream&);//构造函数的声明，定义定在外部
//private:
//	shared_ptr<vector<string>> file;
//};
//TextQuery::TextQuery(ifstream &is) :file(new vector<string>, DebugDelete()) {};
//
//template<typename T> void print(T &t)
//{
//	for (auto beg = t.begin(); beg != t.end(); ++beg)
//		cout << *beg << " ";
//	cout << endl;
//}
//
//int main()  //练习16.24
//{
//	Blob<string> bb1{ "i","can","fly","sky" };
//	print(*(bb1.data));
//	vector<string> bb2{ "you","can","fly","sky" };
//	print(bb2);
//	Blob<string> ex2(bb2.begin(), bb2.end());
//	print(*(ex2.data));
//}
//
////int main()
////{
////	Blob<std::string> sb1{ "a", "b", "c" };
////	Blob<std::string> sb2 = sb1;
////
////	sb2[2] = "b";
////
////	if (sb1 > sb2) 
////	{
////		for (auto iter = sb2.cbegin(); iter != sb2.cend(); ++iter) 
////		{
////			std::cout << *iter << " ";
////		}
////		std::cout << std::endl;
////	}
////
////	ConstBlobPtr<std::string> iter(sb2);
////	std::cout << iter->size() << std::endl;
////
////	std::vector<std::string> vec{ "good", "for", "you" };
////	Blob<std::string> sb3(vec.begin(), vec.end());
////
////	for (auto &s : *(sb3.data)) 
////	{
////		std::cout << s << " ";
////	}
////	std::cout << "\n";
////}