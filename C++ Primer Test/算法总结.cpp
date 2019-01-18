#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <forward_list>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

/*二分查找与简单查找*/
template<typename T> static int binarysearch(T *a, T const &f, int lo, int hi)  //a为容器，f为查找的数，lo和hi为下上限
{
	while (lo < hi)
	{
		int mi = (lo + hi) / 2;
		(f < a[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;  //返回等同于f的最大秩，即使失败了，返回的也是失败的位置（即小于f的最大值的最大秩）
}

template<typename T> static int normalsearch(T *a, T const &f, int lo, int hi)
{
	while (lo < hi)
	{
		if (a[hi] == f)
			break;
		hi--;
	}
	if (lo == hi)
		return -1;
	else
		return hi;
}

template<typename T> static int sum(T *a, int n)
{
	/*列表最大数值*/  //迭代法的直接统计，时间复杂度为O(n)，如果用二分法会降低至O(log n)
	T num2 = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > num2)
			num2 = a[i];
	return num2;

	/*递归计算元素个数*/
	if (n == 0)
		return 0;
	else
		return 1 + sum(a, --n);

	/*递归*/
	if (n == 0)
		return 0;
	else
		return a[--n] + sum(a, n);

	/*迭代*/
	T s = 0;
	for (int i = 0; i < n; i++)
		s += a[i];
	return s;
}

/*广度优先搜索算法*/  //查找一堆人以及相关朋友中有没有卖芒果的（名字最后的字符为m）
bool person_is_seller(string &a)  //表示查找条件的函数，可随时更改
{
	if (a.back() == 'm')
		return true;
	return false;
}

static bool breadth_first_search(map<string, vector<string>> &people)
{
	deque<string> search_deque;
	search_deque.push_back("you");
	vector<string> fn_people;
	while (search_deque.size())
	{
		string person = search_deque.front();
		search_deque.pop_front();
		bool flag = true;
		for (auto &s : fn_people)
			if (s == person)
				flag = false;
		if (flag)
		{
			if (person_is_seller(person))
			{
				cout << "find the seller " << person << endl;
				return true;
			}
			else
			{
				for (auto &s : people[person])
					search_deque.push_back(s);
				fn_people.push_back(person);
			}
		}
	}
	cout << "not find the seller" << endl;
	return false;
}

static int inf = numeric_limits<int>::max();
static vector<string> processed;  //存储处理过的节点
/*狄克斯特拉算法*/
static string find_lowest_cost_node(map<string, int> &costs)
{
	string lower_cost_node;
	int lower_cost = inf;
	for (auto &s : costs)
	{
		bool flag = true;
		for (auto &r : processed)
			if (r == s.first)
				flag = false;
		if (flag)
		{
			if (s.second < lower_cost)
			{
				lower_cost = s.second;
				lower_cost_node = s.first;
			}
		}
	}
	return lower_cost_node;
}

static void dijkstra(map<string, vector<pair<string, int>>> &save, map<string, int> &costs, map<string, string> &parents)
{
	string node = find_lowest_cost_node(costs);
	while (node.size())
	{
		int cost = costs[node];
		auto neighbors = save[node];
		for (auto &s : neighbors)
		{
			auto new_cost = cost + s.second;
			if (costs[s.first] > new_cost)
			{
				costs[s.first] = new_cost;
				parents[s.first] = node;
			}
		}
		processed.push_back(node);
		node = find_lowest_cost_node(costs);
	}
}

/*贪婪算法*/
static void bestst(map<string, set<string>> &stations, set<string> &states_need,set<string> &final_station)
{  //输入数据：所需覆盖的区域，各个广播台名字及其对应区域，最佳广播台选择存储set
	set<string> states_needed(states_need);  //使用新建的set拷贝原数据，对临时数据进行更改保证不修改原数据
	while (states_needed.size())   //每一步循环选择当前need区域，能覆盖最多范围的广播台，直至need为空
	{
		string best_station;
		set<string> states_covered;
		for (auto &s : stations)   //遍历所有的广播台，在当前的need范围内选取能覆盖最多的区域的广播台（相同就跳过）
		{
			set<string> covered;
			vector<string> temp1(20);
			auto end1 = set_intersection(s.second.begin(), s.second.end(), states_needed.begin(), states_needed.end(), temp1.begin());
			temp1.resize(end1 - temp1.begin());  //求出每个广播台覆盖区域与所需覆盖区域的交集，存储字vector中
			for (auto &s2 : temp1)
				covered.insert(s2); //将储存的数据转入covered中
			if (covered.size() > states_covered.size())  //相同就跳过
			{
				best_station = s.first;
				states_covered = covered;
			}
		}
		vector<string> temp2(20);
		auto end2 = set_difference(states_needed.begin(), states_needed.end(), states_covered.begin(), states_covered.end(), temp2.begin());
		temp2.resize(end2 - temp2.begin());  //此时一个广播台已经被选定，将已经被选取广播台的对应区域从need中抹除
		set<string> new_states_needed;
		for (auto &s2 : temp2)
			new_states_needed.insert(s2);
		states_needed = new_states_needed;   //重新赋值need，此时其中已经没有了被抹除的区域
		final_station.insert(best_station);  //将所选的广播台存入最佳选择
	}
}

int main_suanfazongjie()
{
	//int a[] = { 1,32,13,56,32,734,78,123,325,124 };
	//int n = sizeof(a) / sizeof(int);
	//auto temp1 = binarysearch(a, 13, 0, 10);
	//auto temp2 = normalsearch(a, 13, 0, 10);
	//cout << temp1 << temp2 << endl;
	//int s = sum(a, n);
	//cout << s << " " << n << endl;

	/*广度优先搜索*/
	//map<string, vector<string>> people;
	//set<string> fn_people;
	//vector<string> you({ "alice", "bob", "claire" });
	//vector<string> bob({ "anuj", "peegy" });
	//vector<string> alice({ "peggy" });
	//vector<string> claire({ "thom","jonny" });
	//vector<string> empty;
	//people.insert({ "you",you });
	//people.insert({ "bob",bob });
	//people.insert({ "alice",alice });
	//people.insert({ "claire",claire });
	//people.insert({ "anuj",empty });;
	//people.insert({ "peggy",empty });
	//people.insert({ "thom",empty });
	//people.insert({ "jonny",empty });

	//breadth_first_search(people);

	/*狄克斯特拉算法*/
	//map<string, vector<pair<string, int>>> save;  //存储邻居以及前往邻居的开销
	//vector<pair<string, int>> start;
	//start.push_back({ "a",6 });
	//start.push_back({ "b",2 });
	//save.insert({ "start",start });
	//vector<pair<string, int>> a;
	//a.push_back({ "fin",1 });
	//save.insert({ "a", a });
	//vector<pair<string, int>> b;
	//b.push_back({ "a",3 });
	//b.push_back({ "fin",5 });
	//save.insert({ "b",b });
	//vector<pair<string, int>> fin;
	//save.insert({ "fin",fin });

	//map<string, int> costs;   //存储开销
	//costs.insert({ "a",6 });
	//costs.insert({ "b",2 });
	//costs.insert({ "fin",inf });

	//map<string, string> parents;   //存储父节点，后为前的父节点
	//parents.insert({ "a","start" });
	//parents.insert({ "b","start" });
	//parents.insert({ "fin","" });

	//for (auto &s1 : save)
	//	for (auto &s2 : s1.second)
	//		cout << s1.first << " to " << s2.first << ":" << s2.second << endl;
	//for (auto &s : costs)
	//	cout << "start to "<<s.first << " cost " << s.second << endl;
	//for (auto &s : parents)
	//	cout << s.first << "'s parents is " << s.second << endl;
	//cout << endl;
	//dijkstra(save, costs, parents);

	//for (auto &s1 : save)
	//	for (auto &s2 : s1.second)
	//		cout << s1.first << " to " << s2.first << ":" << s2.second << endl;
	//for (auto &s : costs)
	//	cout << "start to " << s.first << " cost " << s.second << endl;
	//for (auto &s : parents)
	//	cout << s.first << "'s parents is " << s.second << endl;

	/*贪婪算法*/
	set<string> states_needed({ "mt","wa","or","id","nv","ut","ca","az" });//所需数据存储，存储所有需要被广播台覆盖的州
	map<string, set<string>> stations;      //各个广播台名字及其范围存储，前string代表广播台的名字，后set<string>代表所覆盖的州
	set<string> kone({ "id","nv","ut" });
	stations.insert({ "kone", kone });
	set<string> ktwo({ "wa","id","mt" });
	stations.insert({ "ktwo", ktwo });
	set<string> kthree({ "or","nv","ca" });
	stations.insert({ "kthree", kthree });
	set<string> kfour({ "nv","ut" });
	stations.insert({ "kfour", kfour });
	set<string> kfive({ "ca","az" });
	stations.insert({ "kfive", kfive });
	set<string> final_station;  //用于储存最佳的广播台选择

	bestst(stations, states_needed, final_station);
	for (auto &s : final_station)
		cout << "最佳广播台选择为：" << s << " " << endl;

	return 0;
}