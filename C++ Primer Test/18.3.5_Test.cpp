//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//using namespace std;
//
//class Class{};
//class Base : public Class
//{
//public:
//	Base() :bval(0), Class() {}
//	Base(int &i) :bval(i),Class() {}
//	Base(const Base &temp) :bval(temp.bval) {}
//protected:
//	int bval;
//};
//
//class D1 :public virtual Base 
//{
//public:
//	D1() :Base() {}
//	D1(const D1 &b) = default;
//	D1(int a) :Base(a) {}
//};
//class D2 :public virtual Base 
//{
//public:
//	D2() :Base() {}
//	D2(const D2 &b) = default;
//	D2(int a) :Base(a) {}
//};
//class MI :public D1, public D2 
//{
//public:
//	MI() = default;
//	MI(const MI &m) :Base(m), D1(m), D2(m) {}
//	MI(int i) :Base(i), D1(i), D2(i) {}
//};
//class Final :public MI, public Class 
//{
//public:
//	Final() = default;
//	Final(const Final &f) :Base(f), MI(f), Class() {}
//	Final(int i) : Base(i), Class() {}
//};
//
//int main()
//{
//	Final a(7);
//}