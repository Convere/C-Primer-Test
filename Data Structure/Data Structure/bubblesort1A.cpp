#include "Ch1.h"

static int num = 0;  //计数，统计基本操作的次数（元素的比较和交换都算基本操作）

void bubblesort1A(int A[], int n)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 1; i < n; i++)
		{
			if (A[i - 1] > A[i])
			{
				swap(A[i - 1], A[i]);
				sorted = false;
				num++;
			}
			num++;
		}
		n--;   //每次循环后，末尾的数已经确定
	}
}

int main_bubblesort1A()
{
	int A[] = { 42,12,2,3,1,23,4,12,4,98 };
	for (auto &s : A)
		cout << s << " ";
	cout << endl;
	cout << num << endl;
	auto sz = sizeof(A) / sizeof(*A);  //数组的总大小除以单个元素的大小得到数组的元素数量
	bubblesort1A(A, sz);
	for (auto &s : A)
		cout << s << " ";
	cout << endl;
	cout << num << endl;
	return 0;
}