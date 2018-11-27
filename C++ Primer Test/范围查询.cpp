#include <iostream>
#include <cstdio>
using namespace std;

int main_Normal()  //传统的蛮力算法，将数组中所有数字与上下限相比较，运算速度缓慢且正确率低
{
	int n, m, point;
	static int save[500002], sum_save[500002];
	cin >> n >> m;
	cin >> point;
	save[0] = point;
	while (cin.get() != '\n')
	{
		for (int i = 1; i < n; i++)
		{
			cin >> point;
			save[i] = point;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, sum = 0;
		if (cin >> a >> b)
		{
			for (auto &s : save)
			{
				if ((a <= s) && (b >= s))
					sum++;
			}
			sum_save[i - 1] = sum;
		}
	}
	for (int i = 0; i < m; i++)
		cout << sum_save[i] << endl;
	return 0;
}

int save[500002];
/*快速排序算法*/
int partition(int *save, int lo, int hi)
{
	//swap(save[lo], save[lo + rand() % (hi + lo - 1)]);  //这里用于向量中交换元素的，数组中并不适用
	int pivot = save[lo];
	while (lo < hi)
	{
		while ((lo < hi) && (pivot <= save[hi]))
			hi--;
		save[lo] = save[hi];
		while ((lo < hi) && (save[lo] <= pivot))
			lo++;
		save[hi] = save[lo];
	}
	save[lo] = pivot;
	return lo;
}

void quicksort(int *save, int lo, int hi)
{
	if (hi - lo < 2) return;
	int mi = partition(save, lo, hi - 1);
	quicksort(save, lo, mi);
	quicksort(save, mi + 1, hi);
}

/*二分查找算法*/
static int binsearch(int *save, int e, int lo, int hi)
{
	while (lo < hi)
	{
		int mi = (lo + hi) >> 1;
		(e < save[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;
}

int main_Cpp()
{
	/*这里的数据输入输出是c++的方式，速度太慢，会导致超时*/
	int n, m, point = 0;
	cin >> n >> m;
	cin >> point;
	save[0] = point;
	while (cin.get() != '\n')  //存储数组数据
	{
		for (int i = 1; i < n; i++)
		{
			cin >> point;
			save[i] = point;
		}
	}
	quicksort(save, 0, n);  //数组整体排序
	for (int i = 1; i <= m; i++)
	{
		int a, b, sum = 0;
		/*这里的数据输入输出是c++的方式，速度太慢，会导致超时*/
		cin >> a >> b;
		int s1 = binsearch(save, a - 1, 0, n);  //这里的a-1究极灵性，避免了少1以及全部相同的问题
		int s2 = binsearch(save, b, 0, n);
		sum = s2 - s1;
		cout << sum << endl;
	}
	return 0;
}

int main_C()  //采用C格式的输入输出语句，时间最小化，也是最优的最终程序
{
	int n, m, point;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &save[i]);
	quicksort(save, 0, n);  //数组整体排序
	for (int i = 1; i <= m; i++)
	{
		int a, b, sum = 0;
		scanf("%d%d", &a, &b);
		int s1 = binsearch(save, a - 1, 0, n);  //这里的a-1究极灵性，避免了少1以及全部相同的问题
		int s2 = binsearch(save, b, 0, n);
		sum = s2 - s1;
		printf("%d \n", sum);
	}
	return 0;
}