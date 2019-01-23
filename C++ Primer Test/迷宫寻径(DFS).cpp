#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

//现在所能得到的就是只能判断当前的迷宫是否能够找到出路，而最小路径由于概率不够随机的原因本人目前在DFS下暂时还没有实现

/*迷宫寻径主流的三大算法：广度/深度优先搜素算法，以及A*算法*/
/*相对而言，深度优先搜索是最适合迷宫出去路径寻径的，通过一步一步的试探和回溯，能很快找到一条出去的路*/
typedef enum { AVAILABLE, ROUTE, BACKTRACKED, WALL } Status;
typedef enum { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN;
inline ESWN nextESWN(ESWN eswn) { return ESWN(eswn + 1); }

static struct Cell
{
	int x, y; Status status;  //xy的坐标与类型
	ESWN incoming, outgoing;  //进入的方向与出去的方向
	Cell *prev;
};

#define LABY_MAX 40
static Cell laby[LABY_MAX][LABY_MAX];
static int ncheck, nback, length;

static inline Cell *neighbor(Cell *cell) //移动的探测，即得到当前cell的邻居，根据outgoing确定方向
{
	switch (cell->outgoing)
	{
	case EAST:return cell + LABY_MAX;
	case SOUTH:return cell + 1;
	case WEST:return cell - LABY_MAX;
	case NORTH:return cell - 1;
	default:exit(-1); //如果不是这四个方向，即UNKNOWN和NO_WAY，则直接退出这个switch循环
	}
}

static inline Cell* advance(Cell* cell)  //实质性的移动，根据cell的incoming移动当前cell到对应的cell
{
	Cell *next;
	switch (cell->outgoing)
	{
	case EAST:next = cell + LABY_MAX; next->incoming = WEST; next->x = cell->x + 1; break;  //这里的操作意思是，现节点的进入为西，即相当于原节点的出是东
	case SOUTH:next = cell + 1;		  next->incoming = NORTH; next->y = cell->y + 1; break;
	case WEST:next = cell - LABY_MAX; next->incoming = EAST; next->x = cell->x - 1; break;
	case NORTH:next = cell - 1;		  next->incoming = SOUTH; next->y = cell->y - 1; break;
	default: exit(-1);
	}
	return next;
}

static bool labyrinth(Cell Laby[LABY_MAX][LABY_MAX], Cell *s, Cell *t)
{
	if ((AVAILABLE != s->status) || (AVAILABLE != t->status)) return false;  //首先，起点和终点必须是能访问的
	stack<Cell*> path;  //栈中存放的都是指向cell单元的指针，这样对于栈的操作过程都是指针操作，能有效提升效率
	s->incoming = UNKNOWN; s->status = ROUTE; path.push(s);  //将起点的进入点设为无，然后状态设为在路径上，最后入栈
	do
	{
		Cell *c = path.top();  //c是指向栈顶元素的指针，用于处理当前栈顶的节点数据
		if (c == t)
		{
			length = path.size();
			return true;  //迷宫的最终条件，找到终点
		}
		while (NO_WAY > (c->outgoing = nextESWN(c->outgoing)))  //将c的出方向改为nextESWN枚举中的下个元素（未知，东南西北，无路）
			if (AVAILABLE == neighbor(c)->status) break;		//遍历c的各个邻居（东南西北方向），一旦有可行的就跳出，不然就循环
																//注意上面的循环终止条件，要么是邻居可走就跳出，要么就是走到了NO_WAY，也就是无路可走，所以跳出
																//同时注意，这里是while循环，回溯之后的cell过此段代码时，会先nextESWN到下一个方向，不会出现一个方向无限循环的情况
																//这里有个很有意思的想法，既然在检查方向，其肯定会检查到其incoming的方向，但是前面可以看到，只要走过的路都会标成ROUTE，所以不会干涉
		if (NO_WAY <= c->outgoing)  //说穿了，就是无路可走了，如同字面意思
		{
			c->status = BACKTRACKED;  //将当前的节点c，即对应的栈顶元素标记为BACKTRACKED，即已经走过但是试探全部失败回溯的点，类似于忒休斯的标志
			path.pop();  //栈顶元素出栈，但是cell c本质上还是存在的，没有删除。从实质上实现回溯
			nback++;
		}
		else
		{
			path.push(c = advance(c));   //将c根据前面试探可行的方向移动之后，将移动后的c入栈（此时的C已经是一个新的cell指针了，没有指向之前的栈顶元素了
			c->outgoing = UNKNOWN;  //新的c的出方向必然为未知
			c->status = ROUTE; //新的栈顶元素的标志改为ROUTE，表示进入路径试探了
			ncheck++;
		}
	} while (!path.empty());  //直到存储路径的path为空
	length = path.size();
	return false;  //如果循环内没有实现true的返回，代表起点到终点没有路，那么最终只能返回false了
}

/******************************************************************************************
*   输出某一迷宫格的信息
******************************************************************************************/
static void printLabyCell(Cell* elem)
{
	printf("%d -> (%d, %d) -> %d\n",
		((Cell*)elem)->incoming,
		((Cell*)elem)->x,
		((Cell*)elem)->y,
		((Cell*)elem)->outgoing);
}

static int labySize;  //此处借用dascpp中邓公的随机迷宫生成程序
static Cell* startCell;
static Cell* goalCell;
static void randLaby()
{
	labySize = LABY_MAX / 2 + rand() % (LABY_MAX / 2); //生成一个随机size的迷宫
	/*DSA*/printf("Using a laby of size %d ...\n", labySize);
	for (int i = 0; i < labySize; i++)
		for (int j = 0; j < labySize; j++)
		{
			laby[i][j].x = i;
			laby[i][j].y = j;
			laby[i][j].incoming =
				laby[i][j].outgoing = UNKNOWN;
			laby[i][j].status = WALL; //边界格点必须是墙
		}
	for (int i = 1; i < labySize - 1; i++)
		for (int j = 1; j < labySize - 1; j++)
			if (rand() % 4) laby[i][j].status = AVAILABLE; //75%的格点为空可用
	startCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	goalCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	startCell->status = goalCell->status = AVAILABLE; //起始格点必须可用
}

//这里同样借用的是邓公的迷宫显示代码
/******************************************************************************************
* 显示迷宫
******************************************************************************************/
static void displayLaby() { //┘└┐┌│─
	static char*   pattern[5][5] =
	{
		"┼", "┼", "┼", "┼", "┼",
		"┼", "  ", "┌", "─", "└",
		"┼", "┌", "  ", "┐", "│",
		"┼", "─", "┐", "  ", "┘",
		"┼", "└", "│", "┘", "  "
	};
	//system("cls");
	printf("  ");
	for (int j = 0; j < labySize; j++)
		(j < 10) ? printf("%2X", j) : printf(" %c", 'A' - 10 + j);
	printf("\n");
	for (int j = 0; j < labySize; j++)
	{
		(j < 10) ? printf("%2X", j) : printf(" %c", 'A' - 10 + j);
		for (int i = 0; i < labySize; i++)
			if (goalCell == &laby[i][j])
				printf("﹩");
			else
				switch (laby[i][j].status)
				{
				case WALL:  printf("█");   break;
				case BACKTRACKED: printf("○");   break;
				case AVAILABLE: printf("  ");   break;
				default: printf("%s ", pattern[laby[i][j].outgoing][laby[i][j].incoming]);  break;  
				//老师这里的代码%s后面没有空格，需要加上，不然迷宫会乱掉
				}
		printf("\n");
	}
}

int main_dfs()
{
	srand(int(time(0)));  //根据系统时间确定随机种子，保证每次执行都不同
	randLaby();
	if (labyrinth(laby, startCell, goalCell))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	displayLaby();
	cout << "start: " << "(" << startCell->x << "," << startCell->y << ")"
		<< "  " << "end: " << "(" << goalCell->x << "," << goalCell->y << ")" << endl;
	cout << "check times: " << ncheck << " back times: " << nback << endl;
	cout << "length of path is " << length << endl;
	return 0;
}