//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//using namespace std;
//
//////声明+位置1
////namespace Exercise
////{
////	int ivar = 0;
////	double dvar = 0;
////	const int limit = 1000;
////}
////int ivar = 0;
//////位置1
////using Exercise::ivar;//错误，与全局变量ivar冲突，多次声明
////using Exercise::dvar;
////using Exercise::limit;
////void manip()
////{
////	//位置2
////	double dvar = 3.1416;
////	int iobj = limit + 1;
////	++ivar;
////	++::ivar;
////	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
////}
//
//////声明+位置2
////namespace Exercise
////{
////	int ivar = 0;
////	double dvar = 0;
////	const int limit = 1000;
////}
////int ivar = 0;
//////位置1
////
////void manip()
////{
////	//位置2
////	using Exercise::ivar;//隐藏全局变量
////	using Exercise::dvar;
////	using Exercise::limit;
////	double dvar = 3.1416;//错误，多重定义，多次初始化，当前dvar对象已经可见
////	int iobj = limit + 1;
////	++ivar;
////	++::ivar;
////	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
////}
//
//////指示+位置1
////namespace Exercise
////{
////	int ivar = 0;
////	double dvar = 0;
////	const int limit = 1000;
////}
////int ivar = 0;
//////位置1
////using namespace Exercise;
////void manip()
////{
////	//位置2
////	double dvar = 3.1416;
////	int iobj = limit + 1;
////	++ivar;  //二义性，不明确
////	++::ivar;
////	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
////}
//
////指示+位置2
//namespace Exercise
//{
//	int ivar = 0;
//	double dvar = 0;
//	const int limit = 1000;
//}
//int ivar = 0;
////位置1
//
//void manip()
//{
//	//位置2
//	using namespace Exercise;
//	double dvar = 3.1416;
//	int iobj = limit + 1;
//	++ivar;  //二义性，不明确
//	++::ivar;
//	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
//}
//
//int main()
//{
//	manip();
//	return 0;
//}