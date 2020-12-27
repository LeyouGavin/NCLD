/**
*	@file		demo_10_2.c
*	@brief		预留
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_10_2.h"

static int demo10CallCnt = 0;

void demo_10_2(void)
{
	printf(DEMO_10_2);

	static int demo10_2CallCnt = 0;

	demo10CallCnt++;
	demo10_2CallCnt++;

	printf("demo_10_2 callback, demo10_2CallCnt = %d, demo10CallCnt = %d\n", demo10_2CallCnt, demo10CallCnt);
}
