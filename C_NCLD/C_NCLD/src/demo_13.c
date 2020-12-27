/**
*	@file		demo_13.c
*	@brief		字节数与字节位数
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_13.h"

void demo_13(void)
{
	printf(DEMO_13);

#pragma warning(disable:4305)	/* 屏蔽 4305 警告 */
	char cVar = 0x0100;
#pragma warning(default:4305)   /* 使能 4305 警告 */
	int iVar = 0;
	printf("cVar = %d\n", cVar);
	printf("sizeof(int) = %d\n", sizeof(iVar));
}
