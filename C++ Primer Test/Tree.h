#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Tree
{
	friend ostream& operator<<(ostream &out, const Tree &temp);
	friend istream &operator>>(istream &in, Tree &temp);
	friend void print(Tree &tree);
public:
	Tree(string na, unsigned ag, double lo, double rad) :name(na), age(ag), longth(lo), radius(rad) {}
	Tree() :Tree("null", 0, 0, 0) {}
	Tree(istream &in) :Tree() { in >> name >> age >> longth >> radius; }
	explicit operator bool() const { return (age < 10); }
	Tree &operator=(const Tree &temp)   //¿½±´¸³ÖµÔËËã·û
	{
		this->name = temp.name;
		this->age = temp.age;
		this->longth = temp.longth;
		this->radius = temp.radius;
		return *this;
	}
	Tree &operator=(const Tree &&temp) noexcept   //ÒÆ¶¯¸³ÖµÔËËã·û
	{
		if (this != &temp)
		{
			this->name = temp.name;
			this->age = temp.age;
			this->longth = temp.longth;
			this->radius = temp.radius;
		}
		return *this;
	}
private:
	string name;
	unsigned age;
	double longth;
	double radius;
};

ostream &operator<<(ostream &out, const Tree &temp)
{
	out << temp.name << " " << temp.age << " " << temp.longth << " " << temp.radius << endl;
	return out;
}

istream &operator >> (istream &in, Tree &temp)
{
	in >> temp.name >> temp.age >> temp.longth >> temp.radius;
	if (!in)
		temp = Tree();
	return in;
}

void print(Tree &tree)
{
	cout << tree.name << " " << tree.age << " " << tree.longth << " " << tree.radius << endl;
}