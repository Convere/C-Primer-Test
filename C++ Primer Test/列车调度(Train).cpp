#include <iostream>
#include <cstdio>
using namespace std;

//const int SZ = 1 << 20;  //快速io 提升输入输出速度
//struct fastio
//{
//	char inbuf[SZ];
//	char outbuf[SZ];
//	fastio()
//	{
//		setvbuf(stdin, inbuf, _IOFBF, SZ);
//		setvbuf(stdout, outbuf, _IOFBF, SZ);
//	}
//}io;

int nn, mm = 0; int train_A[1600000], train_B[3200000], train_S[1600000];

int main_Train()
{
	int ini = 0;
	scanf("%d%d", &nn, &mm);
	for (int i = 0; i < nn; i++)
		scanf("%d", &train_A[i]);
	int flag = 1;  // 1-可行；0-不可行

	int xb_B = 0;  // 输出数组B的下标
	int xb_S = 0;  // 缓存栈S的下标

	for (int i = 1, j = 0; i <= nn && j < nn; i++)  //算法主要思路为从1到n输入到栈中，在输入过程中不断比较原数组数据，一旦有相同即出栈。最终检查flag记号和栈中元素，即可判断no或者操作步骤
	{
		if (xb_S < mm) 
		{
			train_B[xb_B++] = 1;   //这里的赋值1，相当于给S中插值做标志。B中赋值为1，相当于push
			train_S[xb_S++] = i;
		}
		else 
		{
			flag = 0;   //当栈中达到最大缓存时还没排完，即默认失败，直接跳出循环
			break;
		}
		if (i == train_A[j])   //当前计数与A中的j号元素相等时，S中返回上一位重新赋值为0（相当于弹出了首位，即pop）。输出B中的下一位赋值为0，代表pop
		{
			j++;
			train_S[--xb_S] = 0;   //xb_S控型，一旦有相同即回溯，等同于pop操作
			train_B[xb_B++] = 0;
			while (xb_S > 0 && train_S[xb_S - 1] == train_A[j])   //依次比较栈中元素与A中存储的元素，看能否对应完全
			{
				j++;
				train_S[--xb_S] = 0;
				train_B[xb_B++] = 0;
			}
		}
	}

	if (flag == 0 || xb_S != 0) printf("No\n");
	else
	{
		for (xb_B = 0; xb_B < 2 * nn; xb_B++)
		{
			if (train_B[xb_B] == 0) printf("pop\n");
			else if (train_B[xb_B] == 1) printf("push\n");
		}
	}
	return 0;
}