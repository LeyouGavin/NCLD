/**
*	@file		demo_1.c
*	@brief		不同数据类型的内存占用（Bytes）
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_1.h"


void demo_1(void)
{
	printf(DEMO_1);
	printf("sizeof(char) = %d\n", sizeof(char));
	printf("sizeof(short) = %d\n", sizeof(short));
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(long) = %d\n", sizeof(long));
	printf("sizeof(float) = %d\n", sizeof(float));
	printf("sizeof(double) = %d\n", sizeof(double));
	printf("sizeof(long long) = %d\n", sizeof(long long));
}
