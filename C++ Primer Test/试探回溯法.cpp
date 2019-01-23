#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

struct queen
{
	int x, y;
	queen(int xx = 0, int yy = 0) :x(xx), y(yy) {}
	bool operator==(queen const &q) const
	{
		return (x == q.x) || (y == q.y) || (x + y == q.x + q.y) || (x - y == q.x - q.y);
	}
	bool operator!=(queen const &q) const { return !(*this == q); }
};

int checkout(stack<queen> &solu, queen &q)
{
	int num = 0;
	stack<queen> temp(solu);
	while (temp.size())
	{
		auto tm = temp.top(); temp.pop();
		if (q == tm)
			num++;
	}
	return num;
}

tuple<int,int> placequeens(int n)
{
	int ncheck = 0 , nsolution = 0;
	queen q(0, 0);  //初始位置为0,0的零点
	stack<queen> solu;
	do
	{
		if (n <= solu.size() || n <= q.y) //越界，即当前行没有找到对应的点，故回溯上一行重新找点
		{
			auto tm = solu.top(); solu.pop();
			q = tm;
			q.y++;  //为防止继续重复上一行的选点，直接在处理回溯时将其列数加1
		}
		else
		{
			while ((q.y < n) && (checkout(solu, q)))  //将当前queen和栈内的数据比较，是否有干涉的情况产生
			{
				q.y++;   //出现干涉即右移一列计算比对
				ncheck++;
			}
			if (n > q.y)  //到了这一步，即代表此时的位置是符合要求的，只需要判断此时是否越界即可
			{
				solu.push(q);  //未越界则节点入栈
				if (n <= solu.size()) nsolution++;  //若栈的元素数目达到了解的数目，则solution++表示全局解已经找到
				q.x++; q.y = 0;  //进入下一行并重置列数，进行进一步搜索
			}
		}
	} while ((0 < q.x) || (q.y < n));  //所有分支均以或穷举或剪枝后  //所有的用例测试到最后，肯定就到达了q.x=0，q.y=n的地方，故跳出
	tuple<int, int> tmm({ ncheck,nsolution });
	return tmm;
}

int main_shitanhuisufa()
{
	int n;
	while (cin >> n)
	{
		auto temp = placequeens(n);
		cout << get<1>(temp) << " solution(s) found after "<< get<0>(temp) << " check(s) for "<< n << " queen(s)\n"; //输出解的总数
	}
	return 0;
}