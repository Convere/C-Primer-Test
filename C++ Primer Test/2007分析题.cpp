#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> fib(int len)
{
	if (len < 0 || len>1024)
	{
		throw ("invalid length");
	}
	//static vector<int> elems;   
	static vector<int> elems(len, 0);   //更改此处，给elems 的定义添加长度，不然无法使用[]运算符表示之后的数
	for (int i = 0; i < len; i++)
	{
		if (i == 0 || i == 1) elems[i] = 1;
		else elems[i] = elems[i - 1] + elems[i - 2];
	}
	return elems;
}

int main20071()
{
	vector<int> vec;
	vec = fib(5);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];
	cin.get();
	return 0;
}

//struct CFileNode
//{
//	string m_sName = NULL;
//	string m_dCreatTime = "2000-1-1";
//	float m_fSize = 0.0;
//	string m_sType = NULL;
//	CFileNode() {};
//	CFileNode(string &na) :m_sName(na) {}
//};
//
//
//class CFolderNode
//{
//private:
//	string sName = NULL;
//	string dCreatTime = "2000-1-1";
//	list<CFolderNode*>lstFolder;
//	list<CFileNode*>lstFile;
//public:
//	CFolderNode() {};
//	CFolderNode(string &na) :sName(na) {}
//	bool lowsz(const CFileNode* s1, const CFileNode*s2) { return s1->m_fSize < s2->m_fSize; }
////	bool SearchFile(string sName, string &sResult)
////	{
////		sResult = binary_search(lstFile.begin(), lstFile.end(), sName);
////		if (sResult == "1")
////			return true;
////		return false;
////	}
//	void AddFolder(string sName)
//	{
//		CFolderNode* newfolder = new CFolderNode(sName);
//		lstFolder.push_back(newfolder);
//	}
//	void AddFile(string sName)
//	{
//		CFileNode* newfile = new CFileNode(sName);
//		lstFile.push_back(newfile);
//	}
//	void DeleteFile(string sName)
//	{
//		auto iter = find(lstFile.begin(), lstFile.end(), sName);
//		lstFile.remove(*iter);
//	}
//	void SortFiles()
//	{
//		stable_sort(lstFile.begin(), lstFile.end());
//	}
//};
////
//int main()
//{
//	//CFolderNode a1;
//	//CFolderNode a2;
//	//CFileNode b1;
//	//CFileNode b2;
//	//CFileNode b3;
//	//a1.AddFile("1");
//	//a2.AddFolder("1f");
//	//a1.DeleteFile("1");
//	//a2.SortFiles();
//	//string res;
//	//a2.SearchFile("1f", res);
//	return 0;
//}