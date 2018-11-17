#include "Ch2.h"

template<typename T> struct Increase
{
	virtual void operator()(T&e) { e*=e; }
};

template<typename T> void increase(Vector<T> & V)
{
	V.traverse(Increase<T>());
}

//int main_traverse_and_add()
int main_traverse_and_add()
{
	Vector<int> a(10, 5, 5);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	increase(a);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}