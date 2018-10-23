/*#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
using namespace std;

class HasPtr   //练习13.27
{
public:
	HasPtr(const string &s=string()):ps(new string(s)),i(0),use(new size_t(1)){}  //默认构造函数
	HasPtr(const HasPtr &temp) :ps(temp.ps), i(temp.i), use(temp.use) { ++*use; }  //拷贝构造函数，每被拷贝一次则计数器加1
	HasPtr &operator=(const HasPtr &temp)   //拷贝赋值运算符，先递增右侧计数器（拷贝构造函数的工作），再递减左侧计数器，必要时释放内存（析构函数的工作）。再进行判断
	{
		++*temp.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = temp.ps;
		i = temp.i;
		use = temp.use;
		return *this;
	}
	~HasPtr()  //析构函数，必要时释放内存
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	string *ps;
	int i;
	size_t *use;
};

class TreeNode  //练习13.28
{
public:
	TreeNode(): value(string()), count(new int(1)), left(nullptr), right(nullptr) { cout << "空默认构造函数" << endl; }
	TreeNode(const string &temp) : value(temp), count(new int(1)), left(nullptr), right(nullptr) { cout << "默认构造函数" << endl; }
	TreeNode(const TreeNode& rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; cout << "拷贝构造函数" << endl; }
	TreeNode &operator=(const TreeNode& rhs)  //拷贝赋值运算符
	{
		++*rhs.count;
		if (--*count == 0) 
		{
			if (left) 
			{
				delete left;
				left = nullptr;
			}
			if (right) 
			{
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
		value = rhs.value;
		left = rhs.left;
		right = rhs.right;
		count = rhs.count;
		return *this;
	}
	~TreeNode()  //析构函数
	{
		if (--*count == 0) {
			if (left) {
				delete left;
				left = nullptr;
			}
			if (right) {
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree //练习13.28
{
public:
	BinStrTree() : root(new TreeNode) {}
	BinStrTree(const BinStrTree &temp):root(new TreeNode (*temp.root)){}
	BinStrTree &operator=(const BinStrTree& bst)
	{
		TreeNode *new_root = new TreeNode(*bst.root);
		delete root;
		*root = *new_root;
		return *this;
	}
	~BinStrTree() { delete root; }
private:
	TreeNode *root;
};

int main()
{
	string word("me");
	TreeNode a;
	TreeNode b(word);
	TreeNode c(b);
}*/