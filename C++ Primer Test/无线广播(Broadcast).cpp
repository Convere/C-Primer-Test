#include <iostream>
#include <cstdio>
#define UNDISCOVERED 0
#define DISCOVERED 1
#define VISITED 2
using namespace std;

/*这里使用的是无向图的广度优先搜索算法，标记每个节点的邻居为DIS，自己为VIS，在广度搜索的过程中查找有没有邻居DIS相撞
采用了网上学习的图的邻接表数据结构，这个结构天秀很好用，以后多学习*/

struct ENode
{
	int v_to;  //当前节点指向的数据
	ENode *v_from;   //指向当前节点的节点
};
struct Gragh
{
	ENode *v_self;  //无向图，储存自身数据即可
};

Gragh cast[10000]; int queue[10000]; int status[10000];

static int BFS(int first)
{
	int queue_num = 0; int queue_front = 0;  //num表示队列长度，front表示队首
	queue[queue_num++] = first;
	status[first] = DISCOVERED; //此处DISCOVERED代表已经入队，数值为1，进行扫描
	while (queue_num != queue_front)
	{
		int last_one = queue[queue_front];  //存储上一个出队的元素，若其能完成循环，即处于visited状态
		for (ENode *p = cast[queue[queue_front++]].v_self; p; p = p->v_from)  //每扫描一个节点，队首后移
		{
			switch (status[p->v_to])
			{
			case DISCOVERED:
				return -1;
			case UNDISCOVERED:
				status[p->v_to] = DISCOVERED; queue[queue_num++] = p->v_to; break; //与当前节点相关联的节点入队 break;
			}//VISITED已访问结束的节点不用管，直接忽略
		}
		status[last_one] = VISITED;  //表示当前节点已经被访问完毕
	}
	return 1;
}

int main_wuxianguangbo()
{
	int cast_num, less_num, last_cast_num;
	cin >> cast_num >> less_num;
	for (int i = 0; i < less_num; i++)  //建图
	{
		int start, end;
		cin >> start >> end;
		auto temp = new ENode; temp->v_to = end;
		temp->v_from = cast[start].v_self; cast[start].v_self = temp;
		temp = new ENode; temp->v_to = start;
		temp->v_from = cast[end].v_self; cast[end].v_self = temp;
		//将两个节点互相指向，成无向图。每个节点知道自己指向哪个节点，还是不知道哪个节点指向自己
		last_cast_num = start;  //储存最后一个输入的村庄
	}
	cout << BFS(1) << endl;  //改成1就全对了，玄学问题，其实本就应该是随便从图里取一个节点就行的

	//队列储存的数据
	//for (int i = 0; i < 20; i++)
	//	cout << queue[i] << " ";
	//cout << endl;  

	return 0;
}
/*
4 3
1 2
1 3
2 4
*/