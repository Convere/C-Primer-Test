//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//using namespace std;
//
//struct Base1    //练习18.27
//{
//	void print(int) const;    //默认情况下是公有的
//protected:
//	int ival;
//	double dval;
//	char cval;
//private:
//	int *id;
//};
//
//struct Base2
//{
//	void print(double) const;
//protected:
//	double fval;
//private:
//	double dval;
//};
//struct Derived : public Base1
//{
//	void print(std::string) const;
//protected:
//	std::string sval;
//	double dval;
//};
//
//struct MI : public Derived, public Base2
//{
//	void print(std::vector<double>);
//protected:
//	int *ival;
//	std::vector<double> dvec;
//	int ival;
//	double dval;
//	void MI::foo(double cval)
//	{
//		int dval;
//		dval = Base1::dval + Derived::dval;  //(c)
//		Base2::fval = dvec.back();  //(d)
//		Base1::cval = Derived::sval[0];  //(e)
//	}
//};
//
