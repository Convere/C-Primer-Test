#include <iostream>
#include <deque>
#include <time.h>
using namespace std;

//这是最小路径的实现函数，通过BFS方式步步遍历的到；如果使用DFS算法，需要穷尽所有的到达终点的路径，最后取最短的

/*迷宫寻径主流的三大算法：广度/深度优先搜素算法，以及A*算法*/
/*相对而言，深度优先搜索是最适合迷宫最短路径寻径的，通过一轮一轮的扁铝，找到的第一条路径也就是最短的路径*/
typedef enum { AVAILABLE, ROUTE, BACKTRACKED, WALL } Status;
typedef enum { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN;
inline ESWN nextESWN(ESWN eswn) { return ESWN(eswn + 1); }

static struct Cell
{
	int x, y; Status status;  //xy的坐标与类型
	ESWN incoming, outgoing;  //进入的方向与出去的方向
	Cell *prev;				  //运行BFS时建立前缀，用于建图形成反推
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

//输出某一迷宫格的信息
static inline void printLabyCell(Cell* elem)
{
	printf("%d -> (%d, %d) -> %d\n",
		((Cell*)elem)->incoming,
		((Cell*)elem)->x,
		((Cell*)elem)->y,
		((Cell*)elem)->outgoing);
}

void inline shortest_path(Cell *c)  //此函数用于根据传递到终点goalCell的数据，来进行路径反推
{
	cout << "shortest path is: " << endl;
	c->status = ROUTE;   //所有反推的路径全部将状态改为ROUTE，便于显示路径
	printLabyCell(c);
	while (c->incoming)  //一直反推到最短路径的初始点，即起点，起点的incoming是=0的
	{
		length++;        //length开始循环计数
		auto in = c->incoming;
		c = c->prev;
		switch (in)		 //根据上一个cell的incoming，来反推出当前cell的outgoing，相对取反即可
		{
		case EAST:  c->outgoing = WEST;   break;
		case SOUTH: c->outgoing = NORTH;   break;
		case WEST: c->outgoing = EAST;   break;
		case NORTH: c->outgoing = SOUTH;   break;
		default: exit(-1);
		}
		c->status = ROUTE;
		printLabyCell(c);
	}
	cout << "shortest path's long is " << length + 1 << endl;  //由于终点是在循环外面做的，所以此处需要加1
}

static bool bfs(Cell Laby[LABY_MAX][LABY_MAX], Cell *s, Cell *t)
{
	if ((AVAILABLE != s->status) || (AVAILABLE != t->status)) return false;  //首先，起点和终点必须是能访问的
	deque<Cell*> bfs_path;   //采用BFS算法，所以这里改为使用队列结构
	s->incoming = UNKNOWN; s->status = ROUTE; bfs_path.push_back(s);  //将起点的进入点设为无，然后状态设为在路径上，最后入队列
	do
	{
		Cell *c = bfs_path.front();
		bfs_path.pop_front();
		if (c == t)
		{
			t = c;    //当达到终点时，将此时的c传递给goalCell，因为其中储存了其所有的prev前缀
			return true;
		}
		while (NO_WAY != (c->outgoing = nextESWN(c->outgoing)))   //此处改为遍历当前cell的所有方向一次
		{
			if (AVAILABLE == neighbor(c)->status)  //只要cell的一个方向可以，就将其入队
			{
				Cell* temp = advance(c);
				temp->outgoing = UNKNOWN; temp->status = ROUTE;
				temp->prev = c;					   //每个从当前cell出去的cell，都将原cell设为前缀，由此实现当前图（树）结构的实现
				bfs_path.push_back(temp);
				ncheck++;
			}
		}
		c->status = BACKTRACKED;  //而被bfs过的cell，借用BACKTRACKED状态，表示其已经被扫描过但没有到达终点
	} while (!bfs_path.empty());
	return false;
}

static int labySize;  //此处借用dascpp中邓公的随机迷宫生成程序
static Cell* startCell;
static Cell* goalCell;
static void randLaby()
{ 
	labySize = LABY_MAX / 2 + rand() % (LABY_MAX / 2);  //生成一个随机size的迷宫
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
			if (rand() % 4) laby[i][j].status = AVAILABLE; //75%的格点为空可用，增加迷宫难度在此酌情修改
	startCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	goalCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	startCell->status = goalCell->status = AVAILABLE; //起始格点必须可用
}

//这里同样借用的是邓公的迷宫显示代码
//显示迷宫
static void displayLaby()
{ //┘└┐┌│─
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

int main()
{
	srand(int(time(0)));  //根据系统时间确定随机种子，保证每次执行都不同
	randLaby();			  //生成随机迷宫
	if (bfs(laby, startCell, goalCell))  //判断当前迷宫能否从起点走到终点，如果行的话，输出如下
	{
		cout << "true" << endl;
		cout << "start: " << "(" << startCell->x << "," << startCell->y << ")"            //输出当前迷宫的起点和终点
			<< "  " << "end: " << "(" << goalCell->x << "," << goalCell->y << ")" << endl;
		shortest_path(goalCell); //输出当前迷宫从起点到终点的最短路径与长度
	}
	else
		cout << "false" << endl;
	displayLaby();			 //形象的图像展示最短路径与搜索过程
	cout << "check times: "<<ncheck << endl;  //搜索次数
	return 0;
}