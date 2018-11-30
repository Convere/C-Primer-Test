#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <istream>
using namespace std;

static const float PI = 3.14159f;
class Shape
{
public:
	virtual string shape_name() const = 0;
	virtual void print() const = 0;
	virtual ~Shape() {}
};

class Shape_2D :public Shape
{
public:
	Shape_2D() = default;
	//Shape_2D(float x, float y) : x_(x), y_(y) {}
	virtual float area() const = 0;
	virtual float diameter() const = 0;
	virtual float circumference() const = 0;
	virtual ~Shape_2D() override {}
//protected:
//	float x_ ;
//	float y_ ;
};

class Shape_3D :public Shape
{
public:
	Shape_3D() = default;
	Shape_3D(float x, float y, float z) : x_(x), y_(y), z_(z) {}

	virtual float volume() const = 0;

	virtual ~Shape_3D() override {}

protected:
	float x_ = 0.0;  //长  
	float y_ = 0.0;  //宽 
	float z_ = 0.0;  //高 
};

class circle :public Shape_2D
{
public:
	circle() = default;
	circle(string na, float Rad) : name(na), radius(Rad) {}

	string shape_name() const override { return name; }
	float area() const override { return radius*radius*PI; };
	float diameter() const override { return 2 * radius; };
	float circumference() const override { return 2 * radius*PI; };
	void print() const override { cout << shape_name() << " " << area() << " " << circumference() << " " << diameter() << endl; }

	~circle() override {}

private:
	string name = nullptr;
	float radius = 0.0;  //圆的半径 
};

class rectangle :public Shape_2D
{
public:
	rectangle() = default;
	rectangle(string na, float lon, float wid) : name(na), longth(lon), width(wid) {}

	string shape_name() const override { return name; }
	float area() const override { return longth*width; };
	float diameter() const override { cout << "NO Diameter" << endl; return 0; };
	float circumference() const override { return 2 * (longth + width); };
	void print() const override { cout << shape_name() << " " << area() << " " << circumference() << " " << diameter() << endl; }

	~rectangle() override {}

private:
	string name = nullptr;
	float longth = 0.0;  //长
	float width = 0.0;	 //宽
};

class ball :public Shape_3D
{
public:
	ball() = default;
	ball(string na, float Rad) : name(na), radius(Rad) {}

	string shape_name() const override { return name; }
	float volume() const override { return radius*radius*radius*PI; }
	void print() const override { cout << shape_name() << " " << volume() << endl; }

	~ball() override {}

private:
	string name = nullptr;
	float radius = 0.0;  //球的半径
};

class box :public Shape_3D
{
public:
	box() = default;
	box(string na, float lon, float wid, float hei) : name(na), longth(lon), width(wid), height(hei) {}

	string shape_name() const override { return name; }
	float volume() const override { return longth*width*height; }
	void print() const override { cout << shape_name() << " " << volume() << endl; }

	~box() override {}

private:
	string name = nullptr;
	float longth = 0.0;  //长
	float width = 0.0;	 //宽
	float height = 0.0;  //高
};
