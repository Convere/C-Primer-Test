//#include <iostream>
//#include <cstring>
//#include <cmath>
//#include <stdlib.h>
//#include <stdio.h>
//using namespace std;
//
///*不用size控型，直接进行计算也可以，但是速度稍微慢了一点*/
///*祖玛的整体思路*/
///*本意是用list来做，但是由于OJ中禁掉了大量STL库，所以最好用数组来进行撰写操作。
//大体结构分为三部分：（1）主函数体：用于将数据读入存储数组中，然后进行strcpy的空间变化将每次插入导入数组中，最后开一个检查数组的循环，直至不需更改数组为止。输出按题意
//					（2）check函数体：检查当前数组是否有需要消除的部分，sum>=3，有就返回1，没有就返回0。每次插入/修改之后都要进行检查，会稍微拖点时间
//					（3）change函数体：用于更改数组，并将删除后的区域补起来。其中注意start不能为负值，需要在判断条件里控型最小为0。之后再判断当前数组的返回条件，一旦有可能的苗头(两种情况），就把数据start传回继续计算*/
//
//char save[20004], temp[20004];
//int point, n;
//
////const int SZ = 1 << 20;  //快速io 提升输入输出速度
////struct fastio
////{
////	char inbuf[SZ];
////	char outbuf[SZ];
////	fastio()
////	{
////		setvbuf(stdin, inbuf, _IOFBF, SZ);
////		setvbuf(stdout, outbuf, _IOFBF, SZ);
////	}
////}io;
//
//int check(char* save, int &step)    //查询是否需要删除相关数据
//{
//	int sum = 0, pos = step;
//	while (pos <= strlen(save) && save[pos++] == save[step]) sum++;  //这里的strlen(save)必须是小于或小于等于均可，因为这个条件一直满足
//	pos = step - 1;  //pos回位
//	while (pos >= 0 && save[pos--] == save[step]) sum++;
//	if (sum >= 3)
//		return 1;
//	return 0;
//}
//
//int change(char* save, int &step)
//{
//	int start = step, end = step;
//	while (save[start] == save[step] && start) start--;  //start自身也加入了了判定条件，当其为0时，不可能减到-1
//	if (start || save[start] != save[step]) start++; //抵消第一次的必定相等，同时当start为0，不进行递增
//	while (save[end] == save[step] && end) end++;
//	strcpy(temp, save + end);  //直接弄掉start到end之间的相等区间，不能贪快两句合并，必须用临时变量缓存过
//	strcpy(save + start, temp);
//	if ((save[start] == save[start + 1]) || (save[start] == save[start - 1]))  //最简的判断步骤，只有两种情况
//	{
//		if (start == 0)   //当start为0时，为了便于之后的check运算，将其step返回1用于计算。不然当其pos=step-1回位时，会导致数值为-1
//			return 1;
//		return start;  //正常情况返回起始位置的输出
//	}
//	else
//		return 0;
//}
//
//int main_ZUMA2()
//{
//	fgets(save, 10002, stdin);   //读入字符串数据，C++中的新语句fgets代替gets  //stdin为标准输入   //也可以防止空串
//	scanf("%d", &n);  //输入重现次数n
//	for (int i = 1; i <= n; i++)
//	{
//		char data; int step;
//		scanf("%d %c", &step, &data);   //输入的插入位置与元素
//		strcpy(temp, save + step);  //所需插入值的地方之后的所有地址拷贝到temp中
//		save[step] = data;			//插入需要插入的数值
//		strcpy(save + step + 1, temp); //把temp中数据地址插入到step之后的地址中，实现step数值的插入过程，每插入一次加一次sz
//		while (check(save, step) == 1) step = change(save, step);   //循环迭代，直至没有能消除的数为止
//		if (strlen(save) == 1)  //根据有效元素的数量进行判定
//			puts("-");
//		else
//			printf("%s", save);
//	}
//	return 0;
//}