//#include "Ch3.h"
//
//template <typename T> //在有序列表内节点p（可能是trailer）的n个（真）前驱中，找到不大于e的最后者
//ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const 
//{
//	// assert: 0 <= n <= rank(p) < _size
//	/*DSA*/
//	printf("searching for "); print(e); printf(" :\n");
//	while (0 <= n--) //对于p的最近的n个前驱，从右向左逐个比较
//		/*DSA*/ 
//	{
//		printf("  <%4d>", p->pred->data);
//		if (((p = p->pred)->data) <= e) break; //直至命中、数值越界或范围越界
//											   /*DSA*/
//	} printf("\n");
//	// assert: 至此位置p必符合输出语义约定——尽管此前最后一次关键码比较可能没有意义（等效于与-inf比较）
//	return p; //返回查找终止的位置
//} //失败时，返回区间左边界的前驱（可能是header）——调用者可通过valid()判断成功与否
//
//template <typename T> //列表的选择排序算法：对起始于位置p的n个元素排序
//void List<T>::selectionSort(ListNodePosi(T) p, int n) 
//{ //valid(p) && rank(p) + n <= size
//	/*DSA*/printf("SelectionSort ...\n");
//	ListNodePosi(T) head = p->pred; ListNodePosi(T) tail = p;
//	for (int i = 0; i < n; i++) tail = tail->succ; //待排序区间为(head, tail)
//	while (1 < n) 
//	{ //在至少还剩两个节点之前，在待排序区间内
//		ListNodePosi(T) max = selectMax(head->succ, n); //找出最大者（歧义时后者优先）
//		insertB(tail, remove(max)); //将其移至无序区间末尾（作为有序区间新的首元素）
//									/*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
//		tail = tail->pred; n--;
//	}
//}
//
//template <typename T> //列表的插入排序算法：对起始于位置p的n个元素排序
//void List<T>::insertionSort(ListNodePosi(T) p, int n) 
//{ //valid(p) && rank(p) + n <= size
//	/*DSA*/printf("InsertionSort ...\n");
//	for (int r = 0; r < n; r++) 
//	{ //逐一为各节点
//		insertA(search(p->data, r, p), p->data); //查找适当的位置并插入
//		p = p->succ; remove(p->pred); //转向下一节点
//	}
//}
//
//template <typename T> //列表的归并排序算法：对起始于位置p的n个元素排序
//void List<T>::mergeSort(ListNodePosi(T) & p, int n) 
//{ //valid(p) && rank(p) + n <= size
//	/*DSA*/printf("\tMERGEsort [%3d]\n", n);
//	if (n < 2) return; //若待排序范围已足够小，则直接返回；否则...
//	int m = n >> 1; //以中点为界
//	ListNodePosi(T) q = p; for (int i = 0; i < m; i++) q = q->succ; //均分列表
//	mergeSort(p, m); mergeSort(q, n - m); //对前、后子列表分别排序
//	merge(p, m, *this, q, n - m); //归并
//} //注意：排序后，p依然指向归并后区间的（新）起点