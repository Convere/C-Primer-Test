//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//using namespace std;
//
//
//namespace p
//{
//	void compute(int) { cout << "p int" << endl; }   //声明时，同形参类型与数量会打架
//	void compute(){cout << "空"<<endl; }//不可行  
//	void compute(const void *) { cout <<"const void *"<< endl; }//可行,0->NULL  
//}
//using namespace p;
////using p::compute;
//void compute(int) { cout << "int"<<endl; }//可行,最佳匹配  
//void compute(double, double = 1.1) { cout <<"double"<< endl; }//可行,int->double  
//void compute(char*, char* = 0) { cout << "char*"<<endl; }//可行,0->NULL  
////using p::compute;
//void f()
//{
//	//using p::compute;
//	//compute(0);//与compute(int)版本最佳匹配  
//	p::compute(0);
//}
//
//int main()   //练习18.20
//{
//	f();
//}
//
////总结：using声明时，当其处于局部作用域，会隐藏掉外部作用域的函数与变量，局部作用域中使用的是声明的，外部作用域使用的是自己的；
////但是当声明在外部作用域时，会和其他同形参类型与数量的函数，以及同样的变量打架，因为重定义了。其他不同形参的函数会重载
////using指示时，其作用域一直为全部程序，其他不同形参的函数会重载。但其与其他同形参类型与数量的函数，以及同样的变量打架，因为是二义性。
////不过可以通过在调用变量或函数时注明清楚是全局范围定义的还是命名空间定义的即可解决问题。