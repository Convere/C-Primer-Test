//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <cstdlib>
//using namespace std;
//
//void *operator new(size_t size)
//{
//	cout << "operator new ²Ù×÷·û" << endl;
//	if (void *mem = malloc(size))
//		return mem;
//	else
//		throw bad_alloc();
//}
//void operator delete(void *mem) noexcept
//{
//	cout << "operator delete ²Ù×÷·û" << endl;
//	free(mem);
//}
//
//int main()   //Á·Ï°19.1
//{
//	size_t val = 7;
//	cout << val << &val << endl;
//	size_t *a = new size_t(val);
//	cout << *a << a << endl;
//	delete a;
//	return 0;
//}