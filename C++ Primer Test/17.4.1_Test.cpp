//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <algorithm>  
//#include <istream>
//#include <memory>
//#include <initializer_list>
//#include <random>
//using namespace::std;
//
//unsigned randui()
//{
//	static uniform_int_distribution<unsigned> u(0, 9);
//	static default_random_engine e;
//	return u(e);
//}
//
//unsigned randui(unsigned seed)
//{
//	static std::default_random_engine e(seed);
//	static std::uniform_int_distribution<unsigned> u;
//	return u(e);
//}
//
//unsigned randui(unsigned min, unsigned max)
//{
//	static std::default_random_engine e;
//	static std::uniform_int_distribution<unsigned> u(min, max);
//	return u(e);
//}
//
//unsigned randui(unsigned seed, unsigned min, unsigned max)
//{
//	static std::default_random_engine e(seed);
//	static std::uniform_int_distribution<unsigned> u(min, max);
//	return u(e);
//}
//
//int main()  //Á·Ï°17.28-17.30
//{
//	//default_random_engine e;
//	//for (size_t i = 0; i < 10; ++i)
//	//	cout << e() << endl;
//	//static uniform_int_distribution<unsigned> u(0, 9);
//	//static default_random_engine e;
//	//for (size_t i = 0; i < 10; ++i)
//	//	cout << u(e) << endl;
//	for (size_t i = 0; i < 10; ++i)
//		cout << randui() << " ";
//	cout << endl;
//	for (size_t i = 0; i < 10; ++i)
//		cout << randui(30) << " ";
//	cout << endl;
//	for (size_t i = 0; i < 10; ++i)
//		cout << randui(1,100) << " ";
//	cout << endl;
//	for (size_t i = 0; i < 10; ++i)
//		cout << randui(30,1,100) << " ";
//
//}