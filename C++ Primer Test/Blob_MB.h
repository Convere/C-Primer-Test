#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
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

//前置声明，在Blob中声明友元所需要的
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T>&a, const Blob<T>&b) { return a.data == b.data; }

template <typename T> class Blob
{
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	//构造函数
	Blob() :data(make_shared<vector<T>>()) {}
	Blob(initializer_list<T> il) :data(make_shared<vector<T>>(il)) {}
	//Blob中的元素数目
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//添加和删除元素
	void push_back(const T &t) { return data->push_back(t); }
	//移动版本
	void push_back(T &t) { data->push_back(std::move(t)); }
	void pop_back();
	//元素访问
	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	//若data[i]无效，则抛出msg
	void check(size_type i, const string &msg) const;
};

template<typename T> void Blob<T>::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template<typename T> T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T> T& Blob<T>::operator[](size_type i)
{
	//如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T> void Blob<T>::pop_back()
{
	check(0,"pop_back on empty Blob");
	data->pop_back();
}

template<typename T> class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	T& operator*() const
	{
		auto p = check(curr, "deference past end");
		return (*p)[curr];   //(*p)为本对象指向的vector
	}
	//递增和递减
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr& operator++(int);
	BlobPtr& operator--(int);  //后置运算符，int作为一个标志，不参与运算
private:
	//若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<T>> check(size_t, const string&) const;
	//保存一个weak_ptr，表示底层vector可能被销毁
	weak_ptr<vector<T>> wptr;
	size_t curr;  //数组中当前位置
};

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of Blob<T>Ptr");
	++curr;
	return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(-1, "decrement past begin of Blob<T>Ptr");
	return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator++(int)
{
	BlobPtr<T> ret = *this;
	++*this;
	return ret;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator--(int)
{
	BlobPtr<T> ret = *this;
	--*this;
	return ret;
}

template <typename T> inline shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();  //调查wptr是否还存在
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}