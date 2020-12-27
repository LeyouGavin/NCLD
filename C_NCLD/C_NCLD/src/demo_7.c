/**
*	@file		demo_7.c
*	@brief		排序算法
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include <string.h>
#include "demo_7.h"

void printSortResult(int *a, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void demo_7(void)
{
	printf(DEMO_7);

	int length;
	int src[12] = { 5, 1, 4, 8, -1, 0, 9, 1, -2, 3, 7, 2 };
	int a[12];
	int a2[12];
	length = sizeof(src) / sizeof(src[0]);

	memcpy(a, src, sizeof(src));
	insertSort(a, length);
	printSortResult(a, length);
	//
	memcpy(a, src, sizeof(src));
	shellSort(a, length);
	printSortResult(a, length);
	//
	memcpy(a, src, sizeof(src));
	selectSort(a, length);
	printSortResult(a, length);
	//
	memcpy(a, src, sizeof(src));
	HeapSort(a, length);
	printSortResult(a, length);
	//
	memcpy(a, src, sizeof(src));
	bubbleSort(a, length);
	printSortResult(a, length);
	//
	memcpy(a, src, sizeof(src));
	quickSort(a, 0, length - 1);
	printSortResult(a, length);
	//
	memcpy(a, src, sizeof(src));
	mergeSort(a, a2, 0, length - 1);
	printSortResult(a, length);
}

static inline void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void insertSort(int *a, int length)
{
	int i, j;
	
	for (i = 1; i < length; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			if (a[i - j] < a[i - j - 1])
			{
				swap(&a[i - j], &a[i - j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}

//
void shellInsertSort(int *a, int length, int gap)
{
	int i, j;

	for (i = gap; i < length; ++i)
	{
		for (j = 0; j < i - gap + 1; j += gap)
		{
			if (a[i - j] < a[i - j - gap])
			{
				swap(&a[i - j], &a[i - j - gap]);
			}
			else
			{
				break;
			}
		}
	}
}

void shellSort(int *a, int length)
{
	int gap;

	for (gap = length >> 1; gap > 0; gap >>= 1)
	{
		shellInsertSort(a, length, gap);
	}
}

void selectSort(int *a, int length)
{
	int i, j;
	int minIndex;

	for (i = 0; i < length - 1; ++i)
	{
		minIndex = i;
		for (j = i + 1; j < length; ++j)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(&a[minIndex], &a[i]);
		}
	}
}

//
void HeapAdjust(int *H, int s, int length)
{
	int tmp = H[s];
	int child = 2 * s + 1; //左孩子结点的位置。(i+1 为当前调整结点的右孩子结点的位置)
	while (child < length) {
		if (child + 1 <length && H[child]<H[child + 1]) { // 如果右孩子大于左孩子(找到比当前待调整结点大的孩子结点)
			++child;
		}
		if (H[s]<H[child]) {  // 如果较大的子结点大于父结点
			H[s] = H[child]; // 那么把较大的子结点往上移动，替换它的父结点
			s = child;     // 重新设置s ,即待调整的下一个结点的位置
			child = 2 * s + 1;
		}
		else {       // 如果当前待调整结点大于它的左右孩子，则不需要调整，直接退出
			break;
		}
		H[s] = tmp;      // 当前待调整的结点放到比其大的孩子结点位置上
	}
}

void BuildingHeap(int H[], int length)
{
	//最后一个有孩子的节点的位置 i=  (length -1) / 2
	for (int i = (length - 1) / 2; i >= 0; --i)
		HeapAdjust(H, i, length);
}

void HeapSort(int H[], int length)
{
	//初始堆
	BuildingHeap(H, length);
	//从最后一个元素开始对序列进行调整
	for (int i = length - 1; i > 0; --i)
	{
		//交换堆顶元素H[0]和堆中最后一个元素
		int temp = H[i]; H[i] = H[0]; H[0] = temp;
		//每次交换堆顶元素和堆中最后一个元素之后，都要对堆进行调整
		HeapAdjust(H, 0, i);
	}
}

void bubbleSort(int *a, int length)
{
	int i, j;

	for (i = 0; i< length - 1; ++i)
	{
		for (j = 0; j < length - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

//
int partition(int *a, int low, int high)
{
	int privotKey;
	
	privotKey = a[low];
	while (low < high)
	{ 
		while(low < high  && a[high] >= privotKey)
		{
			--high;
		}
		swap(&a[low], &a[high]);
		while (low < high  && a[low] <= privotKey)
		{
			++low;
		}
		swap(&a[low], &a[high]);
	}

	return low;
}

void quickSort(int *a, int low, int high)
{
	int privotLoc;

	if (low < high)
	{
		privotLoc = partition(a, low, high);
		quickSort(a, low, privotLoc - 1);
		quickSort(a, privotLoc + 1, high);
	}
}

//
void merge(int *r, int *rf, int low, int high)
{
	int i, j;
	int mid;
	int index;

	mid = low + ((high - low) >> 1);
	i = low;
	j = mid + 1;
	index = low;
	while (i <= mid && j <= high)
	{
		if (r[i] <= r[j])
		{
			rf[index++] = r[i++];
		}
		else
		{
			rf[index++] = r[j++];
		}
	}
	while (i <= mid)
	{
		rf[index++] = r[i++];
	}
	while (j <= high)
	{
		rf[index++] = r[j++];
	}
	memcpy(r + low, rf + low, sizeof(int)*(high - low + 1));
}

void mergeSort(int *r, int *rf, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = low + ((high - low) >> 1);
		mergeSort(r, rf, low, mid);
		mergeSort(r, rf, mid + 1, high);
		merge(r, rf, low, high);
	}
}

//
void radixSort(int *a, int length)
{

}