/*#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
	Foo sorted() &&
	{
		sort(data.begin(), data.end());
		cout << "右值sort" << endl;
		return *this;
	}
	Foo sorted() const &
	{
		return Foo(*this).sorted();   //调用右值sort


		//Foo ret(*this);
		//return ret.sorted();  //什么都没有


		//Foo ret(*this);
		//sort(ret.data.begin(), ret.data.end());   //正统的左值sort调用
		//cout << "左值sort" << endl;
		//return ret;
	}
private:
	vector<int> data;
};

int main()
{
	Foo().sorted();
	Foo f;
	f.sorted(); // call "const &"
}*/