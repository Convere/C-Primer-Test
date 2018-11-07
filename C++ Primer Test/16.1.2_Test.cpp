//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//#include <initializer_list>
//#include "StrVec_MB_Copy.h"
////#include <Screen_Mb.h>
////#include <Screen.h>
////#include "Blob_MB.h"
////#include "Blob_MB_Copy.h"
//using namespace std;
//
////int main1()   //Á·Ï°16.12
////{
////	Blob<int> sq = { 0,1,2,3,4,5,6,7,8,9 };
////	for (size_t i = 0; i != sq.size(); ++i)
////	{
////		sq[i] = i*i;
////		cout << sq[i] << endl;
////	}
////	return 0;
////}
//
////int main2()   //Á·Ï°16.12
////{
////	Blob<string> sb1{ "a", "b", "c" };
////	Blob<string> sb2 = sb1;
////
////	sb2[2] = "b";
////
////	if (sb1 > sb2) 
////	{
////		for (auto iter = sb2.cbegin(); iter != sb2.cend(); ++iter)
////			std::cout << *iter << " ";
////		std::cout << std::endl;
////	}
////
////	ConstBlobPtr<std::string> iter(sb2);
////	std::cout << iter->size() << std::endl;
////	return 0;
////}
//
////int main3()  //Á·Ï°16.14
////{
////	Screen<16, 32> myScreen('1');
////	//myScreen.display(cout);
////	cout << myScreen;
////	cout << "\n";
////	myScreen.move(12, 1);
////	cin >> myScreen;
////	cout << myScreen;
////	//myScreen.move(12, 1).set('#').display(cout);
////	//cout << "\n";
////	return 0;
////}
////int main4()   //Á·Ï°16.15
////{
////	Screen<5, 5> screen('x');
////	screen.set(2, 2, 'o');
////	std::cout << screen << std::endl;
////
////	std::cout << "please input some characters as you like:";
////	std::cin >> screen;
////	std::cout << screen << std::endl;
////
////	return 0;
////}
//
//int main()
//{
//	Vec<std::string> vec;
//	vec.reserve(6);
//	std::cout << "capacity(reserve to 6): " << vec.capacity() << std::endl;
//
//	vec.reserve(4);
//	std::cout << "capacity(reserve to 4): " << vec.capacity() << std::endl;
//
//	vec.push_back("hello");
//	vec.push_back("world");
//
//	vec.resize(4);
//
//	for (auto i = vec.begin(); i != vec.end(); ++i)
//		std::cout << *i << std::endl;
//	std::cout << "-EOF-" << std::endl;
//
//	vec.resize(1);
//
//	for (auto i = vec.begin(); i != vec.end(); ++i)
//		std::cout << *i << std::endl;
//	std::cout << "-EOF-" << std::endl;
//
//	Vec<std::string> vec_list{ "hello", "world", "pezy" };
//
//	for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
//		std::cout << *i << " ";
//	std::cout << std::endl;
//
//	// Test operator==
//
//	const Vec<std::string> const_vec_list{ "hello", "world", "pezy" };
//	if (vec_list == const_vec_list)
//		for (const auto& str : const_vec_list) std::cout << str << " ";
//	std::cout << std::endl;
//
//	// Test operator<
//	const Vec<std::string> const_vec_list_small{ "hello", "pezy", "ok" };
//	std::cout << (const_vec_list_small < const_vec_list) << std::endl;
//
//	// Test []
//	std::cout << const_vec_list_small[1] << std::endl;
//}