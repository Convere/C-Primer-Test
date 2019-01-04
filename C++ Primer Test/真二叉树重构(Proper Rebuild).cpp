#include <iostream>
#include <cstdio>
using namespace std;

int xianxu[4000000], houxu[4000000], BinaryTreezhongxu[4000000];
int PR_n;

const int SZ = 1 << 20;  //快速io 提升输入输出速度
struct fastio
{
	char inbuf[SZ];
	char outbuf[SZ];
	fastio()
	{
		setvbuf(stdin, inbuf, _IOFBF, SZ);
		setvbuf(stdout, outbuf, _IOFBF, SZ);
	}
}io;

/*树的数据结构设计*/
typedef struct BinaryTree
{
	int key;
	BinaryTree *lson;
	BinaryTree *rson;
}BinaryTree;

/* 查找数组中对应数值的位置 */
int Array_Find(int *A, int begin, int end, int key)
{
	for (int i = begin; i < end; i++)
		if (key == A[i])
			return i;
	return -1;
}

/*根据先序遍历与后续遍历，实现的递归式真二叉树重构*/
BinaryTree *GetBinaryTree(int *PreOrder, int pbegin, int pend, int *PostOrder, int tbegin, int tend)
{
	if (pbegin >= pend || tbegin >= tend) return NULL;   // 出口, 无节点情况  

	BinaryTree *Root = new BinaryTree;         // 分配在堆上, 函数结束时不会消失  
	*Root = { PreOrder[pbegin], NULL, NULL };   // 构造根节点  构造函数，初始值（根节点）的值为先序的首位

	if (pbegin + 1 == pend) return Root;   // 不存在左右子树情况  
	int lr = Array_Find(PostOrder, tbegin, tend, PreOrder[pbegin + 1]); // 在后序遍历中查找先序遍历中直接确定的左树的根节点，赋值

																		// 确定左子树、右子树 前序、后序遍历结果, 递归求解 */  
	//先序遍历的起始为pbegin+1，因为pbegin为根节点，已经使用，其终止点为(lr + 1 - tbegin) + pbegin + 1，可理解为lr+2，其中lr+1为左树的最后一个节点
	//后序遍历的为tbegin到 lr + 1，左数的第一个到右树的第一个，区间为[）
	Root->lson = GetBinaryTree(PreOrder, pbegin + 1, (lr + 1 - tbegin) + pbegin + 1, PostOrder, tbegin, lr + 1);
	Root->rson = GetBinaryTree(PreOrder, (lr + 1 - tbegin) + pbegin + 1, pend, PostOrder, lr + 1, tend - 1);

	return Root;
}

/*这里输出的是所有的节点值以及其对应的子树*/
void Tree_Print(BinaryTree *Root)
{
	if (Root == NULL) return;

	printf("key:   %d\n", Root->key);      //visit tree
	if (Root->lson != NULL) 
		printf("lson:  %d\n", Root->lson->key);
	if (Root->rson != NULL) 
		printf("rson:  %d\n", Root->rson->key);
	printf("\n\n");

	Tree_Print(Root->lson);
	Tree_Print(Root->rson);
}

/*中序遍历的输出*/
void IN_Print(BinaryTree *Root)
{
	if (Root == NULL) return;
	IN_Print(Root->lson);
	printf("%d ", Root->key);
	IN_Print(Root->rson);
}

int main_erchashu()
{
	scanf("%d", &PR_n);   //节点数量读入
	for (int i = 0; i < PR_n; i++)
		scanf("%d", &xianxu[i]);
	for (int i = 0; i < PR_n; i++)
		scanf("%d", &houxu[i]);
	BinaryTree *Root = GetBinaryTree(xianxu, 0, PR_n, houxu, 0, PR_n);
	IN_Print(Root);
	printf("\n");
	return 0;
}