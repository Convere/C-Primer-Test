//#include <iostream>
//#include <cstring>
//#include <cmath>
//#include <stdlib.h>
//#include <stdio.h>
//using namespace std;
//
//char save[20004], temp[20004];
//int point, n;
//int sz = 0;  //sz控型，只记录常规输入的A到Z元素，别的不考虑
//
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
//
//int check(char* save,int &step)    //查询是否需要删除相关数据
//{
//	int sum = 0, pos = step;
//	while (pos <= strlen(save) && save[pos++] == save[step]) sum++;  //这里的strlen(save)必须是小于或小于等于均可，因为这个条件一直满足
//	pos = step - 1;  //pos回位
//	while (pos >= 0 && save[pos--] == save[step]) sum++;
//	//cout << "sz:" << sz << " ";
//	if (sum >= 3)
//		return 1;
//	return 0;
//}
//
//int change(char* save,int &step)
//{
//	int start = step, end = step;
//	while (save[start] == save[step] && start) start--;  //start自身也加入了了判定条件，当其为0时，不可能减到-1
//	if (start || save[start] != save[step]) start++; //抵消第一次的必定相等，同时当start为0，不进行递增
//	while (save[end] == save[step] && end) end++;
//	strcpy(temp, save + end);  //直接弄掉start到end之间的相等区间，不能贪快两句合并，必须用临时变量缓存过
//	strcpy(save + start, temp);
//	sz = sz + start - end;
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
//int main_ZUMA_End()
//{
//	fgets(save, 10002, stdin);   //读入字符串数据，C++中的新语句fgets代替gets  //stdin为标准输入   //也可以防止空串
//	while (save[sz] >= 'A' && save[sz] <= 'Z') sz++;
//	scanf("%d", &n);  //输入重现次数n
//	for (int i = 1; i <= n; i++)
//	{
//		char data; int step;
//		scanf("%d %c", &step, &data);   //输入的插入位置与元素
//		strcpy(temp, save + step);  //所需插入值的地方之后的所有地址拷贝到temp中
//		save[step] = data;			//插入需要插入的数值
//		strcpy(save + step + 1, temp); sz++;  //把temp中数据地址插入到step之后的地址中，实现step数值的插入过程，每插入一次加一次sz
//		while (check(save, step) == 1) step = change(save,step);   //循环迭代，直至没有能消除的数为止
//		if (!sz)  //根据有效元素的数量进行判定
//			puts("-");
//		else
//			printf("%s", save);
//	}
//	return 0;
//}