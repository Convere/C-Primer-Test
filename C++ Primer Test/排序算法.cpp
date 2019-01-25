#include <iostream>
#include <queue>
#include <time.h>
using namespace std;

/*插入排序*/
/*时间复杂度平均O(n2)，最好O(n)，最差O(n2)，空间复杂度O(1)，就地、稳定的排序*/
/*思路为：从第一与第二个元素开始，不断考虑后缀的元素，将其插入到前缀中合适其的位置，随着插入，其后的所有位置都需要改变
类似于打扑克时的抽牌，不过这里的牌是全部知道的。*/
template<typename T> void insertionsort(T data[], int n)
{
	for (int i = 1, j; i < n; i++)
	{
		T tmp = data[i];
		for (j = i; j > 0 && tmp < data[j - 1]; j--)  //注意只有<才会移动，=不动的
			data[j] = data[j - 1];   //插入的数（也就是每次后缀的第一个数）不断与其前面的数字比较，比其大就向前交换，直至比它小或到数组头
		data[j] = tmp;  //最后退出的那个位置被tmp赋值进去补充即可
	}
}

/*选择排序*/  //最近似于人查找的方法
/*时间复杂度平均O(n2)，最好O(n2)，最差O(n2)，空间复杂度O(1)，就地、不稳定的排序*/
/*思路为：遍历当前数组，查找数组中最小（大）的元素，将其与首元素（末元素）进行交换，然后降低搜索区间与交换区间*/
template<typename T> void selectionsort(T data[], int n)
{
	for (int i = 0, j, least; i < n - 1; i++)   //i的最大值定为n-1，是为了保证在j在n时停止循环防止越界
	{
		for (j = i + 1, least = i; j < n; j++)  //每层外循环，将最小值位置i向后移动一位
			if (data[j] < data[least])			//如果处于最小值位置之后的元素比j小，则一直将位置传递给least
				least = j;
		if (i != least)							//此条件表示当前数已是最小时不需要交换，增加n-1次索引比较，减少某些特殊的交换次数
			swap(data[i], data[least]);			//最后直接交换i和least的元素即可，由于前面的循环，此时的least必然是后缀中最小元素对应的位置
												//这里就出现不稳定的原因，当数组中存在多个相同的数a时，可能在前面的a会被交换到后面的位置去（小的数在数组偏后的地方）
	}
}

/*冒泡排序*/  
/*时间复杂度平均O(n2)，最好O(n)，最差O(n2)，空间复杂度O(1)，就地、稳定的排序*/
/*思路为：从头开始向尾遍历，如果后面的数比前面的数小（大），就交换，一直换到最后，再减小区间继续交换*/
template<typename T> void bubblesort(T data[], int n)
{
	bool flag = false;
	while (!flag)
	{
		flag = true;    //作为标识符，当遍历之后仍为true，表示当前数组已经有序，直接跳出即可
		for (int i = 0; i < n - 1; i++)
		{
			if (data[i] > data[i + 1])  //遍历式交换，最终当前区间的最后一个数必然是区间内的最大数
			{
				swap(data[i], data[i + 1]);  //交换过程没有出现交叉，所以是稳定的
				flag = false;
			}
		}
		n--; //n递减，因为每过一次循环，当前区间的最后一个数都已经排序完成，所以通过此来减小区间
	}
}

/*希尔排序*/
/*时间复杂度平均O(n1.3)，最好O(n)，最差O(n2)，空间复杂度O(1)，就地、不稳定的排序*/
/*思路为：根据增量序列将整个数组区间划分为多个h子序列，之后根据增量序列依次递减重新划分重新排序，最后在一个序列中重排实现*/
/*算法核心：增量序列，即shell序列的选取和确定*/
template<typename T> void shellsort(T data[], int n)
{
	int k = 0, m = 1, increments[20];
	while (m < n / 3)						// 动态定义间隔序列（这是最常见的shell增量序列，这几十年对此的研究层出不穷，有更好的存在）    
	{
		increments[k++] = m;
		m = m * 3 + 1;						// {1,4,13,40,121,....的通用shell序列
	}
	for (m = k-1; m >= 0; m--)              //重复使用m，此处作用是遍历increment序列（从大到小）
	{
		int h = increments[m];              //h代表当前的分割步长，即增量序列中的数据提取

		/*从这里开始，实现对输入数组的分割与排序*/
		for (int i = h; i < 2 * h; i++)     //此处开始根据步长h来对数组分割，比如初始h=4，n=17，那么这里的i会取值4567四个数，实现数组的四段分割
		{

			/*从这里开始，实现对于被分割的数组的排序过程*/  //这里是对于每个分割的数组的单独排序算法，可选用不同的
			for (int j = i; j < n;)   //j为输入的初始值，j+h为下一位置，j<n为固定限制条件
			{
				T temp = data[j];     //从当前数组的最左侧开始
				k = j;				  //保留j的数值，使用k来代替j进行插入排序运行
				while (k - h > 0 && temp < data[k - h])   //此处选用的是插入排序
				{
					data[k] = data[k - h];
					k -= h;			  //注意不是k--，步长为h
				}
				data[k] = temp;		  //最后退出的那个位置被temp赋值进去补充即可
				j += h;
			}

			/*以下是对于选择排序的尝试过程，可惜失败了*/
			//for (int j = i-h, k, least; j < n - h; j += h)
			//{
			//	for (k = j , least = j; k < n; k += h)		//每层外循环，将最小值位置i向后移动一位
			//	{
			//		cout << "k: " << k << endl;
			//		if (data[k] < data[least])			//如果处于最小值位置之后的元素比j小，则一直将位置传递给least
			//			least = k;
			//	}
			//	if (k != least)							//此条件表示当前数已是最小时不需要交换，增加一定的索引比较，减少某些特殊的交换次数
			//		swap(data[k], data[least]);			//最后直接交换i和least的元素即可，由于前面的循环，此时的least必然是后缀中最小元素对应的位置
			//}


		}
	}
}

/*堆排序*/
/*时间复杂度平均O(nlog2n)，最好O(nlog2n)，最差O(nlog2n)，空间复杂度O(1)，就地、不稳定的排序*/
/*思路为：根据输入的数组重新建堆，不断地将堆的顶部与数组区间的尾部交换（交换后下滤并减小区间，保证堆的最大值一直在顶部）*/
/*算法核心：建堆，取最大值*/
template<typename T> void moveDown(T data[], int first, int last)  //堆的下滤算法，first为堆顶（数组的第一位），last为堆尾（数组的最后一位）
{													   //从堆的最底层开始，反层次遍历的顺序遍历每个有孩子的节点（自下而上，由浅至深），孩子比自己大就交换，继续按着孩子原来的位置下滤
	int largest = 2 * first + 1;                       //这里的largest计算的是first节点对应的左孩子位置
	while (largest <= last)							   //判断最大的孩子是否还在区间内
	{
		if (largest < last && data[largest] < data[largest + 1])   //此处判断largest是否刚好为末节点，或者查看first的左孩子右孩子哪边大，largest取大边
			largest++;
		if (data[first] < data[largest])               //first作为父节点，与其最大的孩子比较，如果孩子大就换上来；如果不是，代表该节点稳健，跳出
		{
			swap(data[first], data[largest]);          //大的子节点largest和父节点first交换，继续判断first的两个孩子与其的大小关系
			first = largest;
			largest = 2 * first + 1;
		}
		else
			//largest = last + 1;
			break;
	}
}

template<typename T> void heapsort(T data[], int size)
{	
	for (int i = size / 2 - 1; i >= 0; --i)    //建堆，floyid建堆法，即自下而上地下滤每个节点。从size的中部选值，保持所取值都是有孩子的节点，避免无关计算
		moveDown(data, i, size - 1);

	cout << "建堆后数组为：   ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;

	for (int i = size - 1; i >= 1; --i)        //开始实质的堆排序，即不断地将data[0]（当前的最大数）交换到数组的区间末尾
	{
		swap(data[0], data[i]);
		moveDown(data, 0, i - 1);			   //通过每次交换之后的下滤，保证数组的首元素一直都是最大值
	}
}

/*快速排序*/
/*时间复杂度平均O(nlog2n)，最好O(nlog2n)，最差O(n2)，空间复杂度O(nlog2n)，不就地、不稳定的排序*/
/*思路为：将整个数组不断的分而治之，到最后变成只有一个元素的数组（1个元素自然不需要排序），真正的排序发生在数组的不断的划分过程中*/
/*算法核心：递归划分*/
int partition(int save[], int lo, int hi)      //数组的划分函数，中心点为pivot，在划分之后，其大于左侧的所有数，小于右侧的所有数。划分到最后只剩一个元素，数组也就排序好了
{
	int p = save[lo];
	int l = lo, h = hi;
	while (lo < hi)                            //记下save[lo]的数值，从lo开始不断交替比对，当lo=hi时即找到中位点
	{
		while ((lo < hi) && (p <= save[hi]))
			hi--;
		save[lo] = save[hi];
		while ((lo < hi) && (p >= save[lo]))
			lo++;
		save[hi] = save[lo];
	}
	save[lo] = p;
	return lo;
}

void quicksort(int save[], int lo, int hi)
{
	if (hi - lo < 2)return;
	int mi = partition(save, lo, hi - 1);      //确定中位点（不是中点，是中位点pivot）
	quicksort(save, lo, mi);				   //通过在划分后两段区间内不断递归划分，到最后只剩单个一个元素（即hi-lo=1）时，划分完毕的同时也排序完毕
	quicksort(save, mi + 1, hi);
}

/*归并排序*/
/*时间复杂度平均O(nlog2n)，最好O(nlog2n)，最差O(nlog2n)，空间复杂度O(n)，不就地、稳定的排序*/
/*思路为：将整个数组不断的分而治之，到最后变成只有一个/两个元素的数组，然后将各个数组两两归并在一起（排序发生在归并过程中），归并完即完成排序*/
/*算法核心：数组元素的归并*/

template<typename T> void merge(T data[], int lo, int mi, int hi)//这是一个大循环变小循环再到大循环的过程，最后的小循环都是只有两个元素或只有一个元素（两种情况都是直接return），然后慢慢归并排序到一起（最后的大循环）
{
	cout << "lo: " << lo << " mi: " << mi << " hi: " << hi << endl;
	int i1 = 0, i2 = lo, i3 = mi;								 //此处将i1作为temp的下标，i2作为数组data[lo,mi-1]的下标，i3作为数组data[mi,hi-1]的下标
	T *temp = new T[hi - lo];                                    //每次循环创建一个临时数组temp，用来存储当前区间排序后的元素
	while ((i2 < mi) || (i3 < hi))								 //从data分割的前后两个数组不断的相互比较，较小值进入temp，然后对应的区间下标++；如果达到某个区间全部比较完（下标到达上界），则另一个数组的元素按顺序进temp
	{
		if ((i2 < mi) && (!(i3 < hi) || (data[i2] <= data[i3])))
			temp[i1++] = data[i2++];
		cout << "i2: " << i2 << endl;
		if ((i3 < hi) && (!(i2 < mi) || (data[i3] < data[i2])))
			temp[i1++] = data[i3++];
		cout << "i3: " << i3 << endl;
		cout << "i1: " << i1 << endl;
		cout << endl;
	}

	for (int i = 0; i < hi-lo; i++)				//这里的赋值是将临时数组temp存储的排序值传递进data中原本应该对应的区间内，temp内的数值大小恒定为hi-lo
	{
		data[i + lo] = temp[i];					//所排序的区间均为[lo,hi]区间，所以data[i+lo]为temp中所排序的每个数值对应的真实数值
		cout << "temp" << "[" << i << "]:" << temp[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < hi - lo; i++)			//此处用于查看当前data数组的排序情况
		cout << "data" << "[" << i + lo << "]:" << data[i] << " ";
	cout << endl;
	delete[] temp;
}

template<typename T> void mergesort(T data[], int lo, int hi)
{
	if (hi - lo < 2) return;
	int mi = (lo + hi) / 2;
	mergesort(data, lo, mi); mergesort(data, mi, hi);
	merge(data, lo, mi, hi);
}

/*基数排序*/
/*时间复杂度平均O(n*k)，最好O(n*k)，最差O(n*k)，空间复杂度O(n+k)，不就地、稳定的排序*/
/*思路为：从各个数的基数（个位，十位，百位，以此类推）开始比较排序，一直比完最高位的基数*/
/*算法核心：基数必为10种数，位数可选定值或选用数组最大数的位数*/
template<typename T> void radixsort(T data[], int n)
{
	int i, j, k, factor;
	const int radix = 10;
	const int digits = 10;
	queue<T> queues[radix];                                        //一组队列，用于存储不同基数的数据（每一级基数都仅且对应9个数）
	for (i = 0, factor = 1; i < digits; factor *= radix, i++)      //digits表示最大位数，默认为10位，此处遍历10遍。也可以优化算法为当前数据中最大的数的那一位
	{
		for (j = 0; j < n; j++)
			queues[(data[j] / factor) % radix].push(data[j]);	   //每个数据，根据当前位数取余得到其基数，存入对应的队列中（对列恒定为0-9）
		for (j = k = 0; j < radix; j++)
			while (!queues[j].empty())							   //按基数顺序遍历每个队列，重新将数据覆盖原数组data的同时，清空所有队列
			{
				data[k++] = queues[j].front();
				queues[j].pop();
			}
	}
	cout << "基数排序" << endl;
}

/*计数排序*/
/*时间复杂度平均O(n+k)，最好O(n+k)，最差O(n+k)，空间复杂度O(n+k)，不就地、稳定的排序*/
/*思路为：使用一种数据结构作为计数器存储每个数字的出现次数，然后按照数字的大小和存储的数目依次输出*/
/*算法核心：最大的值不要太大，适用于小范围多数据的排序*/
template<typename T> void countingsort(T data[], const int n)
{
	long i;
	long largest = data[0];
	long *temp = new long[n];       //建存所有数的数组temp
	for (int i = 1; i < n; i++)
		if ((largest < data[i]))
			largest = data[i];      //选出数组中的最大值
	unsigned long *count = new unsigned long[largest + 1];   //建议计数容器
	for (i = 0; i <= largest; i++)  //初始化计数容器
		count[i] = 0;
	for (i = 0; i < n; i++)         //根据data属数组中的数据，出现一次，对应的数值+1
		count[data[i]]++;

	/*以下是正统的计数排序过程*/
	//for (i = 1; i <= largest; i++)  //把计数容器count内的单个容器数值，遍历成依次叠加的
	//	count[i] = count[i - 1] + count[i];
	//for (i = n - 1; i >= 0; i--)    //反向遍历数组data，将其根据计数容器中的位置开始依次放置
	//{
	//	temp[count[data[i]] - 1] = data[i];
	//	count[data[i]]--;           //计数器中对应的元素开始递减，完成循环后与初始计数器（每个元素的数量）保持一致。
	//}
	//for (i = 0; i < n; i++)         //temp中的数据已经排序完成，将其重新赋值给data中
	//	data[i] = temp[i];
	
	/*以下为桶排序的一种特殊形式，即直接将按计数器的顺序将其对应的每个元素直接赋值*/
	int num = 0;
	for (i = 0; i <= largest; i++)
	{
		while (count[i] != 0)
		{
			data[num] = i;
			num++; count[i]--;
		}
	}

}

int main()
{
	int a[] = { 21,1,32,13,56,32,89,54,31,456,324,734,78,123,325,3,7,124 };
	int n = sizeof(a) / sizeof(int);
	cout << "原数组为：       ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	//insertionsort(a, n);
	//selectionsort(a, n);
	//bubblesort(a, n);
	//shellsort(a, n);
	//heapsort(a, n);
	//quicksort(a, 0, n);
	//mergesort(a, 0, n);
	//radixsort(a, n);
	countingsort(a, n);

	cout << "排序后的数组为： ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
