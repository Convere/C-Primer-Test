/*#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>
#include <memory>

using namespace std;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string& front() const;
	string& back() const;
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob:: back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}*/