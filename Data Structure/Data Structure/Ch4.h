//#pragma once
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//template <typename T> class Stack : public vector<T> { //将向量的首/末端作为栈底/顶
//public: //size()、empty()以及其它开放接口，均可直接沿用
//	void push(T const& e) { insert(size(), e); } //入栈：等效于将新元素作为向量的末元素插入
//	T pop() { return remove(size() - 1); } //出栈：等效于删除向量的末元素
//	T& top() { return (*this)[size() - 1]; } //取顶：直接返回向量的末元素
//	void print() { for (int n = size() - 1; n >= 0; n--) cout << (*this)[n]; cout << endl; }
//};