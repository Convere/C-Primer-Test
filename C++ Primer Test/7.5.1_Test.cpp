/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Tree
{
public:
	Tree(string na,unsigned ag,double lo,double rad):name(na),age(ag),longth(lo),radius(rad){}
	Tree():Tree(" ",0,0,0){}
	Tree(istream &in) :Tree() { in >> name >> age >> longth >> radius; }
private:
	string name;
	unsigned age;
	double longth;
	double radius;
};*/