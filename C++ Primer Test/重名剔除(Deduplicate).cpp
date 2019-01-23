#include<cstdio>
#include<cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#define HASHSIZE 600001
using namespace std;

const int SZ = 1 << 20;  //快速io 提升输入输出速度
static struct fastio
{
	char inbuf[SZ];
	char outbuf[SZ];
	fastio()
	{
		setvbuf(stdin, inbuf, _IOFBF, SZ);
		setvbuf(stdout, outbuf, _IOFBF, SZ);
	}
}io;

int main_cplusplus()   //自己写的效率确实差很多，数据一多就凉了
{
	int n; vector<string> save; 
	cin >> n;
	while (n--)
	{
		string input;
		cin >> input;
		save.push_back(input);
	}
	vector<string> same(save);
	stable_sort(same.begin(), same.end());
	auto iter = unique(same.begin(), same.end());
	same.erase(iter, same.end());
	vector<string> output(600000, "");
	for (int i = 0; i < same.size(); i++)
	{
		int flag = 0;
		for (int j = 0; j < save.size(); j++)
		{
			if (same[i] == save[j])
				flag++;
			if (flag == 2)
			{
				output[j] = same[i];
				break;
			}
		}
	}
	for (auto &s : output)
		if (s != "")
			cout << s << endl;
	return 0;
}

struct Slot 
{//每个桶对应的槽位，存储冲突，即映射到同一地址且不重复的字符串（实则字符指针） 
	char* data;//数据项，存储字符指针 
	bool repeat;//标志，判别字符串是否重复
	Slot* succ;//后继 
}buckets[HASHSIZE];//桶数组（散列表） 

char name[HASHSIZE][41];//字符二维数组（必须开头定义），存储输入字符串，注意二维长度为40+1个结束符=41 

void Insert(int addr, char* s)  //这里的插入都是前插入，即每次新元素都插入到表头。但为了保证稳定性，最好是后插
{//在相应地址中插入冲突的字符串（实则字符指针） 
	Slot* t = new Slot;
	t->data = s; t->repeat = false;//初始化当前字符串从未重复 
	t->succ = buckets[addr].succ;//链表头插法 
	buckets[addr].succ = t;
}
int HashCode(char* s) 
{//散列码转换（字符串转数字） 
	int sum = 0, len = strlen(s);
	for (int i = 0; i<len; i++)//多项式求和 
		sum += (i + 1)*(s[i] - 'a' + 1);
	return sum;
}

int main_csanliebiao() 
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%s", name[i]);
		int addr = HashCode(name[i]) % HASHSIZE;//获得映射到的地址 
		Slot* p = buckets[addr].succ;//从当前桶的第1个槽位开始 ,存储的地方都是当前的buckets[]的succ后继，这就相当于一个链表结构，在对应的每个桶单元都是一个链表，然后相同的就这里串起来
		while (p)//遍历所有槽位上链表的所有单元（冲突的单元） 
		{
			if (!strcmp(p->data, name[i]))
			{//若当前槽位的字符串重复 
				if (!p->repeat)
				{//检查当前槽位的字符串是否重复
					p->repeat = true;//若未重复，则标志为已重复过 
					puts(name[i]);//输出重复字符串
					//也就是说，在这里并没有将冲突的字符串插入散列表中，而是通过在第二次插入检查重复时，修改当前槽位的状态并输出依次实现过程。
				}break;//若重复过，则忽略，无论是否重复过，皆终止遍历 
			}
			else p = p->succ;  //通过此句完成遍历
		}
		if (!p)Insert(addr, name[i]);//若当前槽位空，则进行插入 
	}
	return 0;
}

/*c++形式的散列表*/
map<int, list<string>> save;   //map的int为桶单元的标号，后面的list为每个桶中的链表

int hashcode(string &s)
{//散列码转换（字符串转数字） 
	int sum = 0, len = s.size();
	for (int i = 0; i < len; i++)//多项式求和 
		sum += (i + 1)*(s[i] - 'a' + 1);
	return sum;
}

int main_cplussanliebiao()
{
	vector<string> same;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		int flag = 0;
		for (auto &s : save[hashcode(input)])
		{
			if (s == input)
			{
				flag++;
				same.push_back(s);
				break;
			}
		}
		if (flag == 0)
			save[hashcode(input)].push_back(input);
	}
	for (auto &s : same)
		cout << s << endl;
	return 0;
}


/*
20
brioche
camembert
cappelletti
savarin
cheddar
cappelletti
tortellni
croissant
brioche
lpc
mapotoufu
yzt
lpc
wzz
zw
brioche
qy
qy
zw
tortellni
*/