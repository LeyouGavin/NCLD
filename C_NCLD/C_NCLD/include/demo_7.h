/**
*	@file		demo_7.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# 排序算法
*	-# 参考 https://www.cnblogs.com/onepixel/articles/7674659.html
**************************************************/
#pragma once

#define DEMO_7	"\n排序算法\n\n"


/**
*	@brief		测试用例入口函数
*	@details	排序算法调用测试
*	
*	排序算法分类
*		内部排序（数据量小，排序过程不需要访问外存）
*			比较类排序（时间复杂度不能突破O(nlogn)，又称非线性时间比较类排序）
*				交换排序：冒泡排序，快速排序
*				插入排序：直接插入排序，希尔排序
*				选择排序：简单选择排序，堆排序
*				归并排序
*			非比较类排序（时间复杂度可以突破比较类排序时间下界，以线性时间运行，又称线性时间比较类排序）
*				计数排序
*				桶排序
*				基数排序
*
*			稳定排序（a在b前面，a=b，排序后a仍在b前面）
*				冒泡排序，直接插入排序，归并排序，基数排序
*			不稳定排序（a在b前面，a=b，排序后a可能在b后面）
*				快速排序，简单选择排序，希尔排序，堆排序
*		外部排序（数据量大，排序过程需要访问外存）
*
*
*
**************************************************/
void demo_7(void);

/**
*	@brief		插入排序（此代码未完全按插入排序定义实现）
*	@details
*		1.首先认为第一个元素已完成排序。
*		2.从未排序队列中的首个元素向前扫描，找到其在已排序队列中的位置。
*		3.将未排序队列中的首个元素插入到相应位置。
*		4.对剩余未排序元素重复步骤2~3，直到排序完成。
*	@param[in]	a	待排序队列数据首地址
*	@param[in]	length	待排序数据长度
**************************************************/
void insertSort(int *a, int length);

/**
*	@brief		广义的插入排序
*	@details
*		1.与插入排序相比，此函数按给定间隔实现分组插入排序。
*	@param[in]	a	待排序队列数据首地址
*	@param[in]	length	待排序数据长度
*	@param[in]	gap	分组间隔
**************************************************/
void shellInsertSort(int *a, int length, int gap);
/**
*	@brief		希尔排序（插入排序的改进版）
*	@details
*		1.将队列元素等间隔分成多组同时进行插入排序。
*		2.减小间隔，重新进行分组排序。
*		2.重复步骤1~2，直到排序完成。
*	@param[in]	a	待排序队列数据首地址
*	@param[in]	length	待排序数据长度
**************************************************/
void shellSort(int *a, int length);

/**
*	@brief		选择排序
*	@details
*		1.遍历队列获取队列中的最小值，如果最小值大于队列未排序部分的首个元素，则交换二者位置。
*		2.一次排序过后，可保证队列未排序部分的首个元素完成排序。
*		3.对剩余未排序元素重复步骤1~2，直到排序完成。
*	@param[in]	a	待排序队列数据首地址
*	@param[in]	length	待排序数据长度
**************************************************/
void selectSort(int *a, int length);

//
void HeapAdjust(int *H, int s, int length);
void BuildingHeap(int H[], int length);
void HeapSort(int H[], int length);

/**
*	@brief		冒泡排序
*	@details
*		1.从队首开始，逐一比较相邻的两个元素，如果第一个元素大于第二个元素，则交换二者位置。
*		2.一次排序过后，可保证最后一个元素为队列中最大元素，即最后一个元素完成排序。
*		3.对剩下的前n-1个元素重复步骤1~2，直到排序完成。
*	@param[in]	a	待排序队列数据首地址
*	@param[in]	length	待排序数据长度
**************************************************/
void bubbleSort(int *a, int length);
//
int partition(int *a, int low, int high);
void quickSort(int *a, int low, int high);
//
void merge(int *r, int *rf, int low, int high);
void mergeSort(int *r, int *rf, int low, int high);
//
void radixSort(int *a, int length);