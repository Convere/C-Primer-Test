#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <memory>
using namespace std;

class Shape
{
public:
	Shape(){}
	virtual ~Shape() {}
	virtual double Area() = 0;
};

double Total(vector<Shape*> s)
{
	double sum = 0.0;
	for (size_t i = 0; i < s.size(); ++i)
		sum += s[i]->Area();
	return sum;
}

class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(double a, double b) : width(a), longth(b) {}
	Rectangle(const Rectangle &temp) : width(temp.width), longth(temp.longth) {}
	double Area() override { return width*longth; }
	~Rectangle()override {}
private:
	double width = 0.0;
	double longth = 0.0;
};

class Square : public Shape
{
public:
	Square() = default;
	Square(double a) : side(a) {}
	Square(const Square &temp) : side(temp.side) {}
	double Area() override { return side*side; }
	~Square()override {}
private:
	double side = 0.0;
};

static const float PI = 3.14159f;
class Circle : public Shape
{
public:
	Circle() = default;
	Circle(double a) : radius(a) {}
	Circle(const Circle &temp) : radius(temp.radius) {}
	double Area() override { return radius*radius*PI; }
	~Circle()override {}
private:
	double radius = 0.0;
};

int main_Shape()
{
	Rectangle r1(2, 3), r2(3, 2), r3(3, 6);
	Square s1(6), s2(8), s3(10);
	Circle c1(1), c2(2), c3(7);
	vector<Shape*> save1, save2, save3;
	save1.push_back(&r1);
	save1.push_back(&r2);
	save1.push_back(&r3);
	save2.push_back(&s1);
	save2.push_back(&s2);
	save2.push_back(&s3);
	save3.push_back(&c1);
	save3.push_back(&c2);
	save3.push_back(&c3);
	auto temp = Total(save1);
	cout << temp << endl;
	temp = Total(save2);
	cout << temp << endl;
	temp = Total(save3);
	cout << temp << endl;
	return 0;
}