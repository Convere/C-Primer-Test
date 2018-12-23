//#include <iostream>
//#include <cstdio>
//using namespace std;
//
///*本来想用list写，但是写的实在很烂，所以还是用数组来写吧，C掌握的知识确实是不充分*/
//
//struct ListNode 
//{
//	char data; ListNode* pred; ListNode* succ;
//	ListNode(){}
//	ListNode(char e, ListNode* p = NULL, ListNode* s = NULL) :data(e), pred(p), succ(s) { }
//	ListNode* insertAspred(char const &e)
//	{
//		ListNode* x = new ListNode(e, pred, this);
//		pred->succ = x; pred = x;
//		return x;
//	}
//	ListNode* insertAssucc(char const &e)
//	{
//		ListNode* x = new ListNode(e, this, succ);
//		succ->pred = x; succ = x;
//		return x;
//	}
//};
//
//class List 
//{ 
//public:
//	int _size; ListNode* header; ListNode* trailer; //规模、头哨兵、尾哨兵
//	int clear();
//	void init(); //列表创建时的初始化
//	// 构造函数
//	List() { init(); } //默认构造函数
//	~List() { clear(); delete header; delete trailer; } //释放（包含头、尾哨兵在内的）所有节点
//	// 只读访问接口
//	int size() const { return _size; } //规模
//	bool empty() const { return _size <= 0; } //判空
//	char& operator[] (int r) const//重载，支持循秩访问（效率低）
//	{
//		ListNode* p = first();
//		while (0 < r--)p = p->succ;
//		return p->data;
//	}
//		
//	ListNode* first() const { return header->succ; } //首节点位置
//	ListNode* last() const { return trailer->pred; } //末节点位置
//	ListNode* insertA(ListNode* p, char const& e); //将e当作p的后继插入
//	ListNode* insertB(ListNode* p, char const& e); //将e当作p的前驱插入
//	char remove(ListNode* p); //删除合法位置p处的节点,返回被删除节点
//}; //List
//
//void List::init()
//{
//	header = new ListNode;
//	trailer = new ListNode;
//	header->succ = trailer; header->pred = NULL;
//	trailer->pred = header; trailer->succ = NULL;
//	_size = 0;
//}
//
//ListNode* List::insertA(ListNode* p, char const &e)
//{
//	_size++; return p->insertAssucc(e);
//}
//
//ListNode* List::insertB(ListNode* p, char const &e)
//{
//	_size++; return p->insertAspred(e);
//}
//
//char List::remove(ListNode* p)
//{
//	char e = p->data;
//	p->pred->succ = p->succ; p->succ->pred = p->pred;
//	delete p; _size--;
//	return e;
//}
//
//int List::clear()
//{
//	int oldsize = _size;
//	while (0 < _size) remove(header->succ);
//	return oldsize;
//}
//
//ListNode* save_node[10000];
//
//void doit(List &save, int &step, char &in)
//{
//	save.insertB(save_node[step], in);
//	switch (step)
//	{
//	case 0:
//	{
//		if (save[step] == save[step + 1] == save[step + 2])
//		{
//			save.remove(save_node[step + 2]);
//			save.remove(save_node[step]);
//			save.remove(save_node[step + 1]);
//		}
//		break;
//	}
//	case 1:
//	{
//		if (save[step - 1] == save[step] == save[step + 1])
//		{
//			save.remove(save_node[step + 1]);
//			save.remove(save_node[step]);
//			save.remove(save_node[step - 1]);
//		}
//		else
//			if (save[step] == save[step + 1] == save[step + 2])
//			{
//				save.remove(save_node[step + 2]);
//				save.remove(save_node[step]);
//				save.remove(save_node[step + 1]);
//			}
//		break;
//	}
//	default:
//	{
//		if (save[step - 2] == save[step - 1] == save[step])
//		{
//			save.remove(save_node[step]);
//			save.remove(save_node[step - 1]);
//			save.remove(save_node[step - 2]);
//		}
//		else
//			if (save[step - 1] == save[step] == save[step + 1])
//			{
//				save.remove(save_node[step + 1]);
//				save.remove(save_node[step]);
//				save.remove(save_node[step - 1]);
//			}
//			else
//				if (save[step] == save[step + 1] == save[step + 2])
//				{
//					save.remove(save_node[step + 2]);
//					save.remove(save_node[step]);
//					save.remove(save_node[step + 1]);
//				}
//		break;
//	}
//	}
//	for (int i = 0; i < save._size; i++)
//		cout << save[i] << endl;
//}
//
//int main_ZUMA_list()
//{
//	char save_in[10000];
//	List save; int n = 0;
//	scanf("%s", &save_in);
//	for (int i = 0; i < strlen(save_in); i++)
//		save_node[i] = save.insertB(save.trailer, save_in[i]);   //相关字符全部单个存入list中
//	scanf("%d", &n);  //需要重现的次数
//	for (int i = 1; i <= n; i++)   //进次数输入的循环
//	{
//		int step = 0; char in;
//		scanf("%d%s", &step, &in);   //step为所插入的位置，in为所插入的字符
//		doit(save, step, in);
//	}
//	return 0;
//}