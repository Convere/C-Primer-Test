#include "Ch2.h"

template <typename T> void Vector<T>::mergeSort(Rank lo, Rank hi)
{
	cout << "调用归并排序" << endl;
	if ((hi - lo) < 2) return;
	int mi = (lo + hi) / 2;
	mergeSort(lo, mi);   cout << "   调用前部分归并排序" << endl;
	mergeSort(mi, hi);   cout << "   调用后部分归并排序" << endl;//递归分别排序
	merge(lo, mi, hi);  //归并
}

template <typename T> void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
	T* A = _elem + lo;
	int lb = mi - lo; T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);  //向B中赋值A的前半部分
	int lc = hi - mi; T* C = _elem + mi;      //向C中赋值A的后半部分
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] < B[j]))) A[i++] = C[k++];
	}
	cout << "调用二路归并" << endl;
	delete[]B;
}

int main_Mergesort()
{
	initializer_list<int> list{ 13,21,32,4,16,5,8,12 };
	Vector<int> a(list);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	a.mergeSort(0, 8);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}