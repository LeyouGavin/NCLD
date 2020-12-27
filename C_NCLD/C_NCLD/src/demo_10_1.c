/**
*	@file		demo_10_1.c
*	@brief		预留
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_10_1.h"

static int demo10CallCnt = 0;

void demo_10_1(void)
{
	printf(DEMO_10_1);

	static int demo10_1CallCnt = 0;

	demo10CallCnt++;
	demo10_1CallCnt++;

	printf("demo_10_1 callback, demo10_1CallCnt = %d, demo10CallCnt = %d\n", demo10_1CallCnt, demo10CallCnt);
}
