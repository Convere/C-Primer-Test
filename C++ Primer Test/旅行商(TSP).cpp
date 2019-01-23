#include <iostream>
#include <cstdio>
#include <vector>
#define GetMax(a,b) (a>b)?a:b
using namespace std;

/*借用拓扑排序的思想，在构造拓扑排序序列的同时，计算所经过的村庄的长度迭代叠加，目前可以记录最终的排序结果与最长路径
但是把走的路径表示出来，尤其是多种路径时的情况还欠缺考虑*/
struct ENode 
{
	int v_to;  //此v_to表示當前村莊通向的另一個村莊
	ENode *v_from;
};
struct VNode 
{
	int in, len;//相对于邻接表结构，额外添加了属性len以计算到每个顶点的最大路徑，in為入度
	ENode *v_self;
};
VNode village_to_village[1000000]; //village_to_village中存储了足够的VNode节点，该节点成员有in入度，len最大路径，fstEdge
int visited[1000000], stack[1000000], maxlen; vector<int> save;

void TSort(int villages)   //借助了拓扑排序的思想来构建
{
	int top = 1;
	for (int i = 1; i<=villages; i++)
		if (!village_to_village[i].in)
		{
			stack[top++] = i;    //如果对应的村庄没有入度，即没有进去的道路（这种村庄一般为图的顶端之类的），入栈，值为村庄名
			save.push_back(i);
		}
	while (top)   //直到top为0，即栈中没有了元素
	{
		int v = stack[top--];  //v为栈顶的村庄，此栈中均为入度为0的村庄
		for (ENode *p = village_to_village[v].v_self; p; p = p->v_from) //遍历对应的村庄中对应的自身信息（即存储的其入边关系）
		{
			//策略：动态规划-不断的更新到每个入度为0的顶点的邻居的最大路径长度
			village_to_village[p->v_to].len = GetMax(village_to_village[v].len + 1, village_to_village[p->v_to].len);
			maxlen = GetMax(village_to_village[p->v_to].len, maxlen);
			//沿着图上的入边不断向前递进，直到计算到最后的一个节点，最终的maxlen为经过的村庄数目，但最终还需包括起始村庄
			//相对于拓扑排序，额外添加了上述2句以更新到每个邻居的最大路径长度和记录图的最大路径长度 
			if (!(--village_to_village[p->v_to].in))
			{
				stack[++top] = p->v_to;  //此处入栈，入度为0的村庄（节点）
				save.push_back(p->v_to);
			}
		}
	}
}

int main_lvxingshang()
{
	int villages, pass;
	cin >> villages >> pass;
	for (int i = 0; i < pass; i++)  //建图
	{
		int start, end;
		cin >> start >> end;
		auto temp = new ENode; temp->v_to = end; village_to_village[end].in++;  
		//表示当前节点通向end村庄，对应的end村庄的入度+1
		temp->v_from = village_to_village[start].v_self; village_to_village[start].v_self = temp;
		//将start村庄本有的v_self信息存储到当前节点的v_from中，然后将当前节点temp覆盖start村庄的self信息
		//总结来说，就是在start节点中记录下，其指向end节点，同时也被self中存储的节点指向。
		//也就是说，在这个有向图数据结构中，节点只知道自己指向哪些节点，但不知道指向自己的节点究竟是什么（此处的v_self均为空）
	}
	TSort(villages);
	cout << maxlen + 1 << endl;  //要包括起始村庄，所以加1

	for (auto &s : save)  //拓扑排序的顺序
		cout << s << " ";
	cout << endl;

	return 0;
}

/*测试用例
6 9
1 2
4 2
4 5
1 6
2 3
2 5
5 6
1 6
3 6
*/