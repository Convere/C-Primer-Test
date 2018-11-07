//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
////#include "Sales_data.h"
//using namespace std;
//
//template<typename T> bool compare(const T &v1, const T &v2)
//{
//	if (v1 < v2) return true;
//	if (v2 < v1) return false;
//	return 0;
//}
//
//int main1() //练习16.2
//{
//	if (compare(3, 2))
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//	return 0;
//}
//
////int main2() //练习16.3  没有可接受的转换，Sales_data中没有<运算符的定义
////{
////	Sales_data s1, s2;
////	if (compare(s1, s2))
////		cout << "true" << endl;
////	else
////		cout << "false" << endl;
////	return 0;
////}
//
//template<typename I, typename V> I Find(const I &i1, const I &i2, const V &v2)
//{
//	I beg = i1;
//	for (; beg != i2; ++ beg)
//	{
//		if (*beg == v2)
//		{
//			cout << "Find it!" << endl;
//			return beg;
//		}
//	}
//	if (beg == i2)
//		cerr << "Not find!" << endl;
//}
//
//int main3()   //练习16.4
//{
//	vector<int> a{ 1,2,3,3,4,56,7 };
//	list<string> b{ "i","can","fly","sky" };
//	auto temp = Find(a.begin(), a.end(), 3);
//	auto temp2 = Find(b.begin(), b.end(), string("me"));
//	return 0;
//}
//
//template<typename A> void print(const A &arr)
//{
//	for (auto &s : arr)
//		cout << s << endl;
//}
//
//int main4()   //练习16.5
//{
//	int a[10] = { 1,2,3,3,3,3,5 };
//	string b[5] = { "i","can","fly","sky" };
//	print(a);
//	print(b);
//	return 0;
//}
//
//template<typename A, unsigned N> A* Begin(A(&arr)[N])
//{
//	return arr;
//}
//
//template<typename A, unsigned N> A* End(A(&arr)[N])
//{
//	return arr + N;
//}
//
//int main5()   //练习16.6
//{
//	int a[10] = { 1,2,3,3,3,3,5 };
//	string b[5] = { "i","can","fly","sky" };
//	auto beg = Begin(a);
//	auto end = End(a);
//	for (; beg != end; ++beg)
//		cout << *beg << endl;
//	return 0;
//}
//
//template <typename T, unsigned N> constexpr unsigned SizeOfArray(const T(&arr)[N])
//{
//	return N;
//}
//
//int main()   //练习16.7
//{
//	int a[10] = { 1,2,3,3,3,3,5 };
//	string b[5] = { "i","can","fly","sky" };
//	auto temp = SizeOfArray(a);
//	auto temp2 = SizeOfArray(b);
//	cout << temp << temp2 << endl;
//}